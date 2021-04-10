/*
 * student_data_base.c
 *
 *  Created on: Apr 5, 2021
 *      Author: musta
 */


#include "student_data_base.h"


/*FIFO APIs*/


FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo ,element_type* buf,unsigned int length)
{
	if(buf== NULL)
		return FIFO_NULL;

	fifo->base=buf;
	fifo->tail=buf;
	fifo->head=buf;
	fifo->count=0;
	fifo->length=length;
	return FIFO_no_error;
}



FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,element_type item)
{
	/*check if queue is valid ?*/
	if(!fifo->base || !fifo->head  || !fifo->tail)
		return FIFO_NULL;

	/*check if queue is full ?*/
	if(FIFO_is_full(fifo)==FIFO_full)
		return FIFO_full;

	/*enqueue data*/
	*(fifo->head)=item;
	fifo->count++;

	/*circler fifo*/
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head=fifo->base;

	else
		fifo->head++;

	return FIFO_no_error;


}


FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo,element_type* item)
{

	/*check if queue is valid ?*/
	if(!fifo->base || !fifo->head  || !fifo->tail)
		return FIFO_NULL;

	/*check if queue is empty ?*/
	if(fifo->count==0)
		return FIFO_empty;

	/*dequeue data*/
	*item=*(fifo->tail);
	fifo->count--;

	/*circler fifo*/
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail=fifo->base;

	else
		fifo->tail++;

	return FIFO_no_error;



}


FIFO_Buf_status FIFO_is_full(FIFO_Buf_t* fifo)
{
	/*check if queue is valid ?*/
	if(!fifo->base || !fifo->head  || !fifo->tail)
		return FIFO_NULL;

	/*check if queue is full ?*/
	if(fifo->count==fifo->length)
		return FIFO_full;

	return FIFO_no_error;
}


void FIFO_print(FIFO_Buf_t* fifo)
{
	element_type *temp;
	int i;

	/*if fifo is empty*/
	if(fifo->count==0)
	{
		printf("fifo is empty\n");
	}

	else
	{
		temp=fifo->tail;
		printf("\n ========= fifo_print =========\n");
		for(i=0;i<fifo->count;i++)
		{
			printf("\t the element number %d is %d \n",i+1,*temp);
			temp++;
		}
	}
}





