/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
//Write a program in C to show a pointer to an array which contents are pointer to structure.
#include<stdio.h>
#include<string.h>
struct Semployee
{
	char name[10];
	int id;
};

void main()
{
	int i;
	struct Semployee emp1={"ahmed",100};
	struct Semployee emp2={"mohamed",200};
	struct Semployee emp3={"mahmoud",300};
	struct Semployee *arr[3]={&emp1,&emp2,&emp3};
	struct Semployee *(*p)[3]=arr;
	for(i=0;i<3;i++)
	{
	printf("employee%d name:%s\n",i+1,(*(*p+i))->name);
	printf("employee%d id:%d\n",i+1,(*(*p+i))->id);
	}
}
