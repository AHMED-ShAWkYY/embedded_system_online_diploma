/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
//Write a program in C to print all the alphabets using a pointer. 
#include<stdio.h>
#include<string.h>

void main()
{
int i;
char c='A';
char *p=&c;
printf("the alphapets are : \n");
for(i=0;i<26;i++,c++)
{
printf("%c  ",*p);
}

}
