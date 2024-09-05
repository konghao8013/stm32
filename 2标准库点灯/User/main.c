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

/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void )
{
 GPIO_InitTypeDef gpio_initstruct = {0};
    
    //开启端口时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    //关闭灯
    GPIO_SetBits(GPIOA,GPIO_Pin_1);
    GPIO_SetBits(GPIOA,GPIO_Pin_2);
    GPIO_SetBits(GPIOA,GPIO_Pin_3);
    
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = GPIO_Pin_1;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&gpio_initstruct);
    
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = GPIO_Pin_2;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&gpio_initstruct);
    
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = GPIO_Pin_3;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&gpio_initstruct);
    //开灯
    GPIO_ResetBits(GPIOA,GPIO_Pin_1);
    GPIO_ResetBits(GPIOA,GPIO_Pin_2);
    GPIO_ResetBits(GPIOA,GPIO_Pin_3);

    while(1);
}


