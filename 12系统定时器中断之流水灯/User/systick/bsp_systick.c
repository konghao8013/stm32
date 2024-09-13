/**
  ******************************************************************************
  * @file       main.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      系统定时器函数接口
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
  

#include "systick/bsp_systick.h"
#include "core_cm3.h"

volatile static uint32_t systick_delay;


void Systick_Init(void)
{
	if(SysTick_Config(SystemCoreClock/1000000)){
		while(1);
	}
}


void TimingDelay_Decrement(void){
	if(systick_delay!=0x00){
		systick_delay--;
	}
}
/**
  * @brief  系统杜塞延迟函数
  * @param  无 
  * @note   无
  * @retval 无
  */
  
void Delay_Us(__IO uint32_t time){
	systick_delay=time;
	while(systick_delay!=0);
}
  
  void Systick_Delay_Us(__IO uint32_t time){
		SysTick_Config(SystemCoreClock/1000000);
		systick_delay=time;
	  
		uint32_t i;
		for(i=0;i<time;i++){
			while(!((SysTick->CTRL)&(1<<16)));
		}
		SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
  }
  void Systick_Delay_Ms(__IO uint32_t time){ 
		SysTick_Config(SystemCoreClock/1000);
		systick_delay=time;
	  
		uint32_t i;
		for(i=0;i<time;i++){
			while(!((SysTick->CTRL)&(1<<16)));
		}
		SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
  }
  void Systick_Delay_S(__IO uint32_t time){  
	 	SysTick_Config(SystemCoreClock);
		systick_delay=time;
	  
		uint32_t i;
		for(i=0;i<time;i++){
			while(!((SysTick->CTRL)&(1<<16)));
		}
		SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
  }
  