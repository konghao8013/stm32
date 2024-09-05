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
#include "LED.h"

void SystemInit(void)
{
	
}





/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void )
{
	//开启时钟	
	RCC_GPIO_CMD();
	
	//关闭灯	
	GPIOA_IO_LED_OFF(GPIO_PIN_1);
	GPIOA_IO_LED_OFF(GPIO_PIN_2);
	GPIOA_IO_LED_OFF(GPIO_PIN_3);
	
	//配置IO模式，推挽模式，50m	
	
	GPIOA_IO_CMD(GPIO_PIN_1);
	GPIOA_IO_CMD(GPIO_PIN_2);
	GPIOA_IO_CMD(GPIO_PIN_3);
	
	//开启灯
	GPIOA_IO_LED_ON(GPIO_PIN_1);
	GPIOA_IO_LED_ON(GPIO_PIN_2);
	GPIOA_IO_LED_ON(GPIO_PIN_3);
	while(1)
	{
		unsigned int i;
			
		for(i = 0;i<1000000;i++)
		{
		
		}
		
		GPIOA_IO_LED_OFF(GPIO_PIN_1);


		for(i = 0;i<1000000;i++)
		{
		
		}
		GPIOA_IO_LED_ON(GPIO_PIN_1);

	}
}


