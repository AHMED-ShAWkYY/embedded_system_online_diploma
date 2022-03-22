/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
//cprogram to store information(name,roll and marks)
#include<stdio.h>
#include<string.h>
struct Sstudent
{
	char name[20];
	int roll ;
	float marks;
};
void print(struct Sstudent x);
void main()
{
struct Sstudent student;
printf("enter information of student \n");
fflush(stdin);
fflush(stdout);
printf("enter name: ");
fflush(stdout);
gets(student.name);
printf("enter roll: ");
fflush(stdout);
scanf("%d",&student.roll);
printf("enter marks: ");
fflush(stdout);
scanf("%f",&student.marks);
print(student);
}
void print(struct Sstudent x)
{
	printf("displaying information\n");
	printf("name: %s\nroll: %d\nmarks: %.1f\n ",x.name,x.roll,x.marks);
}
