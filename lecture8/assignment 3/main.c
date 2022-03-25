/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
//print a string in reverse using pointers
#include<stdio.h>
#include<string.h>

void main()
{
char str[20];
int i;
char *p;
printf("input a string \n");
fflush(stdout);
gets(str);
p=str+strlen(str)-1;
for(i=0;i<strlen(str);i++,p--)
{
printf("%c",*p);
}

}
