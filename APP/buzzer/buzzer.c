#include "buzzer.h"

void Buzzer_Init()
{
	
		/* enable gpiob clock */
	RCC_APB2PeriphClockCmd(BUZZER_PORT_RCC, ENABLE);
	
		/* init gpioc */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = BUZZER_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
