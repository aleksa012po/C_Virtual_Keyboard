/*
 * tones.c
 *
 * Created: 3.1.2023. 10:36:48
 *  Author: user
 */ 

#define  F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <util/delay.h>
#include "tones.h"

int tempo;
double length;

// Sound function
void soundOn(double tone, double len)
{
	DDRD = (1 << PORTD5);		// Enable PORTD5 as output
	TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);		//  Compare Output Mode, non-PWM Mode, Clear OC0B on compare match, set OC0B at BOTTOM, (non-inverting mode), Fast PWM
	TCCR0B = (1 << WGM02) | (1 << CS02);		// Prescaler - Clk / 8
	OCR0A = tone;
	OCR0B = tone/2;
	length = (60.0/tempo)*len*4*1000.0;
	_delay_ms(length);
	DDRD &= (0 << PORTD5);		// Disable PORTD5 as output
	//_delay_ms(10);
}

// Pause/mute function
void pause(double len)
{
	DDRD &= (0 << PORTD5);
	length = (60.0/tempo)*len*4*1000.0;
	_delay_ms(length);
}