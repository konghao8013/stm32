#include "stm32f10x.h"
#include "led/bsp_gpio_led.h"

void LED_GPIO_Config(){
	GPIO_InitTypeDef gpio_initstruct = {0};
    
    //开启端口时钟
    RCC_APB2PeriphClockCmd(R_LED_GPIO_CLK_PORT,ENABLE);
	RCC_APB2PeriphClockCmd(G_LED_GPIO_CLK_PORT,ENABLE);
	RCC_APB2PeriphClockCmd(B_LED_GPIO_CLK_PORT,ENABLE);
    //关闭灯
    GPIO_SetBits(GPIOA,R_LED_GPIO_PIN);
    GPIO_SetBits(GPIOA,G_LED_GPIO_PIN);
    GPIO_SetBits(GPIOA,B_LED_GPIO_PIN);
    
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = R_LED_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&gpio_initstruct);
    
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = G_LED_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&gpio_initstruct);
    
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = B_LED_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&gpio_initstruct);
}
