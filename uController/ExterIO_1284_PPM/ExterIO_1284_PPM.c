#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define BUF_LEN	20
volatile char byteArr[BUF_LEN], byteSendArr[8],  rxFlag = 0, txFlag = 0, nextByte = 0, byteSendTrigger = 0;  
volatile unsigned int head = 0, tail = 0, byteCntr = 8;
volatile char freeState = 0;
unsigned int adcVal, ledCntr = 0;

#define DIG_BEGIN			128
#define DIG_END				128+32
#define ADC_BEGIN 			128 + 64
#define ADC_END 			128 + 64 + 32
#define MSG_AMT_REQ_BEG		64
#define MSG_AMT_REQ_END		64 + 32


#define EXT_INIT		2
#define EXT_DIG_REQ		0
#define EXT_ADC_REQ		1
#define EXT_IDLE		3
#define EXT_DIG_PASS	4
#define EXT_DIG_FILL	5
#define EXT_AMT_FILL	6
#define EXT_AMT_PASS	7
#define EXT_ADC_PASS	8
#define EXT_ADC_FILL	9
volatile uint16_t amtOfExtAdc = 0, amtOfExtDigs = 0, extMode = EXT_IDLE, extModeOld = EXT_IDLE, modeCntr = 0;
volatile char TOKEN_FLAG = 0;

const char CTS_FREE = 0;
const char CTS_BUSY = 1;

#define CTS  0b00001000
#define RTS 0b00010000

char tmp, switchBits;

#ifdef __AVR_ATmega1284P__
#define UBRRH_COM	UBRR0H
#define UBRRL_COM	UBRR0L
#define UCSRA_COM	UCSR0A
#define UCSRB_COM	UCSR0B
#define UCSRC_COM	UCSR0C
#define UDR_COM		UDR0

#define USART_RX_vect_COM	USART0_RX_vect
#define USART_UDRE_vect_COM	USART0_UDRE_vect
#endif

#ifdef __AVR_ATmega8__
#define UBRRH_COM	UBRRH
#define UBRRL_COM	UBRRL
#define UCSRA_COM	UCSRA
#define UCSRB_COM	UCSRB
#define UCSRC_COM	UCSRC
#define UDR_COM		UDR

#define USART_RX_vect_COM	USART_RXC_vect
#define USART_UDRE_vect_COM	USART_UDRE_vect
#endif

unsigned int ppmInputChnls[8], ticksEnd, ticksStart, pulseLength, pulseCntr;
unsigned int curChnlBlk = 0;

/*
1284p :
	TX0 : PD1
	RX0 : PD0
INT0: PD0
	RTS:  PD4 // Request to send -> output (collector)
	CTS:  PD3 // Clear to send 	-> input

8:
	TX0 : PD1
	RX0 : PD0
INT0: PD2
	RTS:  PD4 // Request to send -> output (collector)
	CTS:  PD3 // Clear to send 	-> input
*/

char IsCtsFtee()
{ 
	if((PIND & CTS) == CTS) 
	{
		return CTS_FREE;
	}
	else 
	{
		return CTS_BUSY;
	}
}

unsigned int DiffHeadTail(unsigned int headC, unsigned int tailC)
{
	if(headC > tailC) return (headC - tailC);
	else if(headC < tailC)return (tailC - headC);
	else return 0;
}


unsigned char GetSwitchPins()
{
#ifdef __AVR_ATmega1284P__
return (unsigned char)(PINC ^ 0b11111111);
#endif

#ifdef __AVR_ATmega8__
tmpC |= (((PINB ^ 0b11111111) & 0b00111100)<<0);
tmpC |= (((PIND ^ 0b11111111) & 0b01100000)>>5);
return tmpC;
#endif
}

void Enable_UDREIE()
{
#ifdef __AVR_ATmega1284P__
UCSRB_COM |= (1<<UDRIE0);
#endif

#ifdef __AVR_ATmega8__
UCSRB_COM |= (1<<UDRIE);
#endif
}

void Disable_UDREIE()
{
#ifdef __AVR_ATmega1284P__
UCSRB_COM &= ~(1<<UDRIE0);
#endif

#ifdef __AVR_ATmega8__
UCSRB_COM &= ~(1<<UDRIE);
#endif
}

void Enable_ExtInt()
{
#ifdef __AVR_ATmega1284P__
EIFR |= 0b00000001;
EIMSK |= 0b00000001;
#endif

#ifdef __AVR_ATmega8__
GIFR |= (1<<INTF0);// clear flag
GICR |= (1<<INT0);// Int enable
#endif
}

void Disable_ExtInt()
{
#ifdef __AVR_ATmega1284P__
EIMSK &= ~(1<<INT0);
#endif

#ifdef __AVR_ATmega8__
GICR &= ~(1<<INT0);// Int enable
#endif
}

void GetAdcs()
{
unsigned int stableChnlBlk = 0;
if(curChnlBlk == 0)stableChnlBlk = 4;


byteSendArr[0] = (ppmInputChnls[0 + stableChnlBlk] & 0b0000001111100000)>>5;
byteSendArr[1] = (ppmInputChnls[0 + stableChnlBlk] & 0b0000000000011111);

byteSendArr[2] = (ppmInputChnls[1 + stableChnlBlk] & 0b0000001111100000)>>5;
byteSendArr[3] = (ppmInputChnls[1 + stableChnlBlk] & 0b0000000000011111);


byteSendArr[4] = (ppmInputChnls[2 + stableChnlBlk] & 0b0000001111100000)>>5;
byteSendArr[5] = (ppmInputChnls[2 + stableChnlBlk] & 0b0000000000011111);

byteSendArr[6] = (ppmInputChnls[3 + stableChnlBlk] & 0b0000001111100000)>>5;
byteSendArr[7] = (ppmInputChnls[3 + stableChnlBlk] & 0b0000000000011111);

}


void PpmEdgeInput()
{
	TIFR1 |= 0b00100000;
	ticksEnd = ICR1;
	
	if(ticksEnd > ticksStart)
	{
		pulseLength = ticksEnd - ticksStart;
	}
	else
	{
		pulseLength = 65535 - ticksStart + ticksEnd;
	}



	if(pulseLength > 6000)
	{
		pulseCntr = 0;
		if(curChnlBlk >= 4)curChnlBlk = 0;
		else curChnlBlk = 4;
	}
	else 
	{
		if(pulseCntr < 4)
		{
			pulseLength = pulseLength >> 1;
			if(pulseLength < 1000) pulseLength = 0;
			else pulseLength -= 1000;

			if(pulseCntr == 0)
			{
				if(pulseLength > 700)
				{
					PORTD |= 0b00100000;
				}
				else
				{
					PORTD &= 0b11011111;
				}
			}

			ppmInputChnls[pulseCntr + curChnlBlk] = pulseLength;
			pulseCntr++;
		}
	}
		
	ticksStart = ticksEnd;
}

int main(void)
{ 

Enable_ExtInt();

/* Set baud rate  for 9600 Baud*/
UBRRH_COM = (unsigned char)(0);
/* Enable receiver and transmitter */
UCSRB_COM = (1<<7)|(1<<4)|(1<<3);//
/* Set frame format: 8data, 1stop bit */
#ifdef __AVR_ATmega8__
UBRRL_COM = (unsigned char)(102);
UCSRC_COM = 128+6; 
#endif

#ifdef __AVR_ATmega1284P__
UBRRL_COM = (unsigned char)(102);
UCSRC_COM = 6; 
#endif

PORTD |= CTS;


#ifdef __AVR_ATmega8__
MCUCR = 1; // define Int Sense -> any edge
DDRD = 0b00000010; 
DDRB |= 2;
PORTB |= 0b00111110;
PORTD |= 0b01100000;
#endif 


#ifdef __AVR_ATmega1284P__

EICRA = 0b00000001;
DDRD = 0b00100010;//bit 5 LED
PORTC = 0b11111111;
TCCR1B = 0b01000010;
#endif

sei(); 

while(1)
{

	if(TIFR1 & 0b00100000)PpmEdgeInput();

	if(extMode == EXT_DIG_FILL)
	{
		extMode = EXT_DIG_REQ;
		byteCntr = 0;
		switchBits = GetSwitchPins();
		if(TOKEN_FLAG == 0)
		{
			byteSendArr[0] = DIG_BEGIN;
		}
		else
		{
			byteSendArr[0] = 0;
		}
		byteSendArr[0] |= (switchBits >> 5);
		byteSendArr[1] = DIG_END;
		byteSendArr[1] |= (switchBits & 0b00011111);
		Enable_UDREIE();
	}
	else if(extMode == EXT_AMT_FILL)
	{
		extMode = EXT_INIT;
		byteCntr = 0;
		switchBits = GetSwitchPins();
		if(TOKEN_FLAG == 0)
		{
			byteSendArr[0] = MSG_AMT_REQ_BEG;
		}
		else
		{
			byteSendArr[0] = 0;
		}
		byteSendArr[0] |= 8;
		byteSendArr[1] = (MSG_AMT_REQ_END + 3);
		Enable_UDREIE();
	}
	else if(extMode == EXT_ADC_FILL)
	{
		extMode = EXT_ADC_REQ;
		byteCntr = 0;
		GetAdcs();
		if(TOKEN_FLAG == 0)
		{
			byteSendArr[0] |= ADC_BEGIN;
		}
		else
		{
			//byteSendArr[0] = 0;
		}
		byteSendArr[7] |= ADC_END;
		Enable_UDREIE();
	}
	
	/*
#define DIG_BEGIN			128
#define DIG_END				128+32
#define ADC_BEGIN 			128 + 64
#define ADC_END 			128 + 64 + 32
#define MSG_AMT_REQ_BEG		64
#define MSG_AMT_REQ_END		64 + 32

#define EXT_INIT		2
#define EXT_DIG_REQ		0
#define EXT_ADC_REQ		1
#define EXT_INIT		2
#define EXT_DIG_REQ		0
#define EXT_ADC_REQ		1
#define EXT_IDLE		4
#define EXT_AMT			3
#define EXT_INIT		2
#define EXT_DIG_REQ		0
#define EXT_ADC_REQ		1
uint16_t amtOfExtAdc = 0, amtOfExtDigs = 0, extMode = EXT_INIT;
	*/
	
	#ifdef __AVR_ATmega8__
	ledCntr++;
	if(ledCntr == 3000)PORTB &= ~2;
	else if(ledCntr == 6000)
	{
		PORTB |= 2;
		ledCntr = 0;
	}
	#endif

}
}//main

/**/
SIGNAL (INT0_vect)
{
	DDRD |= RTS;
	Disable_ExtInt();
}


SIGNAL (USART_RX_vect_COM)//TIMER1_COMPA_vect) 
{ 
char rxChar;
char newMode;
unsigned int headTmp;	

	rxChar = UDR_COM;
	newMode = rxChar & 0b11000000;
	if(newMode != 0)
	{
		if(newMode != extModeOld)
		{
			modeCntr = 0;
		}
		else
		{
			modeCntr++;
		}
		extModeOld = newMode;
	}
	headTmp = head;
	byteArr[head++] = rxChar;
	if(head >= BUF_LEN)head = 0;
	if((rxChar & 0b11100000) == DIG_BEGIN)
	{
		tail = headTmp;
		extMode = EXT_DIG_PASS;
		Enable_UDREIE();
	}
	else if((rxChar & 0b11100000) == DIG_END)
	{
		if(extMode != EXT_DIG_PASS)
		{
			extMode = EXT_DIG_FILL;
			TOKEN_FLAG = 0;
		}
		else 
		{
			Enable_UDREIE();
		}
	}
	else if((rxChar & 0b11100000) == MSG_AMT_REQ_BEG)
	{
		tail = headTmp;
		extMode = EXT_AMT_PASS;
		Enable_UDREIE();
	}
	else if((rxChar & 0b11100000) == MSG_AMT_REQ_END)
	{
		if(extMode != EXT_AMT_PASS)
		{
			extMode = EXT_AMT_FILL;
			TOKEN_FLAG = 0;
		}
		else 
		{
			Enable_UDREIE();
		}
	}
	else if((rxChar & 0b11100000) == ADC_BEGIN)
	{
		tail = headTmp;
		extMode = EXT_ADC_PASS;
		Enable_UDREIE();
	}
	else if((rxChar & 0b11100000) == ADC_END)
	{
		if(extMode != EXT_ADC_PASS)
		{
			extMode = EXT_ADC_FILL;
			TOKEN_FLAG = 0;
		}
		else 
		{
			Enable_UDREIE();
		}
	}
	
	/*
	if((UCSRA_COM & 128) == 128)//Rx has 2position buffer -> so in case there are two chars
	{
		rxChar = UDR_COM;
		byteArr[head++] = rxChar;
		if(head >= BUF_LEN) head = 0;
	}
	*/
	if(DiffHeadTail(head, tail) < (10))
	{
		DDRD &= ~RTS;
		Enable_ExtInt();
	}

}


SIGNAL (USART_UDRE_vect_COM)
{ 
char tmpTxChar;

	if(IsCtsFtee() == CTS_FREE)
	{
		if(extMode == EXT_DIG_PASS)
		{
			tmpTxChar = byteArr[tail++];
			if(tmpTxChar & 0b00100000)
			{
				extMode = EXT_DIG_FILL;
				TOKEN_FLAG = 1;
				tmpTxChar &= 0b00011111;
				Disable_UDREIE();
			}
			
			UDR_COM = tmpTxChar;
			if(tail >= BUF_LEN)tail = 0;
			if(head == tail)
			{
				Disable_UDREIE();
			}
		}
		else if(extMode == EXT_AMT_PASS)
		{
			tmpTxChar = byteArr[tail++];
			if(tmpTxChar & 0b00100000)
			{
				extMode = EXT_AMT_FILL;
				TOKEN_FLAG = 1;
				tmpTxChar &= 0b00011111;
				Disable_UDREIE();
			}
			
			UDR_COM = tmpTxChar;
			if(tail >= BUF_LEN)tail = 0;
			if(head == tail)
			{
				Disable_UDREIE();
			}
		}
		else if(extMode == EXT_ADC_PASS)
		{
			tmpTxChar = byteArr[tail++];
			if(tmpTxChar & 0b00100000)
			{
				extMode = EXT_ADC_FILL;
				TOKEN_FLAG = 1;
				tmpTxChar &= 0b00011111;
				Disable_UDREIE();
			}
			
			UDR_COM = tmpTxChar;
			if(tail >= BUF_LEN)tail = 0;
			if(head == tail)
			{
				Disable_UDREIE();
			}
		}
		else
		{
			UDR_COM = byteSendArr[byteCntr++];
		
			if(extMode == EXT_DIG_REQ)
			{
				if(byteCntr == 2)
				{
					extMode = EXT_IDLE;
					Disable_UDREIE();
				}
			}
			else if(extMode == EXT_ADC_REQ)
			{
				if(byteCntr == 8)
				{
					extMode = EXT_IDLE;
					Disable_UDREIE();
				}
			}
			else if(extMode == EXT_INIT)
			{
		
				if(byteCntr == 2)
				{
			
					extMode = EXT_IDLE;
					Disable_UDREIE();
				}
			}
		}
	}
}

