/*
 * student_data_base.h
 *
 *  Created on: Apr 5, 2021
 *      Author: musta
 */

#ifndef STUDENT_DATA_BASE_H_
#define STUDENT_DATA_BASE_H_

#include <stdint.h>
#include <stdio.h>

/*determine type Ex:(uint8_t,uint16_t,uint32_t...)*/
#define element_type uint8_t
/*determine the width of buffer or array*/
#define width1 5

typedef struct
{
	char FirstName[20];
	char LastName[20];
	element_type ID;
	float GPA;
	char CoursesResgisterd[10][10];
}SStudent_Info;


/*determine type of array with same of type of element*/
SStudent_Info student_buffer[width1];


/*FIFO data type*/
typedef struct
{

	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;


typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_Buf_status;


/*FIFO APIs*/

/* input :pointer to your object , pointer to the array to storing ,length of array
 * process :init the fifo (head,base,length,count)
 * return: fifo no error if init is done  */
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo ,element_type* buf,unsigned int length);


/* input :pointer to your object ,item which need add it in fifo
 * process :adding new item
 * return: fifo no error if adding is done  */
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,element_type item);


/* input :pointer to your object ,pointer to item which nedd get it
 * process :geting item from the fifo
 * return: lifo no error if geting is done  */
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo,element_type* item);


/*input :pointer to your object
 *process :check if fifo is full ?
 *return :FIFO_Buf_status */
FIFO_Buf_status FIFO_is_full(FIFO_Buf_t* fifo);


/*print all element in fifo*/
void FIFO_print(FIFO_Buf_t* fifo);




#endif /* STUDENT_DATA_BASE_H_ */
