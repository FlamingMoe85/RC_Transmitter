#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


volatile char byteArr[2], byteCntr = 0, rxFlag = 0, txFlag = 0, nextByte = 0, byteSendTrigger = 0;  
volatile unsigned int head = 0, tail = 0;
volatile char freeState = 0;

const char RX_FREE = 0;
const char RX_BUSY = 1;

char tmp, switchBits;

void SendByteCntr(char val)
{ 
	while ( !( UCSRA & (1<<UDRE)) );
	UDR = val;
	while ( !( UCSRA & (1<<UDRE)) );

} 

char GetTick()
{
	static unsigned int c1 = 0, c2 = 0;
	c1++;
	if(c1 >= 100)
	{
		c1 = 0;
		c2++; 
	} 
	if(c2 >= 5)
	{
		c2 = 0; 
		return 1;
	}
	return 0;
}

void SignalCapa(char sig)
{
	if(sig == RX_FREE)
	{
		
		freeState = 1;
		//DDRD &= ~(0b00001000);  
		}
	else
	{ 
		DDRD |= 0b00001000; 
	}
}

char GET_RX_STATE()
{ 
	if((PIND & 0b00010000) == 16) return RX_FREE;
	else return RX_BUSY;
}

void UartRx()
{
char tmpChar;
	
rxFlag = 0;

 	
	tmpChar = UDR;
	byteArr[head++] = tmpChar;
	
	if(head == 2) head = 0;
	byteCntr++;
	if((UCSRA & 0b10000000) == 128)
	{ 
		tmpChar = UDR;
		byteArr[head++] = tmpChar; 
		if(head == 2) head = 0;
		byteCntr++;
    }  
}

void Send()
{
	

	if(byteCntr > 0)
 	{
	
 		if(GET_RX_STATE() == RX_FREE)
 		{
			
PORTC |= 0b00100000;
			 	UDR = switchBits;//byteArr[tail++];

		 	if(tail == 2) tail = 0;
			byteCntr--; 
		 }  
		 
 	}  
	if(byteCntr == 0)SignalCapa(RX_FREE);
}

void UartTx()
{
txFlag = 0;

	//void Send();
}



int main(void)
{ 


/* Set baud rate  for 9600 Baud*/
UBRRH = (unsigned char)(0);
UBRRL = (unsigned char)52;
/* Enable receiver and transmitter */
UCSRB = (1<<7)|(1<<6)|(1<<RXEN)|(1<<TXEN);//
//UCSRB = (1<<RXEN);
/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
DDRD = 0b00000010; 

PORTD |= 0b11100000; 
PORTB |= 0b11000001;

MCUCR = 0b00000010;
GICR = 0b01000000;
GIFR = 0b01000000;
DDRC = 0b00100000;
sei(); 


while(1)
{ 
	switchBits = ((PINB & 0b11000000) ^ 0b11000000) >> 6;

/**/
	tmp = ((PINB & 0b00000001) ^ 0b00000001) << 5;
	switchBits |= tmp;

	tmp = ((PIND & 0b11100000) ^ 0b11100000) >> 3;
	switchBits |= tmp;
	

	Send();  
/*
	if(freeState == 1)
	{
		if(GetTick() == 1)
		{
			freeState = 0;
			DDRD &= ~(0b00001000);
		}
	}*/

	if(rxFlag == 1)UartRx();
	if(txFlag == 1)UartTx();
}
}//main


SIGNAL (INT0_vect)
{
	DDRD |= 0b00001000;
	GICR = 0b00000000;

}

SIGNAL (USART_RXC_vect)//TIMER1_COMPA_vect) 
{ 
	//SignalCapa(RX_BUSY); 
	DDRD |= 0b00001000;
	//UartRx();
	
rxFlag = 0;
 
	byteArr[head++] = UDR;
	
	if(head == 2) head = 0;
	byteCntr++;
	/*if((UCSRA & 0b10000000) == 128)
	{ 
		byteArr[head++] = UDR; 
		if(head == 2) head = 0;
		byteCntr++;
    }  */
}

SIGNAL (USART_TXC_vect)//TIMER1_COMPA_vect) 
{ 
if(freeState == 1)
{
	GIFR = 0b01000000;
		GICR = 0b01000000;
		freeState = 0;
DDRD &= ~(0b00001000); 
		}
}
