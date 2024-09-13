#include "stm32f10x.h"
#include "key/bsp_gpio_key.h"


/**
  * @brief  初始化
  * @param  无 
  * @note   无
  * @retval 无
  */
void KEY_GPIO_Config(void){
	
	GPIO_InitTypeDef gpio_initstruct = {0};    
	/*定义一个中断控制器结构体*/
	NVIC_InitTypeDef nvic_initstruct={0};
	
	/*定义一个中断控制器结构体*/
	EXTI_InitTypeDef exti_initstruct={0};
	
	
    /*开启时钟*/    
	RCC_APB2PeriphClockCmd(WKUP_KEY1_GPIO_CLK_PORT,ENABLE);	
		/*开启Key相关的GPIO外设/端口复用时钟*/
	RCC_APB2PeriphClockCmd(WKUP_KEY1_KEY_IN_GPIO_EXTI_CLK_PORT,ENABLE);
	
	/*配置中断源*/
	nvic_initstruct.NVIC_IRQChannel=WKUP_KEY1_KEY_IN_GPIO_EXTI_IRQ;
	/*配置抢占优先级*/
	nvic_initstruct.NVIC_IRQChannelPreemptionPriority=1;
	/*配置响应优先级*/
	nvic_initstruct.NVIC_IRQChannelSubPriority=0;
	/*使能配置中断通道*/
	nvic_initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&nvic_initstruct);
	
	  //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_initstruct.GPIO_Pin = WKUP_KEY1_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(WKUP_KEY1_GPIO_PORT,&gpio_initstruct);
	
	
	exti_initstruct.EXTI_Line 		=WKUP_KEY1_KEY_IN_GPIO_EXTI_LINE;
	exti_initstruct.EXTI_Mode 		=EXTI_Mode_Interrupt;
	exti_initstruct.EXTI_Trigger 	=EXTI_Trigger_Falling;
	exti_initstruct.EXTI_LineCmd 	=ENABLE;
	EXTI_Init(&exti_initstruct);
	
	
	
	/*======第二个按键**/
	RCC_APB2PeriphClockCmd(WKUP_KEY2_GPIO_CLK_PORT,ENABLE);	
 
	/*选择要控制的GPIO引脚，设置GPIO模式为浮空输入，设置GPIO速率为50MHz*/ 
  
    
	
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_initstruct.GPIO_Pin = WKUP_KEY2_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(WKUP_KEY2_GPIO_PORT,&gpio_initstruct);


	

}

/**
  * @brief  配置中断IO口
  * @param  无 
  * @note   无
  * @retval 无
  */
void EXTI_KEY_GPIO_Config(void){
	GPIO_InitTypeDef gpio_initstruct = {0};
    
    /*开启时钟*/
    RCC_APB2PeriphClockCmd(WKUP_KEY1_GPIO_CLK_PORT,ENABLE);
	RCC_APB2PeriphClockCmd(WKUP_KEY2_GPIO_CLK_PORT,ENABLE);
	
 
	/*选择要控制的GPIO引脚，设置GPIO模式为浮空输入，设置GPIO速率为50MHz*/
    
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_initstruct.GPIO_Pin = WKUP_KEY1_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(WKUP_KEY1_GPIO_PORT,&gpio_initstruct);
    
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_initstruct.GPIO_Pin = WKUP_KEY2_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(WKUP_KEY2_GPIO_PORT,&gpio_initstruct);
}

/**
  * @brief  检查按键是否按下
  * @param   GPIOX:X 可以是 A,B,C,D,
  * @param  GPIO_PIN:待读取的端口位
  * @note   无
  * @retval KEY_OFF (没有按下按键)，KEY_ON(按下了按键)
  */
uint32_t KEY_SCAN(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
		{
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);		
			return KEY_ON;
		}
		return KEY_OFF;
}