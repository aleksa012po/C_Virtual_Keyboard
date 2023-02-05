/*
 * Virtuelna_klavijatura.c
 *
 * Created: 29.12.2022. 22:34:28
 * Author : Aleksandar Bogdanovic
 */ 

#include <avr/io.h>
#include "defines.h"
#include "init.h"
#include "keyboard.h"


int main(void)
{
    UART_init();
    while (1) 
    {
		keyboard_init();
    }
}

