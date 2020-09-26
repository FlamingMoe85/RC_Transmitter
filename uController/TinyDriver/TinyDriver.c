#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile static uint16_t timer_ovf = 0, cntrVal = 0, cntrValOld = 0, state = 50;
volatile static uint16_t pulseLength = 0;


/*
PB0 PWM Out
PB2 BW
PB3 InputCapture
PB 4 FW
*/

int main(void)
{ 
	DDRB = 0b00010110;
//	PORTB = (1 << PCIE);
	GIMSK = (1 << PCIE);
	PCMSK = (1<<PCINT3);

	//TCCR0A = 0b00000011;
	TCCR0B = 2;
	TIMSK = 2;

 TCCR1 = 0b01100001;
	//GTCCR = 0b00100000;

 	
	OCR1C = 255;
sei();
	while(1)
	{ 
	//OCR1A = 0;
	}

}

ISR(PCINT0_vect)
{

	if((PINB & 8) == 0)
	{
	
		cntrVal = TCNT0; 

		TCCR0B = 0; 

		pulseLength = (timer_ovf * 256)+cntrVal; 

		if(pulseLength > 1600)
		{  
		//if(pulseLength > 2020) pulseLength = 2020;
		 OCR1A = 255;//((pulseLength-1510) >> 1);
		 	/*if(state == 50) state++;
			if(state == 55)
			{

				PORTB |= 0b00010000;
				//OCR1A = ((pulseLength-1510) >> 1);
			}
			else
			{
				//OCR1A = 0;
				PORTB &= 0b11101111;
			}*/
		 }
	 //	else if(pulseLength < 1250)
	 //	{   
	//	 	OCR1A = 20;
				//OCR1A = ((1490 - pulseLength) >> 2);
		 	/*if(state == 50) state--;
			if(state == 45)
			{
				PORTB |= 0b00000100;
				//OCR1A = ((1490 - pulseLength) >> 2);
			}
			else
			{
				OCR1A = 0;
				PORTB &= 0b11111011;
			}*/
	  //    }
		else
		{
		 OCR1A = 0;
            //PORTB &= 0b11111011;
            //PORTB &= 0b11101111; 
		}
	}
	else
	{
		timer_ovf = 0;
		TCNT0 = 0; 
		TCCR0B = 2;
		TIMSK = 2;
		TIFR = 2;
	}
}

ISR(TIM0_OVF_vect)
{

  timer_ovf++;
  /*
  if((pulseLength > 510) && (pulseLength < 490))
  {
	  if(state > 50)
	  {
		if(state < 55)state++; 
	  }
	  else if(state < 50)
	  {
	  	if(state > 45) state--;
	  }
  }
  else
  {
  	if(state > 50) state--;
	else if(state < 50) state++;
  }*/
}
