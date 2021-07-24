/*
 * AVR_MEMORY_MAP.h
 *
 * Created: 7/23/2021 9:59:21 PM
 *  Author:  Mostafa Elshiekh
 */ 
#ifndef AVR_MEMORY_MAP_H_
#define AVR_MEMORY_MAP_H_

#define SetBin(port,bin) port |=(1<<bin)
#define RestBin(port,bin) port &=~(1<<bin)
#define ToggleBin(port,bin) port ^ =(1<<bin)

#define PORTA  (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*) 0x35)
#define PORTD (*(volatile unsigned char*)0x32)

#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

#define PINA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)



#endif /* AVR_MEMORY_MAP_H_ */