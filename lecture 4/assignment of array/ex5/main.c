/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
int a[10],element,n,i,location;
printf("enter the no of elements in the array \n");
fflush(stdin);
fflush(stdout);
scanf("%d",&n);
printf("enter the elements \n");
for(i=0;i<n;i++)
{
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&a[i]);
}
printf("enter the element to search about :");
fflush(stdin);
fflush(stdout);
scanf("%d",&element);
for(i=0;i<n;i++)
{
	if(a[i]==element)
	{
	printf("number found at the location =%d ",i+1);
	break;
	}
}
if(i==n)
{
	printf("element is not exist");
}

}
