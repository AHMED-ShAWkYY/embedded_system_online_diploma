/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
int i,num,fact=1;
printf("enter an integar : ");
fflush(stdout);
fflush(stdout);
scanf("%d",&num);
if(num>0)
{
	for(i=1;i<=num;i++)
{
		fact*=i;
}
	printf("fact = %d",fact);
}
else if(num<0)
{
	printf(("ERROR !! Factrial of negtive number is not exist"));
}
else
{
	printf("fact=%d",fact);

}
}

