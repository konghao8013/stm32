
/**
  ******************************************************************************
  * @file       bsp_gpio_key.ex.H
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      扩展按键
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
  
  
#ifndef __BSP_GPIO_KEY_EX_H
#define __BSP_GPIO_KEY_EX_H

#include "stm32f10x.h"

/*WKUP_KEY1 按键*/
#define WKUP_KEY3_GPIO_PORT		GPIOB 					/*gpio端口*/
#define WKUP_KEY3_GPIO_CLK_PORT	RCC_APB2Periph_GPIOB	/*GPIO端口时钟*/
#define WKUP_KEY3_GPIO_PIN		GPIO_Pin_5				/*链接到GPIO*/

/*WKUP_KEY2 按键*/
#define WKUP_KEY4_GPIO_PORT		GPIOB
#define WKUP_KEY4_GPIO_CLK_PORT	RCC_APB2Periph_GPIOB
#define WKUP_KEY4_GPIO_PIN		GPIO_Pin_6



/*WKUP_KEY1 按键*/
#define WKUP_KEY5_GPIO_PORT		GPIOB
#define WKUP_KEY5_GPIO_CLK_PORT	RCC_APB2Periph_GPIOB
#define WKUP_KEY5_GPIO_PIN		GPIO_Pin_7

/*WKUP_KEY2 按键*/
#define WKUP_KEY6_GPIO_PORT		GPIOB
#define WKUP_KEY6_GPIO_CLK_PORT	RCC_APB2Periph_GPIOB
#define WKUP_KEY6_GPIO_PIN		GPIO_Pin_8





/*
触发按键-板载按键 条件
0 --OFF
1 --ON
*/


#define KEY_EX_ON 0
#define KEY_EX_OFF 1




void KEY_EX_GPIO_Config();
uint32_t KEY_EX_SCAN(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif
