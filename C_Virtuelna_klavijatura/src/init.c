/*
 * init.c
 *
 * Created: 3.1.2023. 10:32:43
 *  Author: user
 */ 

#define F_CPU 16000000UL
#define BAUD 14400

#include <avr/io.h>
#include "defines.h"

void UART_init()
{
	UBRR0H = UBRR0_H;
	UBRR0L = UBRR0_L;
	
	UCSR0A = 0x00;								// Cleans UART status reg
	
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);		// Enable Rx and Tx
	
	UCSR0C = (1 << UCSZ01) | (UCSZ00);			// Asynchronous mode
}