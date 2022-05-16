#include "stm32f4xx.h"
#include "delay.h"//延时函数所在的头文件

void LED_Init(void); 		
void control(uint8_t c);

#define ON   Bit_SET     //GPIO的布尔变量，用于GPIO_WriteBit函数
#define OFF  Bit_RESET   //GPIO的布尔变量，用于GPIO_WriteBit函数

#define LED0(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_11, x)//写IO口状态，0/1
#define LED1(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_10, x)
#define LED2(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_9, x)
#define LED3(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_7, x)
#define LED4(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_3, x)
#define LED5(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_2, x)
#define LED6(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_13, x)
#define LED7(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_12, x)

int main(void)
{ 
	LED_Init();		       //初始化LED端口
	delay_init(168);     //初始化延时函数

	while(1)
	{
		/*流水灯显示*/
		control(1);
		delay_ms(500);
		control(3);
		delay_ms(500);
		control(7);
		delay_ms(500);
		control(15);
		delay_ms(500);
		control(31);
		delay_ms(500);
		control(63);
		delay_ms(500);
		control(127);
		delay_ms(500);
		control(255);
		delay_ms(500);
 	}
}
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;   //GPIO初始化结构体
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG|
								RCC_AHB1Periph_GPIOD, ENABLE);//使能GPIOG、GPIOD时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9 | GPIO_Pin_2 | GPIO_Pin_3;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOG,GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_7 | GPIO_Pin_9 | GPIO_Pin_2 | GPIO_Pin_3);//LED1,LED2,LED3,LED4,LED5

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 |GPIO_Pin_12 | GPIO_Pin_13;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOD, GPIO_Pin_7 |GPIO_Pin_12|GPIO_Pin_13);  //LED6,LED7		 
}

void control(uint8_t c)
{
	if((c & 1) == 1) 
		LED0(ON);
	else
		LED0(OFF);
	if((c & 2) == 2)
		LED1(ON);
	else
		LED1(OFF);
	if((c & 4) == 4)
		LED2(ON);
	else
		LED2(OFF);
	if((c & 8) == 8)
		LED3(ON);
	else
		LED3(OFF);
	if((c & 16) == 16)
		LED4(ON);
	else
		LED4(OFF);
	if((c & 32) == 32)
		LED5(ON);
	else
		LED5(OFF);
	if((c & 64) == 64)
		LED6(ON);
	else
		LED6(OFF);
	if((c & 128) == 128)
		LED7(ON);
	else
		LED7(OFF);
}

