#ifndef IIC_H
#define IIC_H

#include "BitBand.h"

/*  IIC_SCL时钟端口、引脚定义 */
#define IIC_SCL_PORT 			GPIOB   
#define IIC_SCL_PIN 			(GPIO_Pin_10)
#define IIC_SCL_PORT_RCC		RCC_APB2Periph_GPIOB

/*  IIC_SDA时钟端口、引脚定义 */
#define IIC_SDA_PORT 			GPIOB  
#define IIC_SDA_PIN 			(GPIO_Pin_11)
#define IIC_SDA_PORT_RCC		RCC_APB2Periph_GPIOB

//IO操作函数	 
#define IIC_SCL    PBout(10) //SCL
#define IIC_SDA    PBout(11) //SDA	 
#define READ_SDA   PBin(11)  //输入SDA

//IIC所有操作函数
void IIC_Init(void);
void SDA_OUT(void);
void SDA_IN(void);
void IIC_Start(void);
void IIC_Stop(void);
u8 IIC_Wait_Ack(void);
void IIC_Ack(void);
void IIC_NAck(void);
void IIC_Send_Byte(u8 txd);
u8 IIC_Read_Byte(u8 ack);

#endif
