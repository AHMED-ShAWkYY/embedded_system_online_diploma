/*
 * linked_list.h
 *
 *  Created on: ??ş/??ş/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
//the data of every student
#include<stdio.h>
#include<stdint.h>
#define DPRINTF(...)  fflush(stdout);\
					  fflush(stdin);\
					  printf(__VA_ARGS__);\
					  fflush(stdout);\
					  fflush(stdin);
struct Sdata
{
	char name[20];
	int id;
	float height;
};
//node that contains data of a student and pointer to next node
struct Sstudent
{
	struct Sdata student;
	struct Sstudent * p_Nextstudent;
};
//APIS OF LINKED LIST
void add_student(void);
int delete_student(void);
void view_all(void);
void delete_all(void);
int Get_nth(int index);
int Get_length(void);
int nodes_length(struct Sstudent *p_length);
int Get_nth_from_end(int index);
int find_middle(void);
void reverse_linkedlist(void);
#endif /* LINKED_LIST_H_ */
