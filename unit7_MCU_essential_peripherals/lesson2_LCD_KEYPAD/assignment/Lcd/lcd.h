

#ifndef LCD_H_
#define LCD_H_
#define F_CPU 1000000UL
#include "avr/io.h"
#include "avr/delay.h"
#define lcd_port PORTA
#define lcd_port_datadir DDRA
#define lcd_ctrl PORTB
#define lcd_port_ctrldir DDRB
#define rs 1 
#define rw 2
#define enable 3
#define eight_BIT_MODE 
//#define four_BIT_MODE
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

void LCD_init();
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char data);
void LCD_WRITE_STRING(unsigned char *data);
void LCD_is_busy(void);
void LCD_Clear_Screen(void);
void LCD_GO_TO_XY(int line ,int position);

#endif /* LCD_H_ */