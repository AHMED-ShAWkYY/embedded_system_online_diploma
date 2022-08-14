

#include "lcd.h"
#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"
GPIO_Pin_config_t PIN_Config;
void wait (int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<255;j++)
		{
		}
	}
}
void LCD_Clear_Screen(void)
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void LCD_ENABLE()
{
	//		lcd_ctrl&=~(1<<enable);
	MCAL_GPIO_write_Pin(lcd_ctrl,enable, GPIO_Pin_SET);
							wait(50);
	MCAL_GPIO_write_Pin(lcd_ctrl,enable, GPIO_Pin_RESET);
}
void LCD_is_busy(void)
{
	//	lcd_port_datadir=0x0;
	PIN_Config.GPIO_Pin_number=GPIO_PIN_0;
	PIN_Config.GPIO_mode_define=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_1;
	PIN_Config.GPIO_mode_define=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_2;
	PIN_Config.GPIO_mode_define=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_3;
	PIN_Config.GPIO_mode_define=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_4;
	PIN_Config.GPIO_mode_define=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_5;
	PIN_Config.GPIO_mode_define=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_6;
	PIN_Config.GPIO_mode_define=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_7;
	PIN_Config.GPIO_mode_define=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	//	lcd_ctrl|=1<<rw;
	MCAL_GPIO_write_Pin(GPIOA, rw, GPIO_Pin_SET);
	//	lcd_ctrl&=~(1<<rs);
	MCAL_GPIO_write_Pin(GPIOA, rs, GPIO_Pin_RESET);
	LCD_ENABLE(); 
	//	lcd_port_datadir=0xff;
	//	lcd_ctrl&=~(1<<rw);
	MCAL_GPIO_write_Pin(GPIOA, rw, GPIO_Pin_RESET);
}

void LCD_init()
{
	wait(20);
	LCD_is_busy();
	//	lcd_port_ctrldir|=(1<<enable)|(1<<rs)|(1<<rw);
	PIN_Config.GPIO_Pin_number=rs;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=rw;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=enable;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	//	lcd_port_datadir=0xff;
	PIN_Config.GPIO_Pin_number=GPIO_PIN_0;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA,&PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_1;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_2;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_3;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_4;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_5;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_6;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_7;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	MCAL_GPIO_INIT(GPIOA, &PIN_Config);
	MCAL_GPIO_write_Pin(GPIOA,enable,GPIO_Pin_RESET);
	MCAL_GPIO_write_Pin(GPIOA,rw,GPIO_Pin_RESET);
	MCAL_GPIO_write_Pin(GPIOA,rs,GPIO_Pin_RESET);
	wait(15);
	LCD_Clear_Screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);


};
void LCD_WRITE_COMMAND(unsigned char command)
{
//	LCD_is_busy();
//	lcd_port=command;
	MCAL_GPIO_write_Port(lcd_ctrl,command);
//	lcd_ctrl&=~(1<<rs);
	MCAL_GPIO_write_Pin(lcd_ctrl, rs, GPIO_Pin_RESET);
//	lcd_ctrl&=~(1<<rw );
	MCAL_GPIO_write_Pin(lcd_ctrl, rw, GPIO_Pin_RESET);
	wait(1);
	LCD_ENABLE();


}
void LCD_WRITE_CHAR(unsigned char data)
{
//	lcd_ctrl|=(1<<rs);
	//MCAL_GPIO_write_Pin(lcd_ctrl, rs , GPIO_Pin_SET);
//	LCD_is_busy();
//	lcd_port=data;
	MCAL_GPIO_write_Port(lcd_ctrl, data);
//	lcd_ctrl&=~(1<<rw );
	MCAL_GPIO_write_Pin(lcd_ctrl, rw, GPIO_Pin_RESET);
//	lcd_ctrl|=(1<<rs);
	MCAL_GPIO_write_Pin(lcd_ctrl, rs , GPIO_Pin_SET);
	wait(1);
	LCD_ENABLE();

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
void LCD_WRITE_STRING( char *data)
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
