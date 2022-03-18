/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
void print_prime(int start,int end);
void main()
{
int num1,num2;
printf("enter two numbers (intervals)");
fflush(stdin);
fflush(stdout);
scanf("%d %d",&num1,&num2);
print_prime(num1,num2);
}
void print_prime(int start,int end)
{
	int num,i,x=0,a[20],array=0;
	for(num=start;num<=end;num++)
	{
		for(i=1;i<=num;i++)
		{
			if(num%i==0)
				x++;
		}
		if(x==2)
		{
		a[array]=num;
		array++;
		}
		x=0;
	}
	printf("prime numbers between %d and %d are :",start,end);
	for(i=0;i<array;i++)
	{
		printf("%d ",a[i]);
	}
}
