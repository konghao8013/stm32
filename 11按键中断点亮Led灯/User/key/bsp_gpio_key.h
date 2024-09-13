#ifndef __BSP_GPIO_KEY_H
#define __BSP_GPIO_KEY_H

#include "stm32f10x.h"

/*WKUP_KEY1 按键*/
#define WKUP_KEY1_GPIO_PORT	GPIOA
#define WKUP_KEY1_GPIO_CLK_PORT	RCC_APB2Periph_GPIOA
#define WKUP_KEY1_GPIO_PIN	GPIO_Pin_0

/*WKUP_KEY1 按键*/

#define WKUP_KEY1_KEY_IN_GPIO_EXTI_CLK_PORT				RCC_APB2Periph_AFIO /*复用端口时钟*/
#define WKUP_KEY1_KEY_IN_GPIO_EXTI_PORTSOUTCE			GPIO_PortSourceGPIOA /*中断端口*/
#define WKUP_KEY1_KEY_IN_GPIO_EXTI_PINSOUTCE			GPIO_PinSource0 /*中断端口源*/
#define WKUP_KEY1_KEY_IN_GPIO_EXTI_LINE					EXTI_Line0 /*中断线*/
#define WKUP_KEY1_KEY_IN_GPIO_EXTI_IRQ					EXTI0_IRQn /*中断向量号*/ 
#define WKUP_KEY1_KEY_IN_GPIO_EXTI_HANDLER				EXTI0_IRQHandler /*中断处理函数*/

/*WKUP_KEY2 按键*/
#define WKUP_KEY2_GPIO_PORT	GPIOC
#define WKUP_KEY2_GPIO_CLK_PORT	RCC_APB2Periph_GPIOC
#define WKUP_KEY2_GPIO_PIN	GPIO_Pin_13


/*
触发按键-板载按键 条件
0 --OFF
1 --ON
*/


#define KEY_ON 1
#define KEY_OFF 0




void KEY_GPIO_Config(void);
void EXTI_KEY_GPIO_Config(void);
uint32_t KEY_SCAN(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif
