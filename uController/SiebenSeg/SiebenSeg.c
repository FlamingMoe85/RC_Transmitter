#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile unsigned int ticksEnd = 0, ticksStart = 0, pulseLength = 0;
volatile unsigned char pulseCntr = 0, periodCnt = 0, periodCntOld = 0;
volatile unsigned int channel[7];

unsigned char segs[10] = {	0b01110111,
							0b00010001,
							0b01101011,
							0b00111011,
							0b00011101,
							0b00111110,
							0b01111100,
							0b00010011,
							0b01111111,
							0b00111111};

int main(void)
{

TCCR1B = 0b00000001;
TIMSK1 = 0b00100000; // Input Capture Interrupt
sei(); 
DDRA = segs[8];
//PORTA = segs[8];
while(1)
{

pulseLength = 1850;
	//if(periodCnt != periodCntOld)
	//{
		if(pulseLength > 1900){DDRA = segs[9];}
		else if(pulseLength > 1800){DDRA = segs[8];}
		else if(pulseLength > 1700){DDRA = segs[7];}
		else if(pulseLength > 1600){DDRA = segs[6];}
		else if(pulseLength > 1500){DDRA = segs[5];}
		else if(pulseLength > 1400){DDRA = segs[4];}
		else if(pulseLength > 1300){DDRA = segs[3];}
		else if(pulseLength > 1200){DDRA = segs[2];}
		else if(pulseLength > 1100){DDRA = segs[1];}
		else {DDRA = segs[0];}
		periodCntOld = periodCnt;
	//}

}

}

SIGNAL (TIMER1_CAPT_vect)
{
	if((TCCR1B & 64) == 64)//rising edge
	{
		ticksStart = TCNT1;
		TCCR1B = 0b00000001;
	}
	else // falling edge
	{
		TCCR1B = 0b01000001;
		ticksEnd = TCNT1;
		if(ticksEnd > ticksStart)
		{
			pulseLength = ticksEnd - ticksStart;
		}
		else
		{
			pulseLength = 65535 - ticksStart + ticksEnd;
		}
/*
		if(pulseLength > 2500)
		{
			pulseCntr = 0;
			periodCnt++;
		}
		else 
		{
			channel[pulseCntr] = pulseLength;
			pulseCntr++;
		}
		*/
	}
}

/*
	if((TCCR1B & 64) == 0)//falling edge
	{
		ticksStart = TCNT1;
		TCCR1B = 0b01000001;
	}
	else // rising edge
	{
		TCCR1B = 0b00000001;
		ticksEnd = TCNT1;
		if(ticksEnd > ticksStart)
		{
			pulseLength = ticksEnd - ticksStart;
		}
		else
		{
			pulseLength = 65535 - ticksStart + ticksEnd;
		}

		if(pulseLength > 2500)
		{
			pulseCntr = 0;
			periodCnt++;
		}
		else 
		{
			channel[pulseCntr] = pulseLength;
			pulseCntr++;
		}
	}
*/
