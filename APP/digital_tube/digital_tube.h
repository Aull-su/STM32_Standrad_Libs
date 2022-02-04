#ifndef DIGITAL_TUBE_H
#define DIGITAL_TUBE_H

#include "BitBand.h"

#define DIG_TUBE_PORT_RCC        RCC_APB2Periph_GPIOC
#define DIG_TUBE_PIN             (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7)
#define DIG_TUBE_PORT            GPIOC


void DigTube_Init(void);

#endif
