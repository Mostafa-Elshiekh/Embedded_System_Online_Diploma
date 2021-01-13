/*
 ============================================================================
 Name        : EX3_reverse_sentence_recursion.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char arr[],int start,int end);
/*parameters: arr[] base address ,start=0,end which length of array
 *function  : reverse sentence by recursion using swap the char
 *return    : the the factorial  */

int main(void)
{
	char arr[50];
	printf("Enter a sentence: ");
	fflush(stdin);fflush(stdout);
	gets(arr); //scanning the string
	reverse(arr,0,strlen(arr));
	return EXIT_SUCCESS;
}

void reverse(char arr[],int start,int end)
{
    char temp;
	if (end<=start)        //the condition to stop the recursion
	{
		printf("%s",arr);  //print the array after the reverse
	}
	else
	{   //swap the start index with end index
		temp=arr[start];
		arr[start]=arr[end-1];
		arr[end-1]=temp;
		start++;                  //increment the start
		end--;                   //decrement the end
		reverse(arr,start,end);  //recursion by new values of indexes
	}
}

