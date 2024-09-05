
#include "main.h"
#include "LED.h"

void RCC_GPIO_CMD(void)
{
	RCC_APB2ENR |= (0x1<<2);
}

void GPIOA_IO_LED_OFF(unsigned int io_num){
	GPIOA_ODR |= (0x1<<io_num);
}

void GPIOA_IO_LED_ON(unsigned int io_num){
	GPIOA_ODR &=~ (0x1<<io_num);
}

void GPIOA_IO_CMD(unsigned int io_num)
{
	GPIOA_CRL |= (0x3<<(4*io_num));
}

