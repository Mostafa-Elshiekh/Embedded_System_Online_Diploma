
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



FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo ,SStudent_Info* buf,unsigned int length)
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


FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,SStudent_Info *item)
{

	//int *ptr=&item;
	int j=0;


	/*check if queue is valid ?*/
	if(!fifo->base || !fifo->head  || !fifo->tail)
		return FIFO_NULL;

	//check if queue is full ?
	if(FIFO_is_full(fifo)==FIFO_full)
		return FIFO_full;

	printf("\n===================\n");

	printf("\tEnter the first name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s",fifo->head->FirstName);



	printf("\tEnter the last name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s",fifo->head->LastName);

	printf("\tEnter the ID: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&fifo->head->ID);

	printf("\tEnter the GPA: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&fifo->head->GPA);

	printf("\tEnter the ID CoursesResgisterd\n ");
	fflush(stdin);fflush(stdout);
	for(j=0;j<5;j++)
	{
		printf("\tEntet the ID of the %d course: ",j+1);
		scanf("%d",&fifo->head->CoursesResgisterd[j]);
	}
	printf("===================\n");


	fifo->count++;

	/*circler fifo*/
	if(fifo->head == (fifo->base + (fifo->length * sizeof(SStudent_Info))))
		fifo->head=fifo->base;

	else
		fifo->head++;

	return FIFO_no_error;

}


FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo,SStudent_Info* item)
{

	/*check if queue is valid ?*/
	if(!fifo->base || !fifo->head  || !fifo->tail)
		return FIFO_NULL;

	/*check if queue is empty ?*/
	if(fifo->count==0)
	{
		printf("\n==================================\n");
		printf("The Queue Is Empty");
		printf("\n==================================\n");
		return 0;
	}

	/*dequeue data*/
	(item->ID)=(fifo->tail->ID);
	fifo->count--;
    
    printf("\n==========================================================\n");
	printf("FIFO DEQUEUE WHICH ID OF STUDENT IS %d-------->DONE :)\n",item->ID);
	printf("============================================================\n");
	/*circler fifo*/
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(SStudent_Info))))
		fifo->tail=fifo->base;

	else
		fifo->tail++;

	return FIFO_no_error;

}

int add_student_file(FIFO_Buf_t*fifo,SStudent_Info* item)                  // add students info using text file
{
	int i=0,j,count=0;

    /*check if queue is valid ?*/
	if(!fifo->base || !fifo->head  || !fifo->tail)
		printf("FIFO NULL");

	//check if queue is full ?
	if(FIFO_is_full(fifo)==FIFO_full)
	{
		printf("\n======================\n");
		printf("The Queue Is Full :(");
		printf("\n======================\n");
		return 0;
	}


	FILE *fp;
	char text[100];
	char* filename = "c:\\Users\\musta\\Desktop\\data.txt";

	fp = fopen(filename, "r");
	if (fp == NULL){
		printf("Could not open file %s",filename);
		return 1;
	}
	while (fgets(text, 100, fp) != NULL);


	// Extract the first token
	char * token = strtok(text," ");
	strcpy(item->FirstName,token);

	token = strtok(NULL, " ");

	strcpy(fifo->head->LastName,token);

	token = strtok(NULL, " ");

	fifo->head->ID=*(token)-32;

	token = strtok(NULL, " ");


	fifo->head->GPA=atof(token);


	token = strtok(NULL, " ");
	while( token != NULL )
	{
		//printf("%d\n",  ); //printing each token
		fifo->head->CoursesResgisterd[i]=atoi(token);
		token = strtok(NULL, " ");
		i++;
	}

     printf("\n==========================================\n");
     printf("input in Queue By File Has Been---------> Done");
     printf("\n==========================================\n");


	fifo->count++;

	/*circler fifo*/
	if(fifo->head == (fifo->base + (fifo->length * sizeof(SStudent_Info))))
		fifo->head=fifo->base;

	else
		fifo->head++;

	return 0;
}


void FIFO_print(FIFO_Buf_t* fifo)
{
	//SStudent_Info *temp;
	SStudent_Info *temp;
	int i;
	int j;

	/*if fifo is empty*/
	if(fifo->count==0)
	{
		printf("\n====================================\n");
		printf("fifo is empty\n");
		printf("======================================\n");

	}

	else
	{
		temp=fifo->tail;
		printf("\n========= Print All Students In The DataBase ===========\n");
		for(i=0;i<fifo->count;i++)
		{
			printf("\t the first name is: %s \n",temp->FirstName);
			printf("\t the last name is: %s \n",temp->LastName);
			printf("\t the ID is %d: \n",(temp->ID));
			printf("\t the GPA is %f : \n",(temp->GPA));
			for(j=0;j<5;j++)
			{
				printf("\t the ID of the %d course is: %d \n",j+1,(temp->CoursesResgisterd[j]));
			}
			printf("====================================\n");
			temp++;
		}
	}
}

int CountOFStudent(FIFO_Buf_t* fifo)
{
	return fifo->count;
}

int Find_The_Student_By_ID(FIFO_Buf_t* fifo,SStudent_Info *pStudent)
{
	int ID_Number;
	int i=0,j=0;
	pStudent=fifo->tail;
	printf("\nEnter The ID which Student You want it :");
	scanf("%d",&ID_Number);

	for(i=0;i<fifo->count;i++)
	{
		if(pStudent->ID==ID_Number)
		{
			printf("=====================================\n");
			printf("\t the first name is: %s \n",pStudent->FirstName);
			printf("\t the last name is: %s \n",pStudent->LastName);
			printf("\t the ID is %d: \n",(pStudent->ID));
			printf("\t the GPA is %f : \n",(pStudent->GPA));
			for(j=0;j<5;j++)
			{
				printf("\t the ID of the %d course is: %d \n",j+1,(pStudent->CoursesResgisterd[j]));
			}
			printf("====================================\n");
			return 0;
		}
		pStudent++;
	}
	printf("\n====================================\n");
	printf("This ID Not Found In DataBase :(\n");
	printf("====================================\n");
	return 0;

}

int Find_The_Student_By_FirstName(FIFO_Buf_t* fifo,SStudent_Info *pStudent)
{
	char FirstName[12];
	int i=0,j=0;
	pStudent=fifo->tail;
	printf("\nEnter The ID which Student You want it :");
	scanf("%s",FirstName);

	for(i=0;i<fifo->count;i++)
	{
		if(strcmp(pStudent->FirstName,FirstName)==0)
		{
			printf("====================================\n");
			printf("\t the first name is: %s \n",pStudent->FirstName);
			printf("\t the last name is: %s \n",pStudent->LastName);
			printf("\t the ID is %d: \n",(pStudent->ID));
			printf("\t the GPA is %f : \n",(pStudent->GPA));
			for(j=0;j<5;j++)
			{
				printf("\t the ID of the %d course is: %d \n",j+1,(pStudent->CoursesResgisterd[j]));
			}
			printf("====================================\n");
			return 0;
		}
		pStudent++;
	}
	printf("\n====================================\n");
	printf("This FirstName Not Found In The DataBase :(\n");
	printf("====================================\n");

	return 0;
}

int Find_The_Students_Registered_In_course(FIFO_Buf_t* fifo,SStudent_Info *pStudent)
{
	int flag=0;
	int Course_ID;
	int i=0,j=0,k=0;
	pStudent=fifo->tail;
	if(fifo->count==0)
	{
		printf("\n====================================\n");
		printf("fifo is empty\n");
		printf("======================================\n");
		return 0;

	}
	printf("\nEnter The Course ID: ");
	scanf("%d",&Course_ID);

	for(i=0;i<fifo->count;i++)
	{
		for(j=0;j<5;j++)
		{
			if(pStudent->CoursesResgisterd[j]==Course_ID)
			{
				printf("\n====================================\n");
				printf("\t the first name is: %s \n",pStudent->FirstName);
				printf("\t the last name is: %s \n",pStudent->LastName);
				printf("\t the ID is %d: \n",(pStudent->ID));
				printf("\t the GPA is %f : \n",(pStudent->GPA));
				for(k=0;k<5;k++)
				{
					printf("\t the ID of the %d course is: %d \n",k+1,(pStudent->CoursesResgisterd[k]));
				}
				printf("====================================\n");
				flag=1;
			}
			if(i==4)
				return 0;
		}
		pStudent++;

		//return 0;
	}
	if(flag==0)
	{
	printf("\n====================================\n");
	printf("This Course ID Not Exite :(\n");
	printf("====================================\n");

	}
	

	return 0;

}

int Delete_Student_By_ID(FIFO_Buf_t* fifo,SStudent_Info *pStudent)
{
	pStudent=fifo->tail;
	int i,j,Student_ID;
	int flag =0;

	if(fifo->count==0)
	{
		printf("\n====================================\n");
		printf("Fifo Is Empty\n");
		printf("======================================\n");
		return 0;

	}

	SStudent_Info *pNext=(fifo->tail)+1;

	printf("Enter Student ID To Delete It \n");
	scanf("%d",&Student_ID);

	for(i=0;i<fifo->count;i++)
	{
		if(pStudent->ID==Student_ID)
		{
			flag=1;
			*pStudent=*pNext;
			pNext++;
		}
		pStudent++;

	}
	if(flag==1)
	{
				printf("\n===============================\n");
				printf("Deleation has been ----------->Done");
				printf("\n===============================\n");

		(fifo->count)--;
		(fifo->head)--;
		return 0;
	}
	else
	{
		printf("This ID Not Exite In The Data Base :( \n");
		return 0;
	}
}

int Updata_Student(FIFO_Buf_t* fifo,SStudent_Info *pStudent)
{

	int Student_ID;
	int i,choise,j,Course_ID;
	if(fifo->count==0)
	{
		printf("\n====================================\n");
		printf("Fifo is empty\n");
		printf("======================================\n");
		return 0;

	}
	printf("\n================================\n");
	printf("Enter Student ID To Update It: ");
	scanf("%d",&Student_ID);

	for(i=0;i<fifo->count;i++)
	{
		if(pStudent->ID==Student_ID)
		{
			printf("1. First Name\n");
			printf("2. Last Name \n");
			printf("3. ID \n");
			printf("4. GPA \n");
			printf("5. Courses \n");
			printf("Chose What You Need Update It: ");
			scanf("%d",&choise);

			switch(choise)
			{
			case 1:
			{
				printf("Enter The New First Name: ");
				scanf("%s",pStudent->FirstName);
				break;
			}
			case 2:
			{
				printf("Enter The New Last Name: ");
				scanf("%s",pStudent->LastName);
				break;
			}
			case 3:
			{
				printf("Enter The New ID: ");
				scanf("%d",&pStudent->ID);
				break;
			}
			case 4:
			{
				printf("Enter The New GPA: ");
				scanf("%f",&pStudent->GPA);
				break;
			}
			case 5:
			{
				printf("Enter The ID Of The Course Which You Need Update It: ");
				scanf("%d",&Course_ID);
				for(j=0;j<5;j++)
				{
					if(pStudent->CoursesResgisterd[j]==Course_ID)
					{
						printf("Enter The New ID course: ");
						scanf("%d",&(pStudent->CoursesResgisterd[j]));
					}

				}
				break;
			}

			default:
			{
				printf("Wrong choise \n");
			}

			}
			printf("\n================================\n");
			return 0;
		}
		pStudent++;
		if(pStudent->ID!=Student_ID)
		{ 
			printf("\n====================================\n");
	        printf("This Course ID Not Exite :(\n");
	        printf("====================================\n");

		}
	}

}
