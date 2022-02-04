#include "wwdg.h"
#include "led.h"
#include "SysTick.h"


//窗口值是：0x5f
//定时器计数值是：0x7f
//预分频值是:8
void WWDG_Init()
{
	//定义结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//使能 WWDG 时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE); 
	
	//设置 WWDG 窗口值
	WWDG_SetWindowValue(0x5F);
	
	//设置 WWDG 分频数
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	
	//配置WWDG中断
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	//同时设置计数器初始值和使能 WWDG 
	WWDG_Enable(0x7F);
	
	//清除窗口看门狗状态标志
	WWDG_ClearFlag();
	
	//开启中断
	WWDG_EnableIT();

}


void WWDG_IRQHandler()
{
	//delay_ms(1);  //判断有没有复位,喂狗延时
	
	//重新赋值
	WWDG_SetCounter(0x7F);
	
	//清除窗口看门狗状态标志
	WWDG_ClearFlag();
	
	led_1 = !led_1;
}


