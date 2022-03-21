/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
void reverse_digits(int x);
void main()
{
int number;
printf("enter the number: ");
fflush(stdin);
fflush(stdout);
scanf("%d",&number);
reverse_digits(number);
}
void reverse_digits(int x)
{
int num,a[10],i=0,size,number=0,digit=1;
num=x;
while(num>0)
{
	 a[i]=num%10;
	num=num/10;
	i++;
}
size=i;
for(i=size-1;i>=0;i--)
{
	number+=a[i]*digit;
	digit=digit*10;
}
printf("output=%d",number);
}

