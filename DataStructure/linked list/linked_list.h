#include <stdio.h>
#include <stdlib.h>

#ifndef linked_list_H_
#define linked_list_H_
/*data of student*/
struct Sdata
{
	int ID;
	char name[40];
	float height;
};

/*node*/
struct SStudent
{
	struct Sdata student;
	struct SStudent* PnextStudent;
};


/*global pointer to first element*/
struct SStudent* gpFirstStudent=NULL;

void AddStudent();
int DelateStudent();
void View_student();
void DeleteAll();
void PrintOneStudentByIndex();
void FindLengthOfList();
int FindLengthOfListRecursive(gpFirstStudent);
void PrintNodeFromEnd();
void PrintNodeFromEndBy2Bointer();
void ReverseList();

#endif