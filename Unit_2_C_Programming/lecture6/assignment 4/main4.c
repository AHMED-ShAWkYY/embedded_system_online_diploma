/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
// cprogram to store information of students using structures
#include<stdio.h>
#include<string.h>
struct Sstudent
{
	char name[20];
	int roll ;
	float marks;
};
void print(struct Sstudent x[],int size);
void main()
{
struct Sstudent s[10];
int i;
printf("enter information of student \n");
fflush(stdin);
fflush(stdout);
for(i=0;i<10;i++)
{
s[i].roll=i+1;
printf("for roll number %d\n",i+1);
fflush(stdin);
fflush(stdout);
printf("enter name: ");
fflush(stdin);
fflush(stdout);
gets(s[i].name);
printf("enter marks: ");
fflush(stdin);
fflush(stdout);
scanf("%f",&s[i].marks);
}
print(s,10);
}
void print(struct Sstudent x[],int size)
{
	int i;
	printf("displaying information of students\n");
	for(i=0;i<size;i++)
	{
		printf("information for roll number %d:\nname:%s\nmarks:%f\n",x[i].roll,x[i].name,x[i].marks);
	}
}
