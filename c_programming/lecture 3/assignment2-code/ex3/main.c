/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
float a,b,c;
printf("enter three numbers : ");
fflush(stdin);
fflush(stdout);
scanf("%f %f %f",&a,&b,&c);
if(a>b&&a>c)
{
	printf("largest number is %f",a);
}
else if (b>a&&b>c)
{
	printf("largest number is %f",b);
}
else
{
	printf("largest number is %f",c);
}
}

