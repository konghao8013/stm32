/**
  ******************************************************************************
  * @file       bsp_gpio_beep.h
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      热敏传感器触发蜂鸣器
  ******************************************************************************
  * @attention
  *
  * 实验平台  ：野火 STM32F103C8T6-STM32开发板 
  * 论坛      ：http://www.firebbs.cn
  * 官网      ：https://embedfire.com/
  * 淘宝      ：https://yehuosm.tmall.com/
  *
  ******************************************************************************
  */
  
#ifndef __BSP_GPIO_BEEP_H
#define __BSP_GPIO_BEEP_H

#include "stm32f10x.h"


#define BEEP_GPIO_PORT	GPIOA
#define BEEP_GPIO_CLK_PORT	RCC_APB2Periph_GPIOA
#define BEEP_GPIO_PIN	GPIO_Pin_6

/*
触发蜂鸣器
1 on
0 off
**/
#define BEEP_ON 1
#define BEEP_OFF 0

#define BEEP(A) if(A)		GPIO_SetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN);	\
				 else 	  GPIO_ResetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
					 


#define DIGITALHI(P,I)	{P->BSRR	=I;}//输出为高电平
#define DIGITALLO(P,I)	{P->BRR	=I;}//输出为低电平
#define DIGITALTLGGLE(P,I)	{P->ODR	^=I;}//输出为反转状态

/*定义控制IO宏*/
#define BEEP_BEEP_TOGGLE			DIGITALTLGGLE(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define BEEP_BEEP_OFF			DIGITALLO(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define BEEP_BEEP_ON				DIGITALHI(BEEP_GPIO_PORT,BEEP_GPIO_PIN)



void BEEP_GPIO_Config();



#endif
