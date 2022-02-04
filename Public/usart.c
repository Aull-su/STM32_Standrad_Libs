/*!
================================================================================
@Project    : STM32_Standard_Wrapper_Libs  
@Module Func: usart wrapper
--------------------------------------------------------------------------------
@File Name	: usart.c                                                                                           
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
#include "usart.h"


/*!
================================================================================
@Brief
	retarget printf to serial port for c                               
@Param
	ch  [the data to transmit]                                                                   
@Return	
	ch  [the data to transmit]                                   
-------------------------------------------------------------------------------
*/
int fputc(int ch,FILE *p)
{
	USART_SendData(USART1,(u8)ch);	
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	
	return ch;
}

/*!
================================================================================
@Brief
	initialization USART1                               
@Param
	baudRate  [the baud rate]                                                                   
@Return	
	none                                  
-------------------------------------------------------------------------------
*/
void USART1_Init(u32 baudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
	
	// TX
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// RX
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = baudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	
	USART_Cmd(USART1, ENABLE);
	
	USART_ClearFlag(USART1, USART_FLAG_TC);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/*!
================================================================================
@Brief
	USART1 handler                               
@Param
	void                                                                   
@Return	
	none                                  
-------------------------------------------------------------------------------
*/
void USART1_IRQHandler(void)
{
	u8 uRead;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		uRead = USART_ReceiveData(USART1);
		
		USART_SendData(USART1,uRead);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
	}
	
	USART_ClearFlag(USART1, USART_FLAG_TC);
}

/******************* (C) COPYRIGHT 2022 @su.ch ******************END OF FILE***/
