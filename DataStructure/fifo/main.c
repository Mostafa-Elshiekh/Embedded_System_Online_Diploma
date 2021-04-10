/*
 * main.c
 *
 *  Created on: Apr 5, 2021
 *      Author: musta
 */



#include <stdio.h>
#include <stdlib.h>
#include "student_data_base.h"

int main(void)
{
	FIFO_Buf_t student;
	int i,temp;
	if(FIFO_init(&student,student_buffer,5)==FIFO_no_error)
		printf("fifo init ------Done :) \n");








	/*FIFO_Buf_t FIFO_uart;
	element_type i,temp;
	if(FIFO_init(&FIFO_uart,uart_buffer,5)==FIFO_no_error)
		printf("fifo init ------Done :) \n");

	for(i=0;i<5;i++)
	{

		printf("FIFO Enqueue (%x) \n",i);
		if(FIFO_enqueue(&FIFO_uart,i)==FIFO_no_error)
			printf("\t fifo enqueue ----Done :)\n");
		else
			printf("\t fifo enqueue ----failed :( \n");
	}*/


	//FIFO_print(&FIFO_uart);  /*print all element in queue*/


	/*for(i=0;i<5;i++)
	{

		printf("FIFO Dequeue (%d) \n",i);
		if(FIFO_dequeue(&FIFO_uart,&temp)==FIFO_no_error)
			printf("\t fifo dequeue ----Done :)\n");
		else
			printf("\t fifo dequeue ----failed :( \n");
	}*/

	//FIFO_print(&FIFO_uart);  /*print all element in queue*/







	return EXIT_SUCCESS;
}

