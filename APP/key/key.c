#include "key.h"
#include "SysTick.h"

void KEY_Init()
{
		/* enable gpioc clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE, ENABLE);
	
	/* init gpioc */
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = KEY_UP_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(KEY_UP_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KEY_LEFT_PIN|KEY_DOWN_PIN|KEY_RIGHT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(KEY_PUBLIC_PORT, &GPIO_InitStructure);
}

//mode = 0 : 单次扫描
//mode = 1 : 连续扫描
u8 KEY_Scan(u8 mode)
{
	static u8 key=1;
	if(key==1&&(K_UP==1||K_DOWN==0||K_LEFT==0||K_RIGHT==0)) //任意一个按键按下
	{
		delay_ms(10);  //消抖
		key=0;
		if(K_UP==1)
		{
			return KEY_UP; 
		}
		else if(K_DOWN==0)
		{
			return KEY_DOWN; 
		}
		else if(K_LEFT==0)
		{
			return KEY_LEFT; 
		}
		else
		{
			return KEY_RIGHT;
		}
	}
	else if(K_UP==0&&K_DOWN==1&&K_LEFT==1&&K_RIGHT==1)    //无按键按下
	{
		key=1;
	}
	if(mode==1) //连续按键按下
	{
		key=1;
	}
	return 0;
}


