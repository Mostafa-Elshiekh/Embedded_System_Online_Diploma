/*
 * FIFO.c
 *
 *  Created on: Mar 27, 2021
 *      Author: musta
 */
#include "lifo.h"

/*APIS*/
LIFO_status Lifo_init(LIFO_buf_t* lifo_buf,unsigned int* buf,unsigned int length)
{
	if(buf==NULL)
		return LIFO_Null;

	lifo_buf->base=buf;
	lifo_buf->head=buf;
	lifo_buf->length=length;
	lifo_buf->count=0;
	return LIFO_no_error;

}
LIFO_status LIFO_Add_item(LIFO_buf_t* lifo_buf,unsigned int item)
{
	/*check lifo is valid ?*/
	if(!lifo_buf->head || !lifo_buf->base)
		return LIFO_Null;

	/*check lifo is full ?*/
	if(lifo_buf->length==lifo_buf->count)
		return LIFO_full;

	/*add value*/
	*(lifo_buf->head)=item;
	(lifo_buf->head)++;
	(lifo_buf->count)++;
	return LIFO_no_error;
}
LIFO_status LIFO_get_item(LIFO_buf_t* lifo_buf,unsigned int *item)
{
	/*check lifo is valid*/
	if(!lifo_buf->head || !lifo_buf->base)
		return LIFO_Null;

	/*check lifo is empty ?*/
	if(lifo_buf->count==0)
		return LIFO_empty;

	/*get value*/
	(lifo_buf->head)--;
	*item=*(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error;



}





















