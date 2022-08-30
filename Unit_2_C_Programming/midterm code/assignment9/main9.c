/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
#include<string.h>
void rev_string(char arr[],int Size);
void main()
{
char a[20];
printf("enter the string\n");
fflush(stdin);
fflush(stdout);
gets(a);
fflush(stdout);
rev_string(a,strlen(a));

}
void rev_string(char arr[],int Size)
{
	int i=0,j=0,b[20],x=0;
	//skip the elements until i get ' '
	while(arr[i]!=' ')
	{
		i++;
	}
	//move the second word into the array
	for(;i<Size;i++)
	{
		b[j]=arr[i+1];
		j++;
	}
	//move the frist word after the second word
	for(i=j;i<Size;i++)
	{
		b[i]=arr[x];
		x++;
	}
	for(i=0;i<Size;i++)
	{
		printf("%c",b[i]);
	}

}
