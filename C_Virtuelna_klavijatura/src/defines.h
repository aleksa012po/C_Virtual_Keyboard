/*
 * defines.h
 *
 * Created: 29.12.2022. 22:37:17
 *  Author: user
 */ 


#ifndef DEFINES_H_
#define DEFINES_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define BAUD 14400
#define UBRR0_H ((((F_CPU)/(BAUD))/16)-1) >> 8;
#define UBRR0_L ((((F_CPU)/(BAUD))/16)-1);

#endif /* DEFINES_H_ */