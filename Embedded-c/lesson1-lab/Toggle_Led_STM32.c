/*
 ============================================================================
 Name        : Toggle_Led_STM32.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef volatile unsigned int vuint32_t;

typedef union
{
	vuint32_t ALL_ports;
	struct
	{
		vuint32_t PORTA:8;
		vuint32_t PORTB:8;
		vuint32_t PORTC:8;
		vuint32_t PORTD:8;
	}SIU_fields;
}SIU_R;



int main(void)
{
	volatile SIU_R* PORTS=(volatile SIU_R*)0x306100; /*address*/

	PORTS ->ALL_ports =0xFFFFFFFF; /*access all bits*/

	PORTS ->SIU_fields.PORTA=0XFF;


	return EXIT_SUCCESS;
}
