#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define BUF_LEN	20
volatile char byteArr[BUF_LEN], byteSendArr[8],  rxFlag = 0, txFlag = 0, nextByte = 0, byteSendTrigger = 0;  
volatile unsigned int head = 0, tail = 0, byteCntr = 8;
volatile char freeState = 0;
unsigned int adcVal, ledCntr = 0;

#define DIG_BEGIN_END	128
#define ADC_BEGIN_END	128 + 64
#define MSG_AMT_REQ		64
#define EXT_IDLE		4
#define EXT_AMT			3
#define EXT_INIT		2
#define EXT_DIG_REQ		0
#define EXT_ADC_REQ		1
volatile uint16_t amtOfExtAdc = 0, amtOfExtDigs = 0, extMode = EXT_IDLE;

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
unsigned char tmpC = 0;
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
//#ifdef __AVR_ATmega8__
ADMUX = 0b01000101;
ADCSRA = 0b11000111;
while ((ADCSRA & 64) == 64);
adcVal = ADC;
byteSendArr[0] = (adcVal & 0b0000111111000000)>>6;
byteSendArr[1] = (adcVal & 0b0000000000111111);

ADMUX = 0b01000100;
ADCSRA = 0b11000111;
while ((ADCSRA & 64) == 64);
adcVal = ADC;
byteSendArr[2] = (adcVal & 0b0000111111000000)>>6;
byteSendArr[3] = (adcVal & 0b0000000000111111);

ADMUX = 0b01000011;
ADCSRA = 0b11000111;
while ((ADCSRA & 64) == 64);
adcVal = ADC;
byteSendArr[4] = (adcVal & 0b0000111111000000)>>6;
byteSendArr[5] = (adcVal & 0b0000000000111111);
//#endif
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
DDRD = 0b01000010;//bit 6 LED
PORTC = 0b11111111;
#endif

sei(); 

while(1)
{ 
/*	switchBits = GetSwitchPins();
	

	byteSendArr[0] = 128;
	byteSendArr[0] |= (switchBits >> 2);
	byteSendArr[1] = 0;
	byteSendArr[1] |= (switchBits & 3);
	GetAdcs();
	*/
/*	byteSendArr[2] = 0;
	byteSendArr[3] = 0;

	byteSendArr[4] = 0;
	byteSendArr[5] = 0;

	byteSendArr[6] = 0;
	byteSendArr[7] = 0+64;
	*/

	//PORTC &= ~(0b00100000);

	//if((DiffHeadTail(head, tail) != 0) && (byteCntr == 8))
	if((DiffHeadTail(head, tail) != 0) && (extMode == EXT_IDLE))
//	if(DiffHeadTail(head, tail) != 0)
	{
	

		if(byteArr[tail] == DIG_BEGIN_END)
		{
			extMode = EXT_DIG_REQ;
			byteCntr = 0;
			switchBits = GetSwitchPins();
			byteSendArr[0] = DIG_BEGIN_END;
			byteSendArr[0] |= (switchBits >> 6);
			byteSendArr[1] = DIG_BEGIN_END;
			byteSendArr[1] |= (switchBits & 0b00111111);
			Enable_UDREIE();
			//UDR_COM = byteSendArr[byteCntr++];
		}
		else if(byteArr[tail] == ADC_BEGIN_END)
		{
			GetAdcs();
			byteSendArr[0] |= ADC_BEGIN_END;
			byteSendArr[5] |= ADC_BEGIN_END;
			extMode = EXT_ADC_REQ;
			byteCntr = 0;
			Enable_UDREIE();
		}
		else if(byteArr[tail] == MSG_AMT_REQ)
		{
			
			extMode = EXT_AMT;
			byteCntr = 0;
			byteSendArr[0] = MSG_AMT_REQ;
			byteSendArr[1] = 8;
			byteSendArr[2] = 0;
			byteSendArr[3] = MSG_AMT_REQ + 3;
			Enable_UDREIE();
		}
		tail++;
		if(tail == BUF_LEN)tail = 0;
	}
	
	/*
#define DIG_BEGIN_END	128
#define ADC_BEGIN_END	128 + 64
#define MSG_AMT_REQ		64
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

PORTC |= 0b00100000;
	
	byteArr[head++] = UDR_COM;
	if(head >= BUF_LEN)head = 0;
	if((UCSRA_COM & 128) == 128)//Rx has 2position buffer -> so in case there are two chars
	{
		byteArr[head++] = UDR_COM;
		if(head >= BUF_LEN) head = 0;
	}
	
	if(DiffHeadTail(head, tail) < (10))
	{
		DDRD &= ~RTS;
		Enable_ExtInt();
	}

}


SIGNAL (USART_UDRE_vect_COM)
{ 
	if(IsCtsFtee() == CTS_FREE)
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
			if(byteCntr == 6)
			{
				extMode = EXT_IDLE;
				Disable_UDREIE();
			}
		}
		else if(extMode == EXT_AMT)
		{
		
			if(byteCntr == 4)
			{
			
				extMode = EXT_IDLE;
				Disable_UDREIE();
			}
		}
	}
}

