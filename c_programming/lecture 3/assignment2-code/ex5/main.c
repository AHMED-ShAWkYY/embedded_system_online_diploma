/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
char character;
printf("enter a charcter : ");
fflush(stdout);
fflush(stdout);
scanf("%c",&character);
if((character>=97&&character<=122)||(character>=65&&character<=90))
{
	printf("%c is alphapet",character);
}
else
{
	printf("%c is not alphapet",character);
}
}

