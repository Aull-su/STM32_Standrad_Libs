#include "time.h"
#include "led.h"


void TIME4_Init(u16 pre, u16 psc)
{
	TIM_TimeBaseInitTypeDef TIME_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	TIME_TimeBaseInitStructure.TIM_Period = pre; //自动重载值
	TIME_TimeBaseInitStructure.TIM_Prescaler = psc;
	TIME_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIME_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIME_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	
	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM4, ENABLE);
}	

void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) == 1)
	{
		led_1 = !led_1;
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);  //发生中断之后，主动清除中断标志
}
