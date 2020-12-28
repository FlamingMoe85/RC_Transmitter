#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define BUF_LEN	20
volatile char byteArr[BUF_LEN], byteSendArr[8],  rxFlag = 0, txFlag = 0, nextByte = 0, byteSendTrigger = 0;  
volatile unsigned int head = 0, tail = 0, byteCntr = 0;
volatile char freeState = 0;

const char DST_FREE = 0;
const char DST_BUSY = 1;

char tmp, switchBits;

#define TX_FREE  0b00001000
#define SIG_BUSY 0b00010000


void SignalCapa(char sig)
{
	if(sig == DST_FREE)
	{
		
		freeState = 1;
		}
	else
	{ 
		DDRD |= SIG_BUSY; 
	}
}

char GetDstState()
{ 
	if((PIND & TX_FREE) == TX_FREE) 
	{
		return DST_FREE;
	}
	else 
	{
		return DST_BUSY;
	}
}

void UartTx()
{
txFlag = 0;

}

unsigned int DiffHeadTail(unsigned int headC, unsigned int tailC)
{
	if(headC > tailC) return (headC - tailC);
	else if(headC < tailC)return (tailC - headC);
	else return 0;
}


int main(void)
{ 


/* Set baud rate  for 9600 Baud*/
UBRR0H = (unsigned char)(0);
UBRR0L = (unsigned char)52;
/* Enable receiver and transmitter */
UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);//
/* Set frame format: 8data, 2stop bit */
//UCSR0C = (1<<USBS0)|(3<<UCSZ00);
UCSR0C = (3<<UCSZ00);
 
DDRD = 0b01000010;
PORTD = TX_FREE;

EICRA = 0b00000001;
EIFR = 0b00000001;
EIMSK = 0b00000001;

sei(); 

PORTC = 0b11111111;
while(1)
{ 

 
	switchBits = (PINC ^ 0b11111111);
	byteSendArr[0] = 128;
	byteSendArr[0] |= (switchBits >> 2);
	byteSendArr[1] = 0;
	byteSendArr[1] |= (switchBits & 3);

	byteSendArr[2] = 0;
	byteSendArr[3] = 0;

	byteSendArr[4] = 0;
	byteSendArr[5] = 0;

	byteSendArr[6] = 0;
	byteSendArr[7] = 0+64;

	if(switchBits == 16)
	{
		//PORTD |= 64;
	}
	else
	{
		PORTD = PORTD & ~(64);
	}

//	if((DiffHeadTail(head, tail) != 0) && (byteCntr == 0))
	if(DiffHeadTail(head, tail) != 0)
	{
		tail++;
		if(tail == BUF_LEN)tail = 0;
		if(byteArr[tail] == 'a')
		{
	
			byteCntr = 0;

			UCSR0B |= (1<<UDRIE0);
			UDR0 = byteSendArr[byteCntr++];
		}
	}

}
}//main

/**/
SIGNAL (INT0_vect)
{
	DDRD |= SIG_BUSY;
	EIMSK = 0b00000000;
	
}

SIGNAL (USART0_RX_vect)//TIMER1_COMPA_vect) 
{ 

	byteArr[head++] = UDR0;
	if(head >= BUF_LEN)head = 0;
	if((UCSR0A & 128) == 128)//Rx has 2position buffer -> so in case there are two chars
	{
		byteArr[head++] = UDR0;
		if(head >= BUF_LEN) head = 0;
	}
	
	if(DiffHeadTail(head, tail) < (10))
	{


		DDRD &= ~SIG_BUSY;
		EIFR = 0b00000001;
		EIMSK = 0b00000001;
	}

}

SIGNAL (USART0_UDRE_vect)
{ 
if(switchBits == 16)PORTD |= 64;
	if(GetDstState() == DST_FREE)
	{
		UDR0 = byteSendArr[byteCntr++];
		if(byteCntr == 8)
		{
			UCSR0B &= ~(1<<UDRIE0);
		}
	}
}

