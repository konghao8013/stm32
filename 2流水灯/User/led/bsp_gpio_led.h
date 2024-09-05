#ifndef __BSP_GPIO_LED_H
#define __BSP_GPIO_LED_H

#include "stm32f10x.h"


#define R_LED_GPIO_PORT	GPIOA
#define R_LED_GPIO_CLK_PORT	RCC_APB2Periph_GPIOA
#define R_LED_GPIO_PIN	GPIO_Pin_1

#define G_LED_GPIO_PORT	GPIOA
#define G_LED_GPIO_CLK_PORT	RCC_APB2Periph_GPIOA
#define G_LED_GPIO_PIN	GPIO_Pin_2

#define B_LED_GPIO_PORT	GPIOA
#define B_LED_GPIO_CLK_PORT	RCC_APB2Periph_GPIOA
#define B_LED_GPIO_PIN	GPIO_Pin_3

#define LED1_LED2_LED3_ON 0
#define LED1_LED2_LED3_OFF 1

#define R_LED(A) if(A)	GPIO_ResetBits(R_LED_GPIO_PORT,R_LED_GPIO_PIN);	\
				 else GPIO_SetBits(R_LED_GPIO_PORT,R_LED_GPIO_PIN)
					 
#define G_LED(A) if(A)	GPIO_ResetBits(G_LED_GPIO_PORT,G_LED_GPIO_PIN);	\
				 else GPIO_SetBits(G_LED_GPIO_PORT,G_LED_GPIO_PIN)

#define B_LED(A) if(A)	GPIO_ResetBits(B_LED_GPIO_PORT,B_LED_GPIO_PIN);	\
				 else GPIO_SetBits(B_LED_GPIO_PORT,B_LED_GPIO_PIN)


void LED_GPIO_Config();



#endif
