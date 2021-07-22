#include "stm32f4xx.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "12864.h"
#include "string.h"

extern u16 USART_TX_EN; 
extern u16 USART_RX_STA; 

int main()
{
	char USART_SendBuf[]="Hello!";
  int i;  
  int Len=strlen(USART_SendBuf);	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	LCD_GPIO_Init();
	LCD_Init();
	uart1_init(115200);
	while(1)
	{
		delay_ms(2000);
		if(USART_TX_EN)
		{
			for(i=0;i<Len;i++)
			{
				USART_SendData(USART1, USART_SendBuf[i]); 				
				while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)!=SET);
			}
			USART_TX_EN=0;
		}
		//需补充代码
		LCD_Display_Words(0,0,USART_RX_BUF);
	}
}
