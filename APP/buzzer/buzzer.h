#ifndef BUZZER_H
#define BUZZER_H

//#include "system.h"
#include "BitBand.h"

#define BUZZER_PORT_RCC RCC_APB2Periph_GPIOB
#define BUZZER_PIN      GPIO_Pin_5


void Buzzer_Init(void);

#define buzzer PBout(5)


#endif
