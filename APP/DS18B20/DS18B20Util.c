
#include "DS18B20Util.h"


//
DSProfile g_DSProfile = 
{
    {GPIOG, GPIO_Pin_11, GPIO_Mode_Out_PP, 1}
};


//m_pDS = &g_DSProfile;

//
bool DS_Init(void)
{
   return Init(&g_DSProfile);
}

//
float DS_OnLoop(void)
{
    return DSGetTempertare();
}

