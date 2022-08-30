/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
void rev_array(int arr[],int Size);
void main()
{
int a[5]={1,2,3,4,5};
fflush(stdin);
fflush(stdout);
rev_array(a,5);

}
void rev_array(int arr[],int Size)
{
int b[10],i;
for(i=0;i<Size;i++)
{
	b[Size-1-i]=arr[i];
}
for(i=0;i<Size;i++)
{
printf("%d ",b[i]);
}
}
