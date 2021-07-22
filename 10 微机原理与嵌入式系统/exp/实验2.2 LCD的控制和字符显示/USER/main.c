#include "stm32f4xx.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "12864.h"

uint8_t ImageData[]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x07,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x7F,0x80,0x00,0x00,0x00,0x00,0x18,0x0C,0x00,0x00,0x01,0x00,0x00,0x00,0x00,
0x01,0xFF,0x80,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x13,0x10,0x03,0xFE,0x00,
0x03,0xFF,0xC0,0x00,0x00,0x00,0x00,0x58,0x00,0x00,0x00,0x3F,0x30,0x1F,0xFF,0xC0,
0x03,0xFF,0xE0,0x00,0x00,0x00,0x00,0x8C,0x03,0xF0,0x00,0x7F,0xE0,0x7C,0x01,0xE0,
0x03,0xFF,0xF0,0x00,0x00,0x00,0x01,0x36,0x06,0xC0,0x00,0x5F,0xC0,0xFF,0xFC,0x60,
0x01,0xFF,0xF0,0x00,0x00,0x00,0x02,0x1B,0x0F,0x80,0x00,0xFF,0x01,0xFE,0x0F,0x30,
0x00,0xEF,0xF0,0x00,0x00,0x00,0x02,0x6D,0x9F,0x00,0x00,0x3E,0x03,0xFF,0xF1,0x90,
0x00,0xFF,0xF8,0x00,0x00,0x00,0x04,0x36,0xFE,0x00,0x01,0xFF,0x07,0xFF,0xFC,0x90,
0x00,0xEF,0xFF,0xFF,0x80,0x00,0x04,0xDB,0x7E,0x00,0x03,0xFF,0x87,0xFF,0xFC,0xD0,
0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x04,0x6D,0xFC,0x00,0x07,0xFF,0x8F,0xFF,0xFE,0x50,
0x00,0x0F,0xFF,0xFF,0xE0,0x00,0x04,0x36,0xFC,0x10,0x07,0xFF,0x8F,0xFF,0xFE,0x90,
0x00,0x0F,0xFF,0xFF,0xE0,0x00,0x04,0x1B,0xF8,0x10,0x07,0xFF,0xCF,0xFF,0xFE,0x80,
0x00,0x0F,0xFF,0xFF,0xF0,0x00,0x04,0x0F,0xF8,0x10,0x07,0xFF,0xFF,0xFF,0xFA,0x00,
0x00,0x07,0xFF,0xFF,0xF0,0x00,0x04,0x07,0xF0,0x10,0x07,0xFF,0xFF,0xFF,0xFA,0x00,
0x00,0xFF,0xFF,0xFF,0xF8,0x00,0x02,0x03,0xF0,0x20,0x07,0xFF,0xFF,0xFF,0xBA,0x00,
0x00,0xFD,0xFF,0xFF,0xFC,0x00,0x02,0x03,0xF0,0x20,0x03,0xFF,0xFF,0xDF,0xB8,0x00,
0x00,0xC1,0xC0,0x3F,0xFC,0x00,0x01,0x01,0xE0,0x40,0x00,0xFF,0xFF,0xDF,0xB0,0x00,
0x00,0x81,0xC0,0x3F,0xCE,0x00,0x00,0x81,0xE0,0x80,0x00,0x7F,0xFF,0xDF,0xA0,0x00,
0x00,0x81,0x80,0x1D,0xCF,0x00,0x00,0x41,0xE1,0x00,0x00,0x3F,0xFF,0x9B,0x00,0x00,
0x01,0x83,0x80,0x1F,0xC7,0x80,0x00,0x21,0xE2,0x00,0x00,0x1F,0xFD,0xB6,0x00,0x00,
0x01,0xC3,0x00,0x0E,0xE6,0x80,0x00,0x19,0xEC,0x00,0x00,0x07,0xFE,0x20,0x00,0x00,
0x00,0xC3,0x00,0x07,0x67,0x40,0x00,0x07,0xF0,0x00,0x00,0x03,0x3E,0x00,0x00,0x00,
0x00,0x02,0x00,0x03,0xE7,0xA0,0x00,0x00,0x00,0x00,0x00,0x02,0x8E,0x00,0x00,0x00,
0x00,0x06,0x00,0x03,0x83,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x03,0x00,0x00,0x00,
0x00,0x06,0x00,0x07,0x03,0x00,0x77,0x46,0x74,0x24,0x80,0x06,0x04,0x00,0x00,0x00,
0x00,0x1C,0x00,0x06,0x00,0x00,0x55,0x45,0x54,0x57,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x1C,0x00,0x0E,0x00,0x00,0x45,0x45,0x74,0x57,0x80,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1C,0x00,0x00,0x55,0x45,0x44,0x74,0x80,0xF0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x38,0x00,0x00,0x77,0x76,0x47,0x54,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; //128X32

int main()
{
	delay_init(168);
	LCD_GPIO_Init();
	LCD_Init();
	
	
	LCD_Display_Picture(ImageData);  
	delay_ms(1000);    
	LCD_Clear();	
	while(1)
	{
		LCD_Display_Words(0,0,(uint8_t*)"红专并进");
		LCD_Display_Words(1,0,(uint8_t*)"理实交融");
	}
}
