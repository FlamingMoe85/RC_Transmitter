#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile unsigned int ticksEnd = 0, ticksStart = 0, pulseLength = 0;
volatile unsigned char pulseCntr = 0, periodCnt = 0, periodCntOld = 0, 
						logOn = 0, nextPinMask = 0, tmp = 0;
volatile unsigned int channel[7];


int main(void)
{ 

TCCR1B = 0b01000010;
TIMSK = 0b00100000; // Input Capture Interrupt

DDRB = 0b01111110;
sei();
while(1)
{

}

}

SIGNAL (TIMER1_CAPT_vect)
{
	ticksEnd = ICR1;
	
	PORTB = nextPinMask;

	if(pulseCntr == 0)	
	{
		nextPinMask = 8;
	}
	else if(pulseCntr == 1)
	{
		nextPinMask = 16;
	}
	else if(pulseCntr == 2)
	{
		nextPinMask = 32;
	}
	else if(pulseCntr == 3)
	{
		nextPinMask = 64;
	}	
	else if(pulseCntr == 4)
	{
	
		nextPinMask = 0;
	}	
	else if(pulseCntr == 5)
	{
	
		nextPinMask = 0;
	}	
	else if(pulseCntr == 6)
	{
	
		nextPinMask = 2;
	}	
	else if(pulseCntr == 7)
	{
	
		nextPinMask = 4;
	}

	if(ticksEnd > ticksStart)
	{
		pulseLength = ticksEnd - ticksStart;
	}
	else
	{
		pulseLength = 65535 - ticksStart + ticksEnd;
	}



	if(pulseLength > 3000)
	{
		pulseCntr = 0;
		periodCnt++;
		logOn = 1;
	}
	else 
	{
		//channel[pulseCntr] = pulseLength;
		pulseCntr++;
	}
		
	ticksStart = ticksEnd;
}
