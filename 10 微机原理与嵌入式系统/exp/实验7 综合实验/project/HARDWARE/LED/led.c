#include "led.h"
#include "sys.h"

void LED_Init(void){
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOG|RCC_AHB1Periph_GPIOD,ENABLE);
	//LED0,LED1,LED2,LED4,LED5
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_10|GPIO_Pin_9|GPIO_Pin_3|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
  GPIO_Init(GPIOG,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOG,GPIO_InitStructure.GPIO_Pin);
	//LED3 LED6,LED7
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7|GPIO_Pin_13|GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
  GPIO_Init(GPIOD,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOD,GPIO_InitStructure.GPIO_Pin);
}
