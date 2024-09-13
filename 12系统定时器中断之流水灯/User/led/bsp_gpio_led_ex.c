/**
  ******************************************************************************
  * @file    bsp_gpio_led_ex.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief   外部扩展led应用函数接口
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
  
#include "led/bsp_gpio_led_ex.h"    

/**
 * @brief  初始化控制扩展LED的IO
 * @param  无
 * @retval 无
 */
void LED_EX_GPIO_Config(void)
{
    /* 定义一个结构体 */
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    
    /*开启LED相关的GPIO外设/端口时钟*/
    RCC_APB2PeriphClockCmd(LED1_LED_EX_GPIO_CLK_PORT,ENABLE);
    RCC_APB2PeriphClockCmd(LED2_LED_EX_GPIO_CLK_PORT,ENABLE);
    RCC_APB2PeriphClockCmd(LED3_LED_EX_GPIO_CLK_PORT,ENABLE);

    /* 关闭所有led灯*/
//    GPIO_ResetBits(Y_LED_GPIO_PORT,Y_LED_GPIO_PIN);
//    GPIO_ResetBits(P_LED_GPIO_PORT,P_LED_GPIO_PIN);
//    GPIO_ResetBits(W_LED_GPIO_PORT,W_LED_GPIO_PIN);
    LED1_LED2_LED3_LED_EX_ALL_OFF;
    
    /*选择要控制的GPIO引脚、设置GPIO模式为通用推挽输出、设置GPIO速率为50MHz*/
    GPIO_InitStructure.GPIO_Mode    =   GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin     =   LED1_LED_EX_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed   =   GPIO_Speed_50MHz;
    GPIO_Init(LED1_LED_EX_GPIO_PORT,&GPIO_InitStructure);
    
    /*选择要控制的GPIO引脚、设置GPIO模式为通用推挽输出、设置GPIO速率为50MHz*/
    GPIO_InitStructure.GPIO_Mode    =   GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin     =   LED2_LED_EX_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed   =   GPIO_Speed_50MHz;
    GPIO_Init(LED2_LED_EX_GPIO_PORT,&GPIO_InitStructure);
   
    /*选择要控制的GPIO引脚、设置GPIO模式为通用推挽输出、设置GPIO速率为50MHz*/
    GPIO_InitStructure.GPIO_Mode    =   GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin     =   LED3_LED_EX_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed   =   GPIO_Speed_50MHz;
    GPIO_Init(LED3_LED_EX_GPIO_PORT,&GPIO_InitStructure);
     
}

/*********************************************END OF FILE**********************/
