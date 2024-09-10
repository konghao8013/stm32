
/**
  ******************************************************************************
  * @file       bsp_gpio_key.ex.H
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      热敏传感器
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
  
  
#ifndef __BSP_GPIO_TRACK_H
#define __BSP_GPIO_TRACK_H

#include "stm32f10x.h"

/*WKUP_KEY1 按键*/
#define TRACK_GPIO_PORT		GPIOA 					/*gpio端口*/
#define TRACK_GPIO_CLK_PORT	RCC_APB2Periph_GPIOA	/*GPIO端口时钟*/
#define TRACK_GPIO_PIN		GPIO_Pin_12				/*链接到GPIO*/





/*
触发按键-光照传感器  条件
0 --OFF
1 --ON
*/


#define TRACK_ON 0
#define TRACK_OFF 1




void TRACK_GPIO_Config();
uint32_t TRACK_SCAN(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif
