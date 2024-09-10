/**
  ******************************************************************************
  * @file       main.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      光照传感器开关灯
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
  



#include "main.h"
#include "stm32f10x.h"
#include "delay/bsp_delay.h"
#include "light/bsp_gpio_light.h"
#include "led/bsp_gpio_led_ex.h"


/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void )
{
	
	LIGHT_GPIO_Config();
	LED_EX_GPIO_Config();
    while(1){
		//R_LED_ON_ONLY;
		if(LIGHT_SCAN(LIGHT_GPIO_PORT,LIGHT_GPIO_PIN)==LIGHT_ON)
		{
			LED1_LED_EX_ON;			
		}else{
			LED1_LED_EX_OFF;			
		}
		
			
	}
}


