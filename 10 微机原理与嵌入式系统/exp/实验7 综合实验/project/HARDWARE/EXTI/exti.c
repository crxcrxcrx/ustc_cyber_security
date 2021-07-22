#include "exti.h"
#include "sys.h"
#include "delay.h"
#include "lcd.h"
#include "user.h"

extern u8 mode;
extern u8 pswd;
extern u8 pswd_tmp;
extern u8 pswd_stat;

void EXTIX_Init(void){
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	//PE0
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource0);
	//EXTI0
	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
	EXTI_Init(&EXTI_InitStructure);
	//EXTI0-PE0
	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//PE1
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource1);
	//EXTI1
	EXTI_InitStructure.EXTI_Line=EXTI_Line1;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	//EXTI1-PE1
	NVIC_InitStructure.NVIC_IRQChannel=EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x02;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI0_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line0)!=RESET){
		delay_ms(200);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0)==1){
			//SW0 touched
			LCD_Clear();
			LCD_Clear();
			LCD_Clear();
			LCD_Clear();
			mode++;
			pswd_stat=0;
			EXTI_ClearITPendingBit(EXTI_Line0);
		}
	}
}

void EXTI1_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line1)!=RESET){
		delay_ms(200);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==1){
			//SW1 touched
			LCD_Clear();
			LCD_Clear();
			LCD_Clear();
			LCD_Clear();
			if(mode%2==0){
				if(CheckPswd()==1){
					pswd_stat=1;
				}
				else{
					pswd_stat=2;
				}
			}
			else if(mode%2==1){
				if(pswd_stat==0||pswd_stat==2){
					if(CheckPswd()==1){
						pswd_stat=1;
					}
					else{
						pswd_stat=2;
					}
				}
				else if(pswd_stat==1){
					pswd_tmp=ScanPswd();
					pswd_stat=3;
				}
				else if(pswd_stat==3){
					mode=0;
					pswd=pswd_tmp;
					pswd_tmp=0;
					pswd_stat=0;
				}
			}
			EXTI_ClearITPendingBit(EXTI_Line1);
		}
	}
}
