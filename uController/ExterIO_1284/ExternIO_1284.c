#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


volatile char byteArr[2], byteSendArr[8], byteCntr = 0, rxFlag = 0, txFlag = 0, nextByte = 0, byteSendTrigger = 0;  
volatile unsigned int head = 0, tail = 0;
volatile char freeState = 0;

const char RX_FREE = 0;
const char RX_BUSY = 1;

char tmp, switchBits;

#define TX_FREE  0b00001000
#define SIG_BUSY 0b00010000

/**/

void SendByteCntr(char val)
{ 
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = val;
	while ( !( UCSR0A & (1<<UDRE0)) );

} 

char GetTick()
{
	static unsigned int c1 = 0, c2 = 0;
	c1++;
	if(c1 >= 1000)
	{
		c1 = 0;
		c2++; 
	} 
	if(c2 >= 80)
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
		DDRD |= SIG_BUSY; 
	}
}

char GET_RX_STATE()
{ 
	if((PIND & TX_FREE) == TX_FREE) return RX_FREE;
	else return RX_BUSY;
}

void UartRx()
{
char tmpChar;
	
rxFlag = 0;

 	
	tmpChar = UDR0;
	byteArr[head++] = tmpChar;
	
	if(head == 2) head = 0;
	byteCntr++;
	if((UCSR0A & 0b10000000) == 128)
	{ 
		tmpChar = UDR0;
		byteArr[head++] = tmpChar; 
		if(head == 2) head = 0;
		byteCntr++;
    }  

	//currently only use of one expander which is trigegred by an 'a', 
	// so the following is ok
	byteCntr = 0;
}

void Send()
{
	

	//if(byteCntr > 0)
	if(byteCntr < 8)
 	{
	

// 		if((GET_RX_STATE() == RX_FREE) && ((UCSR0A & 64)==0))
		if((UCSR0A & 64)==0)
 		{ 
			
				PORTC |= 0b00100000;
 			 	UDR0 = byteSendArr[byteCntr];

		 	if(tail == 2) tail = 0;
			//byteCntr--; 
			byteCntr++;
		 }  
		 
 	}  
	if(byteCntr == 8)SignalCapa(RX_FREE);
}

void UartTx()
{
txFlag = 0;

	//void Send();
}



int main(void)
{ 


/* Set baud rate  for 9600 Baud*/
UBRR0H = (unsigned char)(0);
UBRR0L = (unsigned char)52;
/* Enable receiver and transmitter */
UCSR0B = (1<<7)|(1<<6)|(1<<RXEN0)|(1<<TXEN0);//
//UCSR0B = (1<<RXEN0);
/* Set frame format: 8data, 2stop bit */
UCSR0C = (1<<USBS0)|(3<<UCSZ00);
 
DDRD = 0b01000010;
PORTD = TX_FREE;

EICRA = 0b00001000;
EIFR = 0b00000010;
EIMSK = 0b00000010;
 
//sei(); 

 
 //PORTD |= 0b01000000;

 sei(); 

PORTC = 0b11111111;
while(1)
{ 

if(GetTick())
{
	if((PIND & 0b01000000) == 64)
	{
//		PORTD = 0;
	}
	else
	{
//		PORTD = 64;
	}
}
 
	switchBits = (PINC ^ 0b11111111);
	byteSendArr[0] = 128;
	byteSendArr[0] |= (switchBits >> 2);
	byteSendArr[1] = 0;
	byteSendArr[1] |= (switchBits & 3);

	byteSendArr[2] = 0;
	byteSendArr[3] = 0;

	byteSendArr[4] = 42;
	byteSendArr[5] = 42;

	byteSendArr[6] = 32;
	byteSendArr[7] = 0+64;

	if(switchBits == 16)
	{
		PORTD |= 64;
	}
	else
	{
		PORTD = PORTD & ~(64);
	}

	Send();   

	if(rxFlag == 1)UartRx();
	if(txFlag == 1)UartTx();
}
}//main

/**/
SIGNAL (INT1_vect)
{
	DDRD |= SIG_BUSY;
	EIMSK = 0b00000000;

}

SIGNAL (USART0_RX_vect)//TIMER1_COMPA_vect) 
{ 
	//SignalCapa(RX_BUSY); 
	DDRD |= SIG_BUSY;
	//UartRx();
	
rxFlag = 0;
 
	byteArr[head++] = UDR0;
	
	if(head == 2) head = 0;
	//byteCntr++; 
	//currently only use of one expander which is trigegred by an 'a', 
	// so the following is ok
	if(byteCntr == 8)byteCntr = 0;

}

SIGNAL (USART0_TX_vect)//TIMER1_COMPA_vect) 
{ 
if(freeState == 1)
{
EIFR = 0b00000010;
EIMSK = 0b00000010;
		freeState = 0;
		DDRD &= ~(SIG_BUSY); 
		}
}

