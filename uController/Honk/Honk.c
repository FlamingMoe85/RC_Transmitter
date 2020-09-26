#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

char adcState = 0, adcVal = 0;;

char GetTick()
{
	static unsigned int c1 = 0, c2 = 0;
	c1++;
	if(c1 >= 10000)
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

int main(void)
{ 

DDRB = 0b00000001;

TCCR0A = 0b01000010;
TCCR0B = 0b00000011;
ADMUX = 0b00100010;


OCR0A = 30;//10 bis 150
while(1)
{ 
 	if((ADCSRA & 64) == 0) 
     {
			adcVal = ADCH;
			ADCSRA = 0b11000110; 
			adcVal = ADCH;
			if(adcVal < 10)
			{
				DDRB = 0;
			}
			else
			{
				DDRB = 1;
			}
        	OCR0A = 30 + ((adcVal-10) >> 1);  
     } 
}

}
