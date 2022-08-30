/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
char text[100];
int length,i,temp;
printf("enter a string    ");
fflush(stdin);
fflush(stdout);
gets(text);
length=strlen(text);
for(i=0;i<(length/2);i++)
{
temp=text[length-i-1];
text[length-i-1]=text[i];
text[i]=temp;
}
printf("reverse string is %s",text);
}
