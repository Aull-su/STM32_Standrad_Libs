/*!
================================================================================
@Project    : STM32_Standard_Wrapper_Libs  
@Module Func: main function
--------------------------------------------------------------------------------
@File Name	: main.c                                                                                           
@Copyright by su.ch                                                     
--------------------------------------------------------------------------------
Change Records                                                              
--------------------------------------------------------------------------------
  [No]       [Name]       [Date]      [Description]                         
  v0.1       new          2022/01/31  new                                  
================================================================================
*/ 

//!-----------------------------------------------------------------------------
//!-----------------------------> Includes  <-----------------------------------
//!-----------------------------------------------------------------------------
#include "BitBand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "led.h"
#include "SysTick.h"
#include "usart.h"
#include "DS18B20Util.h"
#include "esp8266_drive.h"
#include "sta_tcpclent_test.h"


/*!
================================================================================
@Brief
	Write data to fifo(sample)                                       
@Param
	pdata	[write data buffer pointer]                               
	size	[write data length]                                       
@Return	
	count	[size has been written]                                   
--------------------------------------------------------------------------------
*/
int main(void)
{
	u8 i=0;
	char cStr[100]={0};
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� �� 2 ��
	LED_Init();
	USART1_Init(115200);
	
	// ���DS18B20
	while(DS_Init())
	{
	    printf("δ��⵽DS18B20�����ô�������\r\n");
	    delay_ms(500);
	}
	printf("��⵽DS18B20��\r\n");
	
	// ESP8266 Init
	ESP8266_Init(115200);
	ESP8266_STA_TCPClient_Test();
	
  /* Infinite loop */
	while(1)
	{
		i++;
		if(i%20==0)
		{
		    led_0=!led_0;
		}
		
		if(i%500 == 0)
		{
		      printf("��⵽���¶�Ϊ��[%.2f��]\r\n", DS_OnLoop());
			    memset(cStr, 0, sizeof(cStr));
			    sprintf (cStr,"��⵽���¶�Ϊ��[%.2f��]\r\n",  DS_OnLoop());
			    ESP8266_OnLoop(cStr);
		}
		
		delay_ms(10);
			
	}
}


/******************* (C) COPYRIGHT 2022 @su.ch *****************END OF FILE****/

