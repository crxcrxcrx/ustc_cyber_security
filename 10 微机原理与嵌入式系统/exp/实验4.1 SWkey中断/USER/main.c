#include <sys.h>	
#include "exti.h"
#include "delay.h"
#include "led.h"
#include "sw.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);   	
	LED_Init();				  
	KEY_Init();
	EXTIX_Init();       
	LED0=0;			    	
	while(1)
	{
  	
	}
}
