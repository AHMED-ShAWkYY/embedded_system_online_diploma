/*
 * keypad.c
 *
 *  Created on: Aug 9, 2022
 *      Author: PC
 */



#include "keypad.h"
GPIO_Pin_config_t PIN_Config;
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
	//keypad_dir &=~ (1<<r0) | (1<<r1) | (1<<r2) | (1<<r3);
	PIN_Config.GPIO_Pin_number=r0;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(keypad_port,&PIN_Config);
	PIN_Config.GPIO_Pin_number=r1;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(keypad_port,&PIN_Config);
	PIN_Config.GPIO_Pin_number=r2;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(keypad_port,&PIN_Config);
	PIN_Config.GPIO_Pin_number=r3;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(keypad_port,&PIN_Config);
	PIN_Config.GPIO_Pin_number=c0;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(keypad_port,&PIN_Config);
	PIN_Config.GPIO_Pin_number=c1;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(keypad_port,&PIN_Config);
	PIN_Config.GPIO_Pin_number=c2;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(keypad_port,&PIN_Config);
	PIN_Config.GPIO_Pin_number=c3;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(keypad_port,&PIN_Config);
	//keypad_dir |= (1<<c0) | (1 <<c1) | (1<<c2) | (1<<c3);
	//	keypad_port = 0xff;
	MCAL_GPIO_write_Port(keypad_port, 0xff);
}

char keyoad_getchar()
{
	int i , j ;
	for(i=0;i<=3;i++)
	{
		//		keypad_port |= (1<<keypad_c[0]) | (1<<keypad_c[1]) | (1<<keypad_c[2]) | (1<<keypad_c[3]);
		MCAL_GPIO_write_Pin(keypad_port,keypad_c[0], GPIO_Pin_SET);
		MCAL_GPIO_write_Pin(keypad_port,keypad_c[1], GPIO_Pin_SET);
		MCAL_GPIO_write_Pin(keypad_port,keypad_c[2], GPIO_Pin_SET);
		MCAL_GPIO_write_Pin(keypad_port,keypad_c[3], GPIO_Pin_SET);
		//		keypad_port &=~ (1<<keypad_c[i]);
		MCAL_GPIO_write_Pin(keypad_port,keypad_c[i], GPIO_Pin_RESET);
		for(j=0;j<=3;j++)
		{
			if(MCAL_GPIO_Read_Pin(keypad_port,keypad_r[j])==0)
			{
				while(MCAL_GPIO_Read_Pin(keypad_port,keypad_r[j])==0);
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
