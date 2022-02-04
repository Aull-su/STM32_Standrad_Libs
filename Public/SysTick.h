#ifndef SYSTICK_H
#define SYSTICK_H

#include "BitBand.h"

void SysTick_Init(u8 SYSCLK);
void delay_us(u32 nus);
void delay_ms(u16 nms);



#endif
