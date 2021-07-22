#ifndef __TIM_H
#define __TIM_H
#include <sys.h>	
#include "led.h" 

void TIM3_Init(u16 arr,  u16 psc);
void TIM3_IRQHandler(void);
void TIM4_Init(u16 arr,  u16 psc);
void TIM4_IRQHandler(void);
	
#endif
