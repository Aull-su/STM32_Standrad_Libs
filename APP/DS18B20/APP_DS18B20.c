/*!
================================================================================
@Project    : STM32_Standard_Wrapper_Libs  
@Module     : temperature sensor(DS18B20)
--------------------------------------------------------------------------------
@File Name	: APP_DS18B20.c                                                                                           
@Copyright by su.ch                                                    
--------------------------------------------------------------------------------
Change Records                                                              
--------------------------------------------------------------------------------
	[No]       [Name]       [Date]      [Description]                         
   1         su.ch        2022/01/06   first                                  
================================================================================
*/

//!-----------------------------------------------------------------------------
//!------------------------------> For Debug <----------------------------------
//!-----------------------------------------------------------------------------

//!-----------------------------------------------------------------------------
//!------------------------------> Includes  <----------------------------------
//!-----------------------------------------------------------------------------
#include "APP_DS18B20.h"

//!-----------------------------------------------------------------------------
//!---------------------------> Local Defines   <-------------------------------
//!-----------------------------------------------------------------------------

//!-----------------------------------------------------------------------------
//!---------------------------> Local Variables <-------------------------------
//!-----------------------------------------------------------------------------

//!-----------------------------------------------------------------------------
//!------------------------> External Variables <-------------------------------
//!-----------------------------------------------------------------------------

//!-----------------------------------------------------------------------------
//!------------------------> External Functions <-------------------------------
//!-----------------------------------------------------------------------------

//!-----------------------------------------------------------------------------
//!--------------------------> Function Section   <-----------------------------
//!-----------------------------------------------------------------------------


void DSIOIn(void)
{
    m_pDS->ctrlPin.GPIO_Mode = GPIO_Mode_IPU;
    InitIO(&(m_pDS->ctrlPin));
}

void DSIOOut(void)
{
    m_pDS->ctrlPin.GPIO_Mode = GPIO_Mode_Out_PP;
    InitIO(&(m_pDS->ctrlPin));
}

bool Init(DSProfile* pDS)
{
    /* Initialization DS18B20 single IO */
    m_pDS = pDS;
    Reset();
    return DetectDS();
}

void Reset(void)
{
    /* DS18B20 reset or time sequence init */
    DSIOOut();
    DQ_OUT_SET_L;
    delay_us(500);
    DQ_OUT_SET_H;
    delay_us(15);
}

bool DetectDS(void)
{
    u8 uRetry = 0;
    
    DSIOIn();
	
	  // DS18B20拉低总线之前的等待期
    while(DQ_IN && (uRetry < 200))
		{
		    delay_us(1);    
		    uRetry++;
		}
		if(uRetry >= 200)
		{
		    return 1;
		}
		else
		{
		    uRetry = 0;
		}
	
		// DS18B20拉低总线240us
    while((!DQ_IN) && (uRetry < 240))
		{
		    delay_us(1);
		    uRetry++;
		}
		
		if(uRetry >= 240)
		{
		    return 1;
		}
		else
		{
		    return 0;
		}
}

void DSWriteByte(u8 wData)
{
    u8 uBuf = 0;
    u8 uIndex = 0;
    u8 wDataCopy = wData;
	
    // 按位写数据
    DSIOOut();
    for(uIndex = 0; uIndex < 8; uIndex++)
    {
		    uBuf = wDataCopy & 0x01;
		    wDataCopy = wDataCopy >> 1;
		    if(uBuf)  // Write 1
				{
				    DQ_OUT_SET_L;
				    delay_us(2);
				    DQ_OUT_SET_H;
				    delay_us(60);
				}
				else  // Write 0
				{
            DQ_OUT_SET_L;
					  delay_us(60);    
					  DQ_OUT_SET_H;    
					  delay_us(2);
				}
		}
}

// read one bit
u8 DSReadBit(void)
{
    u8 uData = 0;
	
    DSIOOut();
    DQ_OUT_SET_L;
    delay_us(2);
    DQ_OUT_SET_H;
    DSIOIn();
    delay_us(12);
    if(DQ_IN)
		{
		    uData |= 0x01;
		}
		else
		{
		    uData |= 0x00;
		}
		delay_us(50);
		
		return uData;
}

u8 DSReadByte(void)
{
    u8 uBuf = 0;    
	  u8 uData = 0;
    u8 uIndex = 0;
	
	  for(uIndex = 0; uIndex < 8; uIndex++)
	  {
		    uBuf = DSReadBit();  // 字节的低位在前
		    uData = uData | (uBuf << uIndex);
		}
		return uData;

}

float DSGetTempertare(void)
{
    u16 uReg = 0;
    u8 uRegL = 0;
    u8 uRegH = 0;
    float uTemp = 0;
	
    Reset();
    DetectDS();
    DSWriteByte(0xcc);
    DSWriteByte(0x44);
    Reset();
    DetectDS();
    DSWriteByte(0xcc);
    DSWriteByte(0xbe);
    uRegL = DSReadByte();  // LSB
    uRegH = DSReadByte();  // MSB
    uReg = (uRegH << 8) | uRegL;
    if(uRegH & 0xf8)
		{
		    uReg = (~uReg) + 0x01;
		    uTemp = uReg * (-0.0625);
		}
		else
		{
		    uTemp = uReg * (0.0625);
		}
		
		return uTemp;
    
}







