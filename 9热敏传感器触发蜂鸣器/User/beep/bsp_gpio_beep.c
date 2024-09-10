/**
  ******************************************************************************
  * @file       bsp_gpio_beep.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      按键触发蜂鸣器
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
  
#include "stm32f10x.h"
#include "beep/bsp_gpio_beep.h"

void BEEP_GPIO_Config(){
	GPIO_InitTypeDef gpio_initstruct = {0};
    
    //开启端口时钟
    RCC_APB2PeriphClockCmd(BEEP_GPIO_CLK_PORT,ENABLE);

    //关闭灯
	BEEP_BEEP_OFF;
    
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = BEEP_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BEEP_GPIO_PORT,&gpio_initstruct);
    

}
