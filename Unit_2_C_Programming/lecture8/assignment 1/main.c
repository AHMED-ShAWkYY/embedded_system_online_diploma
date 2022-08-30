/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
//Write a program in C to demonstrate how to handle the pointers in the program.
#include<stdio.h>
#include<string.h>

void main()
{
int m=29;
printf("address of m =%x\n",&m);
fflush(stdout);
printf("value of m =%d\n",m);
fflush(stdout);
int *ab=&m;
printf("now ab is assigned with the address of m\n");
fflush(stdout);
printf("address of pointer=%x\n",ab);
fflush(stdout);
printf("content of pointer=%d\n",*ab);
fflush(stdout);
m=34;
printf("the value of m is assigned to 34 now\n");
fflush(stdout);
printf("address of pointer=%x\n",ab);
fflush(stdout);
printf("content of pointer=%d\n",*ab);
fflush(stdout);
*ab=7;
printf("the pointer variable ab is assigned with value 7 now\n");
fflush(stdout);
printf("address of m=%x\n",&m);
fflush(stdout);
printf("content of m=%d\n",m);
fflush(stdout);

}
