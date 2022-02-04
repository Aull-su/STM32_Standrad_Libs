#include "wwdg.h"
#include "led.h"
#include "SysTick.h"


//����ֵ�ǣ�0x5f
//��ʱ������ֵ�ǣ�0x7f
//Ԥ��Ƶֵ��:8
void WWDG_Init()
{
	//����ṹ��
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//ʹ�� WWDG ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE); 
	
	//���� WWDG ����ֵ
	WWDG_SetWindowValue(0x5F);
	
	//���� WWDG ��Ƶ��
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	
	//����WWDG�ж�
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	//ͬʱ���ü�������ʼֵ��ʹ�� WWDG 
	WWDG_Enable(0x7F);
	
	//������ڿ��Ź�״̬��־
	WWDG_ClearFlag();
	
	//�����ж�
	WWDG_EnableIT();

}


void WWDG_IRQHandler()
{
	//delay_ms(1);  //�ж���û�и�λ,ι����ʱ
	
	//���¸�ֵ
	WWDG_SetCounter(0x7F);
	
	//������ڿ��Ź�״̬��־
	WWDG_ClearFlag();
	
	led_1 = !led_1;
}


