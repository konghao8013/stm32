#ifndef __BSP_GPIO_LED_EX_H
#define	__BSP_GPIO_LED_EX_H

#include "stm32f10x.h"

/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的LED引脚 */
// 外部扩展LED1
#define LED1_LED_EX_GPIO_PORT    			GPIOB			                /* GPIO端口 */
 #define LED1_LED_EX_GPIO_CLK_PORT 	        RCC_APB2Periph_GPIOB			/* GPIO端口时钟 */
#define LED1_LED_EX_GPIO_PIN			    GPIO_Pin_13	       				/* 连接到GPIO */

// 外部扩展LED2
#define LED2_LED_EX_GPIO_PORT    			GPIOB			                /* GPIO端口 */
#define LED2_LED_EX_GPIO_CLK_PORT 	        RCC_APB2Periph_GPIOB			/* GPIO端口时钟 */
#define LED2_LED_EX_GPIO_PIN		        GPIO_Pin_14			        	/* 连接到GPIO */

// 外部扩展LED3
#define LED3_LED_EX_GPIO_PORT    			GPIOB			                /* GPIO端口 */
#define LED3_LED_EX_GPIO_CLK_PORT 	        RCC_APB2Periph_GPIOB			/* GPIO端口时钟 */
#define LED3_LED_EX_GPIO_PIN			    GPIO_Pin_15			            /* 连接到GPIO */


/** 触发 外部扩展LED 条件 
  * 0 - off
  * 1 - on
  */
  
#define LED1_LED2_LED3_LED_ON  1
#define LED1_LED2_LED3_LED_OFF 0

/* 使用标准的固件库控制IO*/
#define LED1_LED_EX(A)	if (A)  GPIO_ResetBits(LED1_LED_EX_GPIO_PORT,LED1_LED_EX_GPIO_PIN);   \
                        else      GPIO_SetBits(LED1_LED_EX_GPIO_PORT,LED1_LED_EX_GPIO_PIN)

#define LED2_LED_EX(A)	if (A)	GPIO_ResetBits(LED2_LED_EX_GPIO_PORT,LED2_LED_EX_GPIO_PIN);   \
                        else      GPIO_SetBits(LED2_LED_EX_GPIO_PORT,LED2_LED_EX_GPIO_PIN)

#define LED3_LED_EX(A)	if (A)	GPIO_ResetBits(LED3_LED_EX_GPIO_PORT,LED3_LED_EX_GPIO_PIN);   \
                        else	  GPIO_SetBits(LED3_LED_EX_GPIO_PORT,LED3_LED_EX_GPIO_PIN)

/* 直接操作寄存器的方法控制IO */
#define	    DIGITALHI(P,I)		    {P->BSRR	=I;}	    //输出为高电平		
#define     DIGITALLO(P,I)		    {P->BRR     =I;}	    //输出低电平
#define DIGITALTLGGLE(P,I)          {P->ODR    ^=I;}        //输出反转状态

/* 定义控制IO的宏 */
#define LED1_LED_EX_TOGGLE      DIGITALTLGGLE(LED1_LED_EX_GPIO_PORT,LED1_LED_EX_GPIO_PIN)
#define LED1_LED_EX_OFF		        DIGITALLO(LED1_LED_EX_GPIO_PORT,LED1_LED_EX_GPIO_PIN)
#define LED1_LED_EX_ON		        DIGITALHI(LED1_LED_EX_GPIO_PORT,LED1_LED_EX_GPIO_PIN)

#define LED2_LED_EX_TOGGLE		DIGITALTLGGLE(LED2_LED_EX_GPIO_PORT,LED2_LED_EX_GPIO_PIN)
#define LED2_LED_EX_OFF		        DIGITALLO(LED2_LED_EX_GPIO_PORT,LED2_LED_EX_GPIO_PIN)
#define LED2_LED_EX_ON			    DIGITALHI(LED2_LED_EX_GPIO_PORT,LED2_LED_EX_GPIO_PIN)
                                                                  
#define LED3_LED_EX_TOGGLE		DIGITALTLGGLE(LED3_LED_EX_GPIO_PORT,LED3_LED_EX_GPIO_PIN)
#define LED3_LED_EX_OFF		        DIGITALLO(LED3_LED_EX_GPIO_PORT,LED3_LED_EX_GPIO_PIN)
#define LED3_LED_EX_ON			    DIGITALHI(LED3_LED_EX_GPIO_PORT,LED3_LED_EX_GPIO_PIN)

/* 单灯操作 */
//外部扩展LED1
#define LED1_LED_EX_ON_ONLY                 LED1_LED_EX_ON    \
                                            LED2_LED_EX_OFF   \
                                            LED3_LED_EX_OFF

//外部扩展LED2
#define LED2_LED_EX_ON_ONLY		            LED1_LED_EX_OFF   \
                                            LED2_LED_EX_ON    \
                                            LED3_LED_EX_OFF
					
//外部扩展LED3
#define LED3_LED_EX_ON_ONLY	                LED1_LED_EX_OFF   \
                                            LED2_LED_EX_OFF   \
                                            LED3_LED_EX_ON
					
//外部扩展LED全亮
#define LED1_LED2_LED3_LED_EX_ALL_ON        LED1_LED_EX_ON    \
                                            LED2_LED_EX_ON    \
                                            LED3_LED_EX_ON
					               
//外部扩展LED全灭
#define LED1_LED2_LED3_LED_EX_ALL_OFF       LED1_LED_EX_OFF   \
                                            LED2_LED_EX_OFF   \
                                            LED3_LED_EX_OFF

void LED_EX_GPIO_Config(void);

#endif /* __BSP_GPIO_LED_EX_H */
