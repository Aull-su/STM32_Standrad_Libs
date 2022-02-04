#ifndef ADC_TEMP_H
#define ADC_TEMP_H


#include "BitBand.h"


void ADC_Temp_Init(void);

u16 Get_ADC_Temp_Value(u8 ch,u8 times);


int Get_Temperture(void);


#endif
