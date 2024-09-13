/**
  ******************************************************************************
  * @file       bsp_gpio_light.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      光照传感器接口
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
#include "light/bsp_gpio_light.h"
#include "delay/bsp_delay.h"

void LIGHT_GPIO_Config(){
	GPIO_InitTypeDef gpio_initstruct = {0};
    
    /*开启时钟*/
    RCC_APB2PeriphClockCmd(LIGHT_DO_GPIO_CLK_PORT,ENABLE);
	
 
	/*选择要控制的GPIO引脚，设置GPIO模式为浮空输入，设置GPIO速率为50MHz*/
    
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_initstruct.GPIO_Pin = LIGHT_DO_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LIGHT_DO_GPIO_PORT,&gpio_initstruct);
    

}


/**
  * @brief  检查按键是否按下
  * @param   GPIOX:X 可以是 A,B,C,D,
  * @param  GPIO_PIN:待读取的端口位
  * @note   无
  * @retval KEY_OFF (没有按下按键)，KEY_ON(按下了按键)
  */
uint32_t LIGHT_SCAN(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){

		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == LIGHT_ON)
		{
			//while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == LIGHT_ON);
			return LIGHT_ON;
			
		}
		
		return LIGHT_OFF;
}