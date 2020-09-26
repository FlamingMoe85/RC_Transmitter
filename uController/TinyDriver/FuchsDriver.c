#include <avr/io.h> 
#include <stdint.h> 

#define NEUTRAL 500 // due to 2µs timebase => 1300µs
#define DEAD_BAND 5

#define NEUTRAL_UPPER	NEUTRAL+DEAD_BAND
#define TOP	NEUTRAL_UPPER+255

#define NEUTRAL_LOWER	NEUTRAL-DEAD_BAND
#define BOTTOM NEUTRAL_LOWER-255

volatile static uint16_t pulseLength = 0, state = 5;

uint16_t adcVal = 0;

/*
PB1 PWM Out / OCR1A
PB2 Backward Enable
PB3 "InputCapture"
PB 0 Forward Enable
*/

int main(void)
{ 
	ADMUX = 2;
	
	DDRB = 0b00001111; 
 	TCCR1 = 1;
	TCCR0B = 2; 
	/*
	TCCR0A = 0b10100011; 
	OCR0A = 10;
	OCR0B = 0;*/
	//OCR1C = 255; 

	while(1)
	{ 
	
	 	while((PINB & 16) == 0);
		TCNT1 = 0;
		pulseLength = 0;
		while((PINB & 16) == 16)
		{
			while(TCNT1 < 16); // creates timeslots with 2µs length
			TCNT1 = 0;
			pulseLength++;
		} 
	/*	
		ADCSRA = 0b11000110;
		while ((ADCSRA & 64) == 64)
		{
		};
		adcVal = ADCH<<6;
		adcVal |= ADCL;
		pulseLength = adcVal;//NEUTRAL_UPPER - 100;*/
		
		if(pulseLength > NEUTRAL_UPPER) // grater than 
		{ 
			if(state == 8)
			{
				DDRB |=  0b00001101;//set Pin 2 to output LOW
				PORTB &= 0b11110111;
				
				if(pulseLength > TOP) pulseLength = TOP;
				pulseLength -= NEUTRAL_UPPER;
				TCCR0A = 0b10000011; 
				OCR0A = pulseLength;
				//PORTB |= 0b00000001;
			}
			else
			{
				OCR0A = 0; // set PWM to 0% dutycycle
				DDRB &=  0b11111100;//set Pin to input
				PORTB |= 0b00000100;
				PORTB |= 0b00001000;
				TCCR0A = 0; 
				//PORTB &= 0b11111010; // set fw/be enable low
				state++;
			}
		}
		
		
		else if(pulseLength < NEUTRAL_LOWER)
		{
			if(state == 2)
			{
				DDRB |=  0b00000110;//set Pin to output
				PORTB &= 0b11111011;

				
				if(pulseLength < BOTTOM)pulseLength = BOTTOM;
				OCR0B = BOTTOM - pulseLength;
				TCCR0A = 0b00100011; 
				//PORTB |= 0b00000100;
			}
			else
			{
				TCCR0A = 0; 
				OCR0B = 0; // set PWM to 0% dutycycle
				DDRB &=  0b11111001;//set Pin to input
				PORTB |= 0b00001000;
				PORTB |= 0b00000100;
				
				//PORTB &= 0b11111010; // set fw/be enable low
				state--;
			}
		}
		else
		{
			OCR0A = 0; // set PWM to 0% dutycycle
			OCR0B = 0; // set PWM to 0% dutycycle
			DDRB &= 0b11110000;//set Pin to input
			//PORTB &= 0b11111010; // set fw/be enable low
			PORTB |= 0b00001100;
			PORTB &= 0b11111100;

			if(state > 5) state--;
			if(state < 5) state++;
		}
	}

}
 
