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
printf("enter an alphapet : ");
fflush(stdout);
scanf("%c",&character);
if(character=='a'||character=='e'||character=='i'||character=='o'||character=='u')
{
	printf("%c is vowel",character);
}
else
{
	printf("%c is constant",character);
}
}

