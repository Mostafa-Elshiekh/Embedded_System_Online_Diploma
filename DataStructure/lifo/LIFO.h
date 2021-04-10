/*
 * FIFO.h
 *
 *  Created on: Mar 27, 2021
 *      Author: musta
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef LIFO_H_
#define LIFO_H_


/*type definitions*/
typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned int * head;
	unsigned int * base;
}LIFO_buf_t;


typedef enum
{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null,
}LIFO_status;


/*APIS*/

/* input :pointer to your object , pointer to the array to storing ,length of array
 * process :init the lifo (head,base,length,count)
 * return: lifo no error if init is done  */
LIFO_status Lifo_init(LIFO_buf_t* lifo_buf,unsigned int* buf,unsigned int length);


/* input :pointer to your object ,item which nedd add it in lifo
 * process :adding new item
 * return: lifo no error if adding is done  */
LIFO_status LIFO_Add_item(LIFO_buf_t* lifo_buf,unsigned int item);


/* input :pointer to your object ,pointer to item which nedd get it
 * process :geting item from the lifo
 * return: lifo no error if geting is done  */
LIFO_status LIFO_get_item(LIFO_buf_t* lifo_buf,unsigned int *item);









#endif /* LIFO_H_ */
