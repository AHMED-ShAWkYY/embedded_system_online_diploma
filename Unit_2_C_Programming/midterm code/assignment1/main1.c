/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
void sum_digits(int x);
void main()
{
int number;
printf("enter the number: ");
fflush(stdin);
fflush(stdout);
scanf("%d",&number);
sum_digits(number);
}
void sum_digits(int x)
{
int num,a[10],i=0,size,sum=0;
num=x;
while(num>0)
{
	 a[i]=num%10;
	num=num/10;
	i++;
}
size=i;
for(i=0;i<size;i++)
{
	sum+=a[i];
}
printf("sum-=%d",sum);
}
