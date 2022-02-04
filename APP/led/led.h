#ifndef _LED_H
#define _LED_H

#include "BitBand.h"

#define LED_PORT_RCC    RCC_APB2Periph_GPIOC
#define LED_PIN         (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7)
#define LED_PORT        GPIOC
#define LED_0           GPIO_Pin_0
#define LED_1           GPIO_Pin_1
#define LED_2           GPIO_Pin_2
#define LED_3           GPIO_Pin_3
#define LED_4           GPIO_Pin_4
#define LED_5           GPIO_Pin_5
#define LED_6           GPIO_Pin_6
#define LED_7           GPIO_Pin_7

void LED_Init(void);
void LED_0_Set(void);
void LED_0_Reset(void);
void LED_1_Set(void);
void LED_1_Reset(void);
void LED_2_Set(void);
void LED_2_Reset(void);
void LED_3_Set(void);
void LED_3_Reset(void);
void LED_4_Set(void);
void LED_4_Reset(void);
void LED_5_Set(void);
void LED_5_Reset(void);
void LED_6_Set(void);
void LED_6_Reset(void);
void LED_7_Set(void);
void LED_7_Reset(void);

#define led_0 PCout(0)
#define led_1 PCout(1)
#define led_2 PCout(2)
#define led_3 PCout(3)
#define led_4 PCout(4)
#define led_5 PCout(5)
#define led_6 PCout(6)
#define led_7 PCout(7)

#endif
