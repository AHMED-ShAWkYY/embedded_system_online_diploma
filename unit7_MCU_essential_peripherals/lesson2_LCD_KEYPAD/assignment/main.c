 

#include "LCD/lcd.h"
#include "avr/delay.h"
#include "keypad_driver/keypad.h"
 char a[4][4]={
	{'7','4','1','c'},
	{'8','5','2','0'},
	{'9','6','3','='},
	{'/','*','-','+'}
};
int main()
{
	LCD_init();
	keypad_init();
	_delay_ms(20);
	 char pressed_key;
	while(1)
	{
		pressed_key=keyoad_getchar();
		switch(pressed_key)
		{
			case ('!'):
			LCD_Clear_Screen();
			break;
			case ('N'):
			break;
			default:
			LCD_WRITE_CHAR(pressed_key);
			break;
		}
	}
	}