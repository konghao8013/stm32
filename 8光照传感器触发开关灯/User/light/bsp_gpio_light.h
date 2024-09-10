
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
  
  
#ifndef __BSP_GPIO_LIGHT_H
#define __BSP_GPIO_LIGHT_H

#include "stm32f10x.h"

/*WKUP_KEY1 按键*/
#define LIGHT_GPIO_PORT		GPIOA 					/*gpio端口*/
#define LIGHT_GPIO_CLK_PORT	RCC_APB2Periph_GPIOA	/*GPIO端口时钟*/
#define LIGHT_GPIO_PIN		GPIO_Pin_11				/*链接到GPIO*/





/*
触发按键-光照传感器  条件
0 --OFF
1 --ON
*/


#define LIGHT_ON 0
#define LIGHT_OFF 1




void LIGHT_GPIO_Config();
uint32_t LIGHT_SCAN(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif
