#include "sys.h"
#include "delay.h"
#include "dip.h"
#include "sw.h"
#include "exti.h"
#include "led.h"
#include "lcd.h"

u8 mode=0;
u8 pswd=0;
u8 pswd_tmp=0;
u8 pswd_stat=0;

int main(void){
	delay_init(168);
	DIP_Init();
	SW_Init();
	EXTIX_Init();
	LED_Init();
	LCD_Init();
	LCD_Clear();
	LCD_Clear();
	LCD_Clear();
	LCD_Clear();
	LCD_Display_Words(0,0,(uint8_t*)"SW0|1 mode|hand");
	LCD_Display_Words(1,0,(uint8_t*)"DIP0-7 ipt pswd");
	LCD_Display_Words(2,0,(uint8_t*)"Default pswd:");
	LCD_Display_Words(3,0,(uint8_t*)"00000000");
	delay_ms(3000);
	LCD_Clear();
	LCD_Clear();
	LCD_Clear();
	LCD_Clear();
	while(1){
		LED0=DIP0;
		LED1=DIP1;
		LED2=DIP2;
		LED3=DIP3;
		LED4=DIP4;
		LED5=DIP5;
		LED6=DIP6;
		LED7=DIP7;
		if(mode%2==0){
			//working, input password
			if(pswd_stat==0){
				LCD_Display_Words(0,0,(uint8_t*)"Want open?");
				LCD_Display_Words(1,0,(uint8_t*)"Please ipt pswd");
				LCD_Display_Words(2,0,(uint8_t*)"Default pswd is");
				LCD_Display_Words(3,0,(uint8_t*)"00000000");
			}
			else if(pswd_stat==1){
				LCD_Display_Words(0,0,(uint8_t*)"Success!");
				LCD_Display_Words(1,0,(uint8_t*)"Welcome~~~");
			}
			else if(pswd_stat==2){
				LCD_Display_Words(0,0,(uint8_t*)"Want open?");
				LCD_Display_Words(1,0,(uint8_t*)"Try again!");
			}
		}
		else if(mode%2==1){
			//change password
			if(pswd_stat==0){
				LCD_Display_Words(0,0,(uint8_t*)"Change pswd?");
				LCD_Display_Words(1,0,(uint8_t*)"Please ipt pswd");
				LCD_Display_Words(2,0,(uint8_t*)"Default pswd is");
				LCD_Display_Words(3,0,(uint8_t*)"00000000");
			}
			else if(pswd_stat==1){
				LCD_Display_Words(0,0,(uint8_t*)"Pswd correct!");
				LCD_Display_Words(1,0,(uint8_t*)"Please ipt new");
			}
			else if(pswd_stat==2){
				LCD_Display_Words(0,0,(uint8_t*)"Change pswd?");
				LCD_Display_Words(1,0,(uint8_t*)"Try again!");
			}
			else if(pswd_stat==3){
				LCD_Display_Words(0,0,(uint8_t*)"Are you sure?");
				LCD_Display_Words(1,0,(uint8_t*)"See the LEDs");
			}
		}
 	}
}
