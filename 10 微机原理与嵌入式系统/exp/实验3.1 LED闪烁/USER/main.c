#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"
#include "tim.h"

int main(void)
{
	delay_init(168);	//初始化延时函数
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组 2 
	LED_Init();
	LED0=0;
	LED1=0;
	TIM3_Init(7999,8999);
	while(1)
	{
		LED1=!LED1;
		delay_ms(500);
	}
}
