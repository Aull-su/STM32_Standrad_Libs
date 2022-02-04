#include "digital_tube.h"

void DigTube_Init(void)
{
		/* enable gpioc clock */
	RCC_APB2PeriphClockCmd(DIG_TUBE_PORT_RCC, ENABLE);
	
	/* init gpioc */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = DIG_TUBE_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DIG_TUBE_PORT, &GPIO_InitStructure);
}
