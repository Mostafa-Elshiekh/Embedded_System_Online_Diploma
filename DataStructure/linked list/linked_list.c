#include "linked_list.h"


void AddStudent()
{
	struct SStudent* pNewStudent;
	/*struct SStudent* pLastStudent;*/
	char temp_next[40];
	/*check if list is empty*/
	if(gpFirstStudent==NULL)
	{
		/*create new student*/
		pNewStudent=(struct SStudent*) malloc (sizeof(struct SStudent));

		/*assign it to gdpFirstStudent*/
		gpFirstStudent=pNewStudent;
	}
	else
	{
		/*navigate until reach to the last student*/
		struct SStudent* pLastStudent=gpFirstStudent;
		while(pLastStudent->PnextStudent)
			pLastStudent=pLastStudent->PnextStudent;
		/*create new student*/
		pNewStudent=(struct SStudent*) malloc (sizeof(struct SStudent));
		pLastStudent->PnextStudent=pNewStudent;
	}

	/*fill new record*/
	printf("\nEnter student ID: ");
	fflush(stdin);		fflush(stdout);
	gets(temp_next);
	pNewStudent->student.ID=atoi(temp_next);

	printf("\nEnter student name: ");
	fflush(stdin);		fflush(stdout);
	gets(pNewStudent->student.name);

	printf("\nEnter student height: ");
	fflush(stdin);		fflush(stdout);
	gets(temp_next);
	pNewStudent->student.height=atof(temp_next);

	/*set the next pointer (new student) null*/
	pNewStudent->PnextStudent=NULL;
}


int DelateStudent()
{
	char temp_text[40];
	unsigned int selected_id;

	/*get the selected id*/
	printf("\n enter the student id to be deleted: ");
	fflush(stdin);		fflush(stdout);
	gets(temp_text);
	selected_id=atoi(temp_text);


	/*list is not empty*/
	if(gpFirstStudent)
	{
		struct SStudent* pSelectedStudent=gpFirstStudent;
		struct SStudent* pPreviousStudent=NULL;

		/*loop on all records*/
		while(pSelectedStudent)
		{
			if(pSelectedStudent->student.ID == selected_id)
			{
				if(pPreviousStudent)
				{
					pPreviousStudent->PnextStudent=pSelectedStudent->PnextStudent;

				}
				else /*1st student==ID*/
				{
					gpFirstStudent=pSelectedStudent->PnextStudent;

				}
				free(pSelectedStudent);
				return 1;
			}
			pPreviousStudent=pSelectedStudent;
			pSelectedStudent=pSelectedStudent->PnextStudent;
		}
		printf("\n cannot find student ID :");
		return 0;

	}
}


void View_student()
{
	struct SStudent* pCurrentStudent=gpFirstStudent;
	int count=0;

	if(gpFirstStudent == NULL)
		printf("\n Empty list ");
	else
	{
		while(pCurrentStudent)
		{
			printf("\n record number %d ",count+1);
			printf("\n \t ID: %d ",pCurrentStudent->student.ID);
			printf("\n \t name: %s ",pCurrentStudent->student.name);
			printf("\n \t height: %f ",pCurrentStudent->student.height);
			pCurrentStudent=pCurrentStudent->PnextStudent;
			count++;
		}
	}
}

void DeleteAll()
{
	struct SStudent* pCurrentStudent=gpFirstStudent;
	if(gpFirstStudent==NULL)
	{
		printf("\n Empty list ");
	}
	else
	{
		while(pCurrentStudent)
		{
			struct SStudent* pTempStudent=pCurrentStudent;
			pCurrentStudent=pCurrentStudent->PnextStudent;
			free(pTempStudent);
		}
		gpFirstStudent=NULL;
	}

}

void PrintOneStudentByIndex()
{
	int count=0;
	int index;
	printf("\n enter idex to print this student  ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&index);

	struct SStudent* pCurrentStudent=gpFirstStudent;

	while(pCurrentStudent)
	{
		if(count==index)
		{
			printf("\n \t ID: %d ",pCurrentStudent->student.ID);
			printf("\n \t name: %s ",pCurrentStudent->student.name);
			printf("\n \t height: %f ",pCurrentStudent->student.height);
			break;
		}

		else
		{
			pCurrentStudent=pCurrentStudent->PnextStudent;
			count++;
		}
	}

}


void FindLengthOfList()
{
	int length=0;
	struct SStudent *pCurrentStudent=gpFirstStudent;

	while(pCurrentStudent)
	{
		pCurrentStudent=pCurrentStudent->PnextStudent;
		length++;
	}
	printf("\n length of list is %d",length);
}

int FindLengthOfListRecursive(gpFirstStudent)
{
	struct SStudent * pCurrentStudent=gpFirstStudent;

	if(pCurrentStudent==NULL)
	{
		return 0;
	}
	else
	{
		pCurrentStudent=pCurrentStudent->PnextStudent;
		return 1+ FindLengthOfListRecursive(pCurrentStudent);
	}

}

void PrintNodeFromEnd()
{

	int count=0;
	int index;

	if(gpFirstStudent==NULL)
	{
		printf("\nList is empty\n");
		return 0;
	}

	printf("\n enter idex to print this student  ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&index);

	struct SStudent* pCurrentStudent=gpFirstStudent;



	while(pCurrentStudent)
	{
		if(index==(FindLengthOfListRecursive(gpFirstStudent)-count))
		{
			printf("\n \t ID: %d ",pCurrentStudent->student.ID);
			printf("\n \t name: %s ",pCurrentStudent->student.name);
			printf("\n \t height: %f ",pCurrentStudent->student.height);
			break;
		}

		else
		{
			pCurrentStudent=pCurrentStudent->PnextStudent;
			count++;
		}
	}

}

void PrintNodeFromEndBy2Bointer()
{
	struct SStudent* pStart =gpFirstStudent;
	struct SStudent* pEnd =gpFirstStudent;

	int index,i;
	printf("\n enter idex to print this student  ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&index);

	for(i=0;i<index;i++)
	{
		pEnd=pEnd->PnextStudent;
	}

	while(pEnd)
	{
		pStart=pStart->PnextStudent;
		pEnd=pEnd->PnextStudent;
	}

    
	printf("\n \t ID: %d ",pStart->student.ID);
	printf("\n \t name: %s ",pStart->student.name);
	printf("\n \t height: %f ",pStart->student.height);
}

void ReverseList()
{
	struct SStudent* pStart =gpFirstStudent;
	struct SStudent* pEnd =gpFirstStudent;

	while(pEnd)
	{
		pEnd=pEnd->PnextStudent;
	}
	gpFirstStudent=pEnd;
	
}
