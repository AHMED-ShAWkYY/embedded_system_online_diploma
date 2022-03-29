/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
float a;
printf("enter a number : ");
fflush(stdin);
fflush(stdout);
scanf("%f",&a);
if(a>0)
{
	printf("%f is positive",a);
}

else if(a<0)
{
	printf("%f is negative",a);
}
else
{
	printf("you entered zero");
}
}

