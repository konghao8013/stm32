#ifndef __LED_H
#define __LED_H


void RCC_GPIO_CMD(void);
void GPIOA_IO_LED_OFF(unsigned int io_num);
void GPIOA_IO_LED_ON(unsigned int io_num);
void GPIOA_IO_CMD(unsigned int io_num);

#endif
