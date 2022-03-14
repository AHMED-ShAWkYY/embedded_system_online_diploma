/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
int num;
printf("enter an integar you want to check : ");
fflush(stdout);
scanf("%d",&num);
if(num%2==0)
{
	printf("%d is even",num);
}
else
{
	printf("%d is odd",num);
}
}

