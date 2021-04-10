/*
 ============================================================================
 Name        : FIFO_buffer.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIFO.h"

unsigned int buffer1[5];

int main(void)
{
	unsigned int i;

	LIFO_buf_t uart_lifo,I2C_lifo;
	/*static allocation*/
	Lifo_init(&uart_lifo,buffer1,5);
	/*dynamic allocation*/
	unsigned int *buffer2=(unsigned int*)malloc(5*sizeof(unsigned int));
	Lifo_init(&I2C_lifo,buffer2,5);

	for(i=1;i<=6;i++) //add
	{
		if (LIFO_Add_item(&uart_lifo,i)==LIFO_no_error)
			printf("UART_LIFO:add: %d\n",i);
	}

	printf("\n");
	for(i=5;i>0;--i) //get
	{
		if (LIFO_get_item(&uart_lifo,&i)==LIFO_no_error)
			printf("UART_LIFO:get: %d\n",i);
	}





	return EXIT_SUCCESS;
}
