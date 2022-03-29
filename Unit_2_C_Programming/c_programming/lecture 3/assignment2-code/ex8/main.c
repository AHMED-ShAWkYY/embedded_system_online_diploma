/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
char operator;
float x,y;
printf("enter operator either + or - or * : ");
fflush(stdout);
fflush(stdout);
scanf("%c",&operator);
printf("enter two operands: ");
fflush(stdout);
fflush(stdout);
scanf("%f %f",&x,&y);
/* ascii value for '*' =42 ,ascii value for '+' =43 ,ascii value for '-' =45 */
switch(operator)
{
case 42:
	printf("%.2f*%.2f=%.2f",x,y,x*y);
	break;
case 43:
	printf("%.2f+%.2f=%.2f",x,y,x+y);
	break;
case 45:
	printf("%.2f-%.2f=%.2f",x,y,x-y);
	break;
default:
	printf("you chosed wrong operation");
	break;
}
}
