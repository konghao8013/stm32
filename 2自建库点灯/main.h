#ifndef __MAIN_H
#define __MAIN_H

#define GPIO_PIN_0		(unsigned int)(0)
#define GPIO_PIN_1		(unsigned int)(1)
#define GPIO_PIN_2		(unsigned int)(2)
#define GPIO_PIN_3		(unsigned int)(3)
#define GPIO_PIN_4		(unsigned int)(4)
#define GPIO_PIN_5		(unsigned int)(5)
#define GPIO_PIN_6		(unsigned int)(6)
#define GPIO_PIN_7		(unsigned int)(7)
#define GPIO_PIN_8		(unsigned int)(8)
#define GPIO_PIN_9		(unsigned int)(9)
#define GPIO_PIN_10		(unsigned int)(10)
#define GPIO_PIN_11		(unsigned int)(11)
#define GPIO_PIN_12		(unsigned int)(12)
#define GPIO_PIN_13		(unsigned int)(13)
#define GPIO_PIN_14		(unsigned int)(14)
#define GPIO_PIN_15		(unsigned int)(15)




#define PERIPH_BASE 		((unsigned int)0x40000000)
#define APB2_PERIPH_BASE 	(PERIPH_BASE+0x10000)
#define GPIOA_BASE 			(APB2_PERIPH_BASE+0x800)
#define RCC_BASE 			(PERIPH_BASE+0x21000)


#define RCC_APB2ENR 			*(unsigned int *)(RCC_BASE+0x18)
#define GPIOA_ODR 			*(unsigned int *)(GPIOA_BASE+0xC)
#define GPIOA_CRL 			*(unsigned int *)(GPIOA_BASE+0x00)

#endif
