/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
int sumnum(void);
void main()
{
int sum=0;
fflush(stdin);
fflush(stdout);
sum=sumnum();
printf("sum=%d",sum);
}
int sumnum(void)
{
static int number=0;
int y=0;
int sum=0;
number++;
y=number;
if(number<=100)
{
sum=y+sumnum();
}
else
{
	return 0;
}
return sum;
}
