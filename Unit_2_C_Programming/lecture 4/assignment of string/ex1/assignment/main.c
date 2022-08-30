/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
char text[100],length=0,i=0;
printf("enter a string \n");
fflush(stdin);
fflush(stdout);
gets(text);
while(text[i]!=0)
{
	i++;
	length++;
}
printf("length of a string = %d", length);
}
