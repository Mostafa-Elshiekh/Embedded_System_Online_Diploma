/*
 ============================================================================
 Name        : LINKED_LIST_STUDENT.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "file.c"



int main(void)
{
	printf("\ndone\n");
	char temp_text[40];
	while(1)
	{
		printf("\n======================");
		fflush(stdin);		fflush(stdout);

		printf("\n\t choose the following options \n");
		fflush(stdin);		fflush(stdout);
		printf("\n 1:AddStudent ");
		fflush(stdin);		fflush(stdout);
		printf("\n 2:DeleteStudent ");
		fflush(stdin);		fflush(stdout);
		printf("\n 3:ViewStudent ");
		fflush(stdin);		fflush(stdout);
		printf("\n 4:DeleteAll ");
		fflush(stdin);		fflush(stdout);
		printf("\n 5:PrintOneStudentByIndex ");
		fflush(stdin);		fflush(stdout);
		printf("\n 6:FindLengthOfList ");
		fflush(stdin);		fflush(stdout);
		printf("\n 7:FindLengthOfListRecursive ");
		fflush(stdin);		fflush(stdout);
		printf("\n 8:PrintNodeFromEnd");
		fflush(stdin);		fflush(stdout);
		printf("\n 9:PrintNodeFromEndBy2Bointer  ");
		fflush(stdin);		fflush(stdout);
		printf("\n 10:end the programe  ");
		fflush(stdin);		fflush(stdout);




		gets(temp_text);
		printf("=====================");
		fflush(stdin);		fflush(stdout);

		switch (atoi(temp_text))
		{
		case 1:
			AddStudent();
			break;
		
		case 2:
			DelateStudent();
			break;

		case 3:
			View_student();
			break;
		case 4:
			DelateStudent();
			break;
		case 5:
			PrintOneStudentByIndex();
			break;
		case 6:
			FindLengthOfList();
			break;
		case 7:
			printf("\nlength of list is %d",FindLengthOfListRecursive(gpFirstStudent));
		    break;
		case 8:
		     PrintNodeFromEnd();
		     break;
		case 9:
		     PrintNodeFromEndBy2Bointer();
		     break;
		case 10:
		    return 0;
		default:
			printf("\n wrong option");
			break;
		}


	}
	return 0;
}
