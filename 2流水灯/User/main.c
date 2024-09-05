/**
  ******************************************************************************
  * @file       main.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      自建库点灯
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
/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void )
{
	LED_GPIO_Config();
    //开灯
    GPIO_ResetBits(GPIOA,GPIO_Pin_1);
    GPIO_ResetBits(GPIOA,GPIO_Pin_2);
    GPIO_ResetBits(GPIOA,GPIO_Pin_3);

    while(1){
		
		R_LED(LED1_LED2_LED3_ON);
		Rough_Delay_Ms(200);
		R_LED(LED1_LED2_LED3_OFF);
		Rough_Delay_Ms(200);
		
	
		G_LED(LED1_LED2_LED3_ON);
		Rough_Delay_Ms(200);
		G_LED(LED1_LED2_LED3_OFF);
		Rough_Delay_Ms(200);
		
		B_LED(LED1_LED2_LED3_ON);
		Rough_Delay_Ms(200);
		B_LED(LED1_LED2_LED3_OFF);
		Rough_Delay_Ms(200);
	}
}


