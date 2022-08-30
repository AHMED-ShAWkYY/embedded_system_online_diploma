
#ifndef FIFO_H_
#define FIFO_H_
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include <stdlib.h>
#define DPRINTF(...)  fflush(stdout);\
					  fflush(stdin);\
					  printf(__VA_ARGS__);\
					  fflush(stdout);\
					  fflush(stdin);
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#define element_type struct sinfo
typedef struct
{
	element_type* FIFO_base;
	element_type*FIFO_head;
	element_type* FIFO_tail;
	unsigned int FIFO_count;
	unsigned int FIFO_length;
}FIFO_buf_t;
typedef struct sinfo
{
char fristname[50];
char secondname[50];
int roll ;
float GPA;
int cid[10];
}student_t;

typedef enum {
	FIFO_null,
	FIFO_empty,
	FIFO_full,
	FIFO_no_error,
	FIFO_error
}FIFO_status;
//API'
FIFO_status FIFO_init(FIFO_buf_t*FIFO_P,element_type *P_buf,unsigned int length);
int check_dubicated_rollnumber(FIFO_buf_t*FIFO_P,int num);
FIFO_status Get_data_from_file(FIFO_buf_t*FIFO_P);
FIFO_status add_element_manually(FIFO_buf_t*FIFO_P);
FIFO_status find_the_Student_by_rollnumber(FIFO_buf_t*FIFO_P);
FIFO_status find_the_Student_by_firstname(FIFO_buf_t*FIFO_P);
FIFO_status find_Students_registered_in_same_course(FIFO_buf_t*FIFO_P);
FIFO_status print_number_of_students_in_system(FIFO_buf_t*FIFO_P);
FIFO_status delete_a_student(FIFO_buf_t*FIFO_P);
FIFO_status update_student(FIFO_buf_t*FIFO_P);
FIFO_status display_all_informations(FIFO_buf_t*FIFO_P);



#endif
