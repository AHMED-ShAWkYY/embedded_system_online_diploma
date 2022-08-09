

#include "lcd.h"
void LCD_Clear_Screen(void)
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void LCD_ENABLE()
{
		lcd_ctrl&=~(1<<enable);
		_delay_ms(30);
		lcd_ctrl|=(1<<enable);
}
void LCD_is_busy(void)
{
	lcd_port_datadir=0x0;  
	lcd_ctrl|=1<<rw; 
	lcd_ctrl&=~(1<<rs);
	LCD_ENABLE(); 
	lcd_port_datadir=0xff;
	lcd_ctrl&=~(1<<rw);

}

void LCD_init()
{
_delay_ms(20);
#ifdef eight_BIT_MODE
LCD_is_busy(); 
	lcd_port_ctrldir|=(1<<enable)|(1<<rs)|(1<<rw);
	lcd_ctrl&=~(1<<enable)|(1<<rw)|(1<<rs);
	lcd_port_datadir=0xff;
	LCD_Clear_Screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
#endif
#ifdef four_BIT_MODE
#endif

};
void LCD_WRITE_COMMAND(unsigned char command)
{
	#ifdef eight_BIT_MODE
	LCD_is_busy();
	lcd_port=command;
	lcd_ctrl&=~(1<<rs);
	lcd_ctrl&=~(1<<rw );
	LCD_ENABLE();
	#endif
	
	#ifdef four_BIT_MODE
	#endif 
	
}
void LCD_WRITE_CHAR(unsigned char data)
{
	#ifdef eight_BIT_MODE
		lcd_ctrl|=(1<<rs);
	LCD_is_busy();
	lcd_port=data;
	lcd_ctrl&=~(1<<rw );
	lcd_ctrl|=(1<<rs);
	LCD_ENABLE();
	#endif
	
	#ifdef four_BIT_MODE
	#endif	
}
void LCD_GO_TO_XY(int line ,int position)
{
	if(line==2)
	{
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);	
	}
	else if(line==1)
	{
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
	}
}
void LCD_WRITE_STRING(unsigned char *data)
{
	int count=0;
	while(*data>0)
	{
		if(count==16)
		{
			LCD_GO_TO_XY(2,0);
		}
		else if(count==32)
		{
			LCD_Clear_Screen();
			LCD_GO_TO_XY(1,0);
			count=0;
		}
	LCD_WRITE_CHAR(*data);
	data++;
	count++;	
	}	
}