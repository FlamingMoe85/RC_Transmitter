#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile unsigned char bitCntr = 0, shftVar = 0, charCntr = 0, charCntr2=0;
volatile unsigned char toggleLed = 0;
volatile unsigned int ledBase = 0;
unsigned char tog = 0;
volatile unsigned char valArr[100];

int main(void)
{ 
/*
EICRA = 0b00001100;
EIFR |= 0b00000010;
EIMSK |= 0b00000010;
*/


UCSR0A = 2;
UBRR0H = (unsigned char)(0);
UBRR0L = (unsigned char)(16);
/* Enable receiver and transmitter */
UCSR0B = (1<<3);//
/* Set frame format: 8data, 1stop bit */

OCR1A = 1000;
TCCR1A = 3;
TCCR1B = 0b00011010;
TIMSK1 = 2;



DDRD = 0b01000010;//bit 6 LED
DDRA = 1;
sei();
while(1)
{
	while((PIND & 8) == 0)
	{

	}
	TCNT1 = 0;
	shftVar = shftVar <<1;
	shftVar |= (PIND & 1);
	bitCntr++;
	while((PIND & 8))
	{

	}
	TCCR1B |= 2;
	if(bitCntr == 8)
	{
		PORTA = tog++;
		valArr[charCntr] = shftVar;
		//UDR0 = 0b11000011;//shftVar;
		shftVar = 0;
		bitCntr = 0;
		charCntr++;
	}
}
}


SIGNAL (INT1_vect)
{
/*
	TCCR1B |= 2;
	bitCntr++;
	if(bitCntr == 8)
	{
		if((PORTD & 64) == 64)
		{
			PORTD &= 0b10111111;
		}
		else
		{
			PORTD |= 64;
		}
	}
	*/
}

SIGNAL(TIMER1_COMPA_vect)
{

charCntr2=0;
	TCCR1B &= 0b11111000;
	TCNT1 = 0;
	bitCntr = 0;
	shftVar = 0;
	tog = 0;
	/*UDR0 = charCntr;*/
/*	*/ 
//if(charCntr == 6)
{
	while(charCntr2 < charCntr)
	{
		UDR0 = valArr[charCntr2++];
		while((UCSR0A & 32) != 32);
	}
		while((UCSR0A & 32) != 32);
		UDR0 = 13;
		while((UCSR0A & 32) != 32);
		UDR0 = 10; 
}	
	charCntr = 0;
}
