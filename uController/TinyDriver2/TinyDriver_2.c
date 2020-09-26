#include <avr/io.h> 
#include <stdint.h> 

#define NEUTRAL 663 // due to 2µs timebase => 1300µs
#define DEAD_BAND 5

#define NEUTRAL_UPPER	NEUTRAL+DEAD_BAND
#define TOP	NEUTRAL_UPPER+255

#define NEUTRAL_LOWER	NEUTRAL-DEAD_BAND
#define BOTTOM NEUTRAL_LOWER-255

volatile static uint16_t pulseLength = 0, state = 5;


/*
PB1 PWM Out / OCR1A
PB2 Backward Enable
PB3 "InputCapture"
PB 0 Forward Enable
*/

int main(void)
{ 
	DDRB = 0b00000111; 
 
	TCCR0B = 1; 

 	TCCR1 = 0b01100100; 
	OCR1C = 255; 

	while(1)
	{ 
	 	while((PINB & 8) == 0);
		TCNT0 = 0;
		pulseLength = 0;
		while((PINB & 8) == 8)
		{
			while(TCNT0 < 16); // creates timeslots with 2µs length
			TCNT0 = 0;
			pulseLength++;
		} 

		if(pulseLength > NEUTRAL_UPPER) // grater than 
		{ 
			if(state == 8)
			{
				DDRB |= 0b00000010;//set Pin to output
				if(pulseLength > TOP) pulseLength = TOP;
				pulseLength -= NEUTRAL_UPPER;
				OCR1A = pulseLength;
				PORTB |= 0b00000001;
			}
			else
			{
				OCR1A = 0; // set PWM to 0% dutycycle
				DDRB &= 0b11111101;//set Pin to input
				PORTB &= 0b11111010; // set fw/be enable low
				state++;
			}
		} 
		else if(pulseLength < NEUTRAL_LOWER)
		{
			if(state == 2)
			{
				DDRB |= 0b00000010;//set Pin to output
				if(pulseLength < BOTTOM)pulseLength = BOTTOM;
				OCR1A = BOTTOM - pulseLength;
				PORTB |= 0b00000100;
			}
			else
			{
				OCR1A = 0; // set PWM to 0% dutycycle
				DDRB &= 0b11111101;//set Pin to input
				PORTB &= 0b11111010; // set fw/be enable low
				state--;
			}
		}
		else
		{
			OCR1A = 0; // set PWM to 0% dutycycle
			DDRB &= 0b11111101;//set Pin to input
			PORTB &= 0b11111010; // set fw/be enable low

			if(state > 5) state--;
			if(state < 5) state++;
		}
	}

}
 
