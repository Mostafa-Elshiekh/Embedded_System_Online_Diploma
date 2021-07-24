/*
 * GPIOs_driver.h
 *
 * Created: 7/24/2021 2:06:34 PM
 *  Author: Mostafa Elshiekh
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include "AVR_MEMORY_MAP.h"

#ifndef GPIOS_DRIVER_H_
#define GPIOS_DRIVER_H_

#define  A 0x39
#define  B 0x36
#define  C 0x33
#define  D 0x30
#define  output 1
#define input 0
void  Bin_Set(uint8_t  base , uint8_t  bit);
void	 Bin_Rest (uint8_t  base , uint8_t  bit);
void	 toggle_bit (uint8_t  reg , uint8_t  bit);
void Pin_Direction(uint8_t  base , uint8_t  bin , uint8_t  state );  //base is register bin
void Port_Direction(uint8_t  base  , uint8_t  state ) ; //base is register bin
uint8_t  Port_Read(uint8_t  base);
uint8_t  Port_Write(uint8_t  base , uint8_t  value);
uint8_t  Bin_Read(uint8_t  base , uint8_t   bin);
uint8_t  Bin_Write(uint8_t  base , uint8_t  bin, uint8_t  value);

#endif /* GPIOS_DRIVER_H_ */