#define width 3
typedef struct
{
	char FirstName[20];
	char LastName[20];
	int ID;
	float GPA;
	int CoursesResgisterd[5];
}SStudent_Info;


/*determine type of array with same of type of element*/
SStudent_Info student_buffer[width];

/*FIFO data type*/
typedef struct
{

	unsigned int length;
	unsigned int count;
	SStudent_Info* base;
	SStudent_Info* head;
	SStudent_Info* tail;
}FIFO_Buf_t;



typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_Buf_status;


FIFO_Buf_status FIFO_is_full(FIFO_Buf_t* fifo);
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo ,SStudent_Info* buf,unsigned int length);
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,SStudent_Info *item);
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo,SStudent_Info* item);
int add_student_file(FIFO_Buf_t*fifo,SStudent_Info* item);
void FIFO_print(FIFO_Buf_t* fifo);
int CountOFStudent(FIFO_Buf_t* fifo);
int Find_The_Student_By_FirstName(FIFO_Buf_t* fifo,SStudent_Info *pStudent);
int Find_The_Students_Registered_In_course(FIFO_Buf_t* fifo,SStudent_Info *pStudent);
int Delete_Student_By_ID(FIFO_Buf_t* fifo,SStudent_Info *pStudent);
int Updata_Student(FIFO_Buf_t* fifo,SStudent_Info *pStudent);

