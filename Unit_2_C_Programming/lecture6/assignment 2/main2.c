/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
//c program to add two distances (in inch-feet )using structures
#include<stdio.h>
#include<string.h>
struct Sdistance
{
	int feet;
	float inch;
};
struct Sdistance add_distances(struct Sdistance x,struct Sdistance y);
void main()
{
struct Sdistance d1,d2,p;
printf("enter information for 1st distance \n");
fflush(stdin);
fflush(stdout);
printf("enter feet: ");
fflush(stdout);
scanf("%d",&d1.feet);
printf("enter roll: ");
fflush(stdout);
scanf("%f",&d1.inch);
printf("enter information for 2nd distance \n");
fflush(stdin);
fflush(stdout);
printf("enter feet: ");
fflush(stdout);
scanf("%d",&d2.feet);
printf("enter roll: ");
fflush(stdout);
scanf("%f",&d2.inch);
p=add_distances(d1,d2);
printf("sum of distances=%d+%.2f",p.feet,p.inch);
}
struct Sdistance add_distances(struct Sdistance x,struct Sdistance y)
{
	struct Sdistance sum;
	sum.feet=x.feet+y.feet;
	sum.inch=(x.inch+y.inch);
	while(sum.inch>12)
	{
		sum.feet++;
		sum.inch=sum.inch-12;
	}
	return sum;
}
