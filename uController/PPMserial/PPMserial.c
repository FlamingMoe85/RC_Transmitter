#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile unsigned int pulseArr[4] = {1000, 1300, 1600, 2000};

int main(void)
{ 
unsigned int tickCntr = 0;
char tmpPin, allDoneFlags = 15;
DDRB = 2;
TCCR1B = 0b00000010;
while(1)
{
	
	
	PORTB = 0;
	pulseArr[0] = 0; 
	pulseArr[1] = 0; 
	pulseArr[2] = 0; 
	pulseArr[3] = 0; 

	while(1)//wait for all Pins to be high
	{
		tmpPin = PINC & 2;
		if(tmpPin == 2)break; //then all Pins are high	
	}

	TCNT1 = 0;
	while(TCNT1 < 100)//avoid possible flickers
	{
	}

	allDoneFlags = 15;
	while(allDoneFlags != 0)//runs as long until all Pins are low again
	{
		tmpPin = PINC & 15;
		allDoneFlags &= tmpPin;

		//The "(pulseArr['n'] == 0)" checks are used as a flag that the certain channel is measured
		// Otherwise it gets permanently overwritten 
		if(((tmpPin & 1) == 0) && (pulseArr[0] == 0))pulseArr[0] = TCNT1;
		if(((tmpPin & 2) == 0) && (pulseArr[1] == 0))pulseArr[1] = TCNT1;
		if(((tmpPin & 4) == 0) && (pulseArr[2] == 0))pulseArr[2] = TCNT1;
		if(((tmpPin & 8) == 0) && (pulseArr[3] == 0))pulseArr[3] = TCNT1;
		// Pssst... (honestly here is (at least technically) some jitter going on)
	}

	// subtract the 1ms offset from the 1.5 ms signal
	if(pulseArr[0] < 1000)pulseArr[0] = 0;
	else pulseArr[0] -= 1000;

	if(pulseArr[1] < 1000)pulseArr[1] = 0;
	else pulseArr[1] -= 1000;

	if(pulseArr[2] < 1000)pulseArr[2] = 0;
	else pulseArr[2] -= 1000;

	if(pulseArr[3] < 1000)pulseArr[3] = 0;
	else pulseArr[3] -= 1000;


	//do the pulses of the 4 channels after another
	PORTB = 2;
	TCNT1 = 0;	
	OCR1A = 400;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));
	PORTB = 0;
	TCNT1 = 0;	
	OCR1A = pulseArr[0]+600;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));

	PORTB = 2;
	TCNT1 = 0;	
	OCR1A = 400;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));
	PORTB = 0;
	TCNT1 = 0;	
	OCR1A = pulseArr[1]+600;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));

	PORTB = 2;
	TCNT1 = 0;	
	OCR1A = 400;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));
	PORTB = 0;
	TCNT1 = 0;	
	OCR1A = pulseArr[2]+600;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));

	PORTB = 2;
	TCNT1 = 0;	
	OCR1A = 400;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));
	PORTB = 0;
	TCNT1 = 0;	
	OCR1A = pulseArr[3]+600;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));

	// "Stop token"
	PORTB = 2;
	TCNT1 = 0;	
	OCR1A = 400;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));
	PORTB = 0;

/*
	TCNT1 = 0;	
	OCR1A = 4000;
	TIFR |= 0b00010000;
	while(!(TIFR & 0b00010000));
	*/
}	
}
