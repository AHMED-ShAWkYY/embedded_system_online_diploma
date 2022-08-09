/*
 * keypad.c
 *
 * Created: 7/29/2022 2:52:50 PM
 *  Author: PC
 */ 

#include "keypad.h"
 char get_pressed[4][4]={
	{'7','4','1','c'},
		{'8','5','2','0'},
			{'9','6','3','='},
				{'/','*','-','+'}
};
char keypad_c[]={c0,c1,c2,c3};
char keypad_r[]={r0,r1,r2,r3};

void keypad_init()
{
	keypad_dir &=~ (1<<r0) | (1<<r1) | (1<<r2) | (1<<r3);
	keypad_dir |= (1<<c0) | (1<<c1) | (1<<c2) | (1<<c3);
	keypad_port = 0xff;
}

char keyoad_getchar()
{
	int i , j ;
	for(i=0;i<=3;i++)
	{
		keypad_port |= (1<<keypad_c[0]) | (1<<keypad_c[1]) | (1<<keypad_c[2]) | (1<<keypad_c[3]);
		keypad_port &=~ (1<<keypad_c[i]);
		for(j=0;j<=3;j++)
		{
			if(!(keypad_input & (1<<keypad_r[j])))
			{
				while(!(keypad_input & (1<<keypad_r[j])));
				switch(i)
				{
					case(0):
					if(j==0) return '7';
					else if(j==1) return '4';
					else if(j==2) return '1';
					else if(j==3) return '!';
					break;
					case(1):
					if(j==0) return '8';
					else if(j==1) return '5';
					else if(j==2) return '2';
					else if(j==3) return '0';
					break;
					case(2):
					if(j==0) return '9';
					else if(j==1) return '6';
					else if(j==2) return '3';
					else if(j==3) return '0';
					break;
					case(3):
					if(j==0) return '/';
					else if(j==1) return '*';
					else if(j==2) return '-';
					else if(j==3) return '+';
					break;
				}
			}
		}
	}
	return 'N';
	
}
