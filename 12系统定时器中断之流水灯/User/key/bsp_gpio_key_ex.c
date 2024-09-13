/**
  ******************************************************************************
  * @file       bsp_gpio_key.ex.c
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
  
#include "stm32f10x.h"
#include "key/bsp_gpio_key_ex.h"
#include "delay/bsp_delay.h"

void KEY_EX_GPIO_Config(){
	GPIO_InitTypeDef gpio_initstruct = {0};
    
    /*开启时钟*/
    RCC_APB2PeriphClockCmd(WKUP_KEY3_GPIO_CLK_PORT,ENABLE);
	
 
	/*选择要控制的GPIO引脚，设置GPIO模式为浮空输入，设置GPIO速率为50MHz*/
    
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IPU;
    gpio_initstruct.GPIO_Pin = WKUP_KEY3_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(WKUP_KEY3_GPIO_PORT,&gpio_initstruct);
    

	//配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IPU;
    gpio_initstruct.GPIO_Pin = WKUP_KEY4_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(WKUP_KEY4_GPIO_PORT,&gpio_initstruct);
	
	//配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IPU;
    gpio_initstruct.GPIO_Pin = WKUP_KEY5_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(WKUP_KEY5_GPIO_PORT,&gpio_initstruct);
	
		
	//配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IPU;
    gpio_initstruct.GPIO_Pin = WKUP_KEY6_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(WKUP_KEY6_GPIO_PORT,&gpio_initstruct);
	
}


/**
  * @brief  检查按键是否按下
  * @param   GPIOX:X 可以是 A,B,C,D,
  * @param  GPIO_PIN:待读取的端口位
  * @note   无
  * @retval KEY_OFF (没有按下按键)，KEY_ON(按下了按键)
  */
uint32_t KEY_EX_SCAN(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
		uint32_t key_ex_san_temp_i = 0;
		uint32_t filtering_factor = 30;
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_EX_ON)
		{
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_EX_ON){
				key_ex_san_temp_i++;
				Rough_Delay_Ms(1);
				if(key_ex_san_temp_i == filtering_factor){
					break;
				}
			}
			if(key_ex_san_temp_i != filtering_factor){
				return KEY_EX_ON;
			}
			
		}
		
		return KEY_EX_OFF;
}