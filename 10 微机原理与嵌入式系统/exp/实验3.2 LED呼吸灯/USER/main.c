#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"
#include "delay.h"
#include "pwm.h"

int main(void)
{
	u16 flag;
	delay_init(168); 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIM2_PWM_Init(3000,0);	  

	while(1) 
	{
		for(flag=0;flag<1024;flag+=64)
		{
			delay_ms(100);
			TIM_SetCompare3(TIM2,flag);			
		}
		
		for(flag=1024;flag>0;flag-=64)
		{
			delay_ms(100);
			TIM_SetCompare3(TIM2,flag);			
		}
		//修改比较值，修改占空比
	}
}
