/*
 * keypad.c
 *
 * Created: 4/22/2021 6:32:10 PM
 *  Author: Marco
 */ 


#include "KEYPAD_DRIVER.h"
#include "STM32F103C6_GPIO_DRIVERS.h"
#include "STM32_F103C6.h"




char keypad(void)
{
	MCAL_GPIO_WritePort(GPIOB, 0x0020);// Make Pin B5 High
	Wait();
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<0) ) return '7';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<1) ) return '4';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<3) ) return '1';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<4) ) return 'c';


	MCAL_GPIO_WritePort(GPIOB, 0x0040); // Make Pin B6 High
	Wait();
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<0) ) return '8';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<1) ) return '5';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<3) ) return '2';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<4) ) return '0';

	MCAL_GPIO_WritePort(GPIOB, 0x0080); // Make Pin B7 High
	Wait();
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<0) ) return '9';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<1) ) return '6';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<3) ) return '3';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<4) ) return '=';

	MCAL_GPIO_WritePort(GPIOB, 0x0100); // Make Pin B8 High
	Wait();
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<0) ) return '/';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<1) ) return '*';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<3) ) return '-';
	if(  (MCAL_GPIO_ReadPort(GPIOB)) &(uint16_t)(1<<4) ) return '+';


	return 'N';
}
