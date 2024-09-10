/**
  ******************************************************************************
  * @file       main.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      反射循迹触发蜂鸣器
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
#include "track/bsp_gpio_track.h"
#include "beep/bsp_gpio_beep.h"
#include "led/bsp_gpio_led_ex.h"


/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void )
{
	
	TRACK_GPIO_Config();
	LED_EX_GPIO_Config();
	BEEP_GPIO_Config();
    while(1){
		//R_LED_ON_ONLY;
		if(TRACK_SCAN(TRACK_GPIO_PORT,TRACK_GPIO_PIN)==TRACK_ON)
		{
			LED1_LED_EX_ON;	
			BEEP_BEEP_ON;
		}else{
			LED1_LED_EX_OFF;	
			BEEP_BEEP_OFF;
		}
		
			
	}
}


