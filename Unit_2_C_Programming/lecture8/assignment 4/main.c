/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
//print a string in reverse using pointers
#include<stdio.h>
#include<string.h>

void main()
{
int a[15],b[15];
int i,j,size;
int *p,*pp;
int count=0;
p=a;
pp=b;
printf("input the number of elements to store in the array (max 15) \n");
fflush(stdout);
scanf("%d",&size);
printf("input %d number of elements in the array\n",size);
for(i=0;i<size;i++,p++)
{
printf("enter element %d: ",i+1);
fflush(stdout);
scanf("%d",&a[i]);
}
while(count<size)
{
	p--;
	*pp=*p;
	count++;
	pp++;
}
printf("The elements of array in reverse order are :\n");
for(i=0,j=size;i<size;i++,j--)
{
printf("element - %d: %d\n",j,b[i]);
fflush(stdout);
}
}
