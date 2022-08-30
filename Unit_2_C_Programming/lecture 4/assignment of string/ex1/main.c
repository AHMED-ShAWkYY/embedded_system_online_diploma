/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
char text[100],character;
int i=0,frequency=0;
printf("enter a string \n");
fflush(stdin);
fflush(stdout);
gets(text);
printf("enter a character to find frequency \n");
fflush(stdin);
fflush(stdout);
scanf("%c",&character);
while(text[i]!=0)
{
	if(text[i]==character)
	{
		frequency++;
	}
	i++;
}
printf("frequency of %c = %d",character,frequency);
}
