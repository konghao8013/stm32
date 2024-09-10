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
#include "ntc/bsp_gpio_ntc.h"
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
	
	NTC_GPIO_Config();
	LED_EX_GPIO_Config();
	BEEP_GPIO_Config();
    while(1){
		//R_LED_ON_ONLY;
		if(NTC_SCAN(NTC_GPIO_PORT,NTC_GPIO_PIN)==NTC_ON)
		{
			LED1_LED_EX_ON;	
			BEEP_BEEP_ON;
		}else{
			LED1_LED_EX_OFF;	
			BEEP_BEEP_OFF;
		}
		
			
	}
}


