/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
void pr_reverse_sentence(char arr[],int length);
void main()
{
char a[20];
printf("enter a sentence");
fflush(stdin);
fflush(stdout);
gets(a);
pr_reverse_sentence(a,strlen(a));
}

void pr_reverse_sentence(char arr[],int length)
{

if(length-->0)
{
	printf("%c",arr[length]);
	pr_reverse_sentence(arr,length);
}
}
