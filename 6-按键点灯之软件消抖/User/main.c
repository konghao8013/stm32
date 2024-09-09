/**
  ******************************************************************************
  * @file       main.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      按键点灯
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
#include "led/bsp_gpio_led.h"
#include "led/bsp_gpio_led_ex.h"
#include "key/bsp_gpio_key.h"
#include "key/bsp_gpio_key_ex.h"


/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void )
{
	uint32_t time_temp=300;
	LED_GPIO_Config();
	LED_EX_GPIO_Config();
	KEY_GPIO_Config();
	KEY_EX_GPIO_Config();
    while(1){
		//R_LED_ON_ONLY;
		if(KEY_SCAN(WKUP_KEY1_GPIO_PORT,WKUP_KEY1_GPIO_PIN)==KEY_ON)
		{
	
			R_LED_TOGGLE;
		}
		
		else if(KEY_SCAN(WKUP_KEY2_GPIO_PORT,WKUP_KEY2_GPIO_PIN)==KEY_ON)
		{
	
			G_LED_TOGGLE;
		}		
		
		else if(KEY_EX_SCAN(WKUP_KEY3_GPIO_PORT,WKUP_KEY3_GPIO_PIN)==KEY_EX_ON)
		{
	
			B_LED_TOGGLE;
		}		
		else if(KEY_EX_SCAN(WKUP_KEY4_GPIO_PORT,WKUP_KEY4_GPIO_PIN)==KEY_EX_ON)
		{
	
			LED1_LED_EX_TOGGLE;
		}		
		else if(KEY_EX_SCAN(WKUP_KEY4_GPIO_PORT,WKUP_KEY5_GPIO_PIN)==KEY_EX_ON)
		{
	
			LED2_LED_EX_TOGGLE;
		}	
		else if(KEY_EX_SCAN(WKUP_KEY4_GPIO_PORT,WKUP_KEY6_GPIO_PIN)==KEY_EX_ON)
		{
	
			LED3_LED_EX_TOGGLE;
		}
		
		
			
	}
}


