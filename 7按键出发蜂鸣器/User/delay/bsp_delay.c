/**
  ******************************************************************************
  * @file       main.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      延迟函数
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
  

#include "delay/bsp_delay.h"

/**
  * @brief  延迟函数
  * @param  无 
  * @note   无
  * @retval 无
  */
  
  void Rough_Delay(__IO uint32_t ncount)
  {	
	  for(uint32_t i=0;i<ncount;i++){
		__NOP();
	  }
  }
  void Rough_Delay_Us(__IO uint32_t ncount){
		Rough_Delay(ncount*8);
  }
  void Rough_Delay_Ms(__IO uint32_t ncount){ 
		Rough_Delay_Us(0x3e8*ncount);	   
  }
  void Rough_Delay_S(__IO uint32_t ncount){  
	  Rough_Delay_Ms(0x3e8*ncount);
  }
  