/*
 * uart.c
 *
 * Created: 29.12.2022. 23:49:59
 *  Author: user
 */ 

#include <avr/io.h>

void UART_putch(unsigned char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	
		UDR0 = data;
}

char UART_getch()
{
	char data;
	
	while(!(UCSR0A & (1 << RXC0)));
	
		return data = UDR0;
	
}