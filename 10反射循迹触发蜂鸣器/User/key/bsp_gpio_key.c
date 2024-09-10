#include "stm32f10x.h"
#include "key/bsp_gpio_key.h"

void KEY_GPIO_Config(){
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