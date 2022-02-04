#include "led.h"

void LED_Init(void)
{
	/* enable gpioc clock */
	RCC_APB2PeriphClockCmd(LED_PORT_RCC, ENABLE);
	
	/* init gpioc */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = LED_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	/* led0~8:off */
	GPIO_SetBits(LED_PORT, LED_PIN);
}

void LED_0_Set(void)
{
	/* light led0 */
	GPIO_ResetBits(LED_PORT, LED_0);
}

void LED_0_Reset(void)
{
	/* off led0 */
	GPIO_SetBits(LED_PORT, LED_0);
}

void LED_1_Set(void)
{
	/* light led1 */
	GPIO_ResetBits(LED_PORT, LED_1);
}

void LED_1_Reset(void)
{
	/* off led1 */
	GPIO_SetBits(LED_PORT, LED_1);
}

void LED_2_Set(void)
{
	/* light led2 */
	GPIO_ResetBits(LED_PORT, LED_2);
}

void LED_2_Reset(void)
{
	/* off led2 */
	GPIO_SetBits(LED_PORT, LED_2);
}

void LED_3_Set(void)
{
	/* light led3 */
	GPIO_ResetBits(LED_PORT, LED_3);
}

void LED_3_Reset(void)
{
	/* off led3 */
	GPIO_SetBits(LED_PORT, LED_3);
}

void LED_4_Set(void)
{
	/* light led4 */
	GPIO_ResetBits(LED_PORT, LED_4);
}

void LED_4_Reset(void)
{
	/* off led4 */
	GPIO_SetBits(LED_PORT, LED_4);
}

void LED_5_Set(void)
{
	/* light led5 */
	GPIO_ResetBits(LED_PORT, LED_5);
}

void LED_5_Reset(void)
{
	/* off led5 */
	GPIO_SetBits(LED_PORT, LED_5);
}

void LED_6_Set(void)
{
	/* light led6 */
	GPIO_ResetBits(LED_PORT, LED_6);
}

void LED_6_Reset(void)
{
	/* off led6 */
	GPIO_SetBits(LED_PORT, LED_6);
}

void LED_7_Set(void)
{
	/* light led7 */
	GPIO_ResetBits(LED_PORT, LED_7);
}

void LED_7_Reset(void)
{
	/* off led7 */
	GPIO_SetBits(LED_PORT, LED_7);
}
