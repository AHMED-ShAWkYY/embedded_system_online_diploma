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
for(i=0;i<n;i++)
{
	a[i]=i+1;
}
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf("\nenter the element to be inserted :");
fflush(stdin);
fflush(stdout);
scanf("%d",&element);
printf("enter the location");
fflush(stdin);
fflush(stdout);
scanf("%d",&location);
for(i=n;i>=0;i--)
{
	a[i]=a[i-1];
	if(i==location)
	{
		a[location-1]=element;
		break;
	}
}
for(i=0;i<=n;i++)
{
printf("%d ",a[i]);
}
}
