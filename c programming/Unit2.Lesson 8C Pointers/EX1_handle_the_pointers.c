/*
 ============================================================================
 Name        : EX1_handle_the_pointers.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int m=29;
	int *ap=NULL;
	printf("Address of m : %p\n",&m);
	printf("Value of m : %d\n",m);
	ap=&m;
	printf("\nNow ab is assigned with the address of m\n");
	printf("Address of pointer ab : %p\n",ap); //address of m which ap point it
	printf("Content of pointer ab : %d\n",*ap);  //the value store in address which ap point it


	m=34;
	printf("\nThe value of m assigned to %d now \n",m);
	printf("Address of pointer ab : %p\n",ap);
	printf("Content of pointer ab : %d\n",*ap);  //the value store in address which ap point it

	*ap=7;
	printf("\nThe pointer variable ab is assigned with value %d now\n",*ap);
	printf("Address of m : %p\n",ap); //address of m which ap point it
	printf("Value of m : %d\n",m);




	return EXIT_SUCCESS;
}
