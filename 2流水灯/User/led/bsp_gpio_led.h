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

#define DIGITALHI(P,I)	{P->BSRR	=I;}//输出为高电平
#define DIGITALLO(P,I)	{P->BRR	=I;}//输出为低电平
#define DIGITALTLGGLE(P,I)	{P->ODR	^=I;}//输出为反转状态

/*定义控制IO宏*/
#define R_LED_TOGGLE	DIGITALTLGGLE(R_LED_GPIO_PORT,R_LED_GPIO_PIN)
#define R_LED_OFF			DIGITALHI(R_LED_GPIO_PORT,R_LED_GPIO_PIN)
#define R_LED_ON			DIGITALLO(R_LED_GPIO_PORT,R_LED_GPIO_PIN)

#define G_LED_TOGGLE	DIGITALTLGGLE(G_LED_GPIO_PORT,G_LED_GPIO_PIN)
#define G_LED_OFF			DIGITALHI(G_LED_GPIO_PORT,G_LED_GPIO_PIN)
#define G_LED_ON			DIGITALLO(G_LED_GPIO_PORT,G_LED_GPIO_PIN)


#define B_LED_TOGGLE	DIGITALTLGGLE(B_LED_GPIO_PORT,B_LED_GPIO_PIN)
#define B_LED_OFF			DIGITALHI(B_LED_GPIO_PORT,B_LED_GPIO_PIN)
#define B_LED_ON			DIGITALLO(B_LED_GPIO_PORT,B_LED_GPIO_PIN)

/*单灯操作*/

#define R_LED_ON_ONLY	R_LED_ON	\
						G_LED_OFF	\
						B_LED_OFF	

#define G_LED_ON_ONLY	R_LED_OFF	\
						G_LED_ON	\
						B_LED_OFF	

#define B_LED_ON_ONLY	R_LED_OFF	\
						G_LED_OFF	\
						B_LED_ON	

/*RGB全亮*/

#define R_G_B_ALL_ON 	R_LED_ON	\
						G_LED_ON	\
						B_LED_ON	
						
/*RGB灭*/

#define R_G_B_ALL_OFF 	R_LED_OFF	\
						G_LED_OFF	\
						B_LED_OFF	
void LED_GPIO_Config();



#endif
