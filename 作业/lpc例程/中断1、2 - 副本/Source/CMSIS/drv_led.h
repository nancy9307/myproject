#ifndef __DRV_LED_H__
#define __DRV_LED_H__

#include "stm32f4xx.h"
#include "typedefine.h"


//-------------------------------------------------------------------
//                          指示灯相关定义
//-------------------------------------------------------------------
#define LEDn                             2

#define LED2_PIN                         GPIO_Pin_3
#define LED2_GPIO_PORT                   GPIOE
#define LED2_GPIO_CLK                    RCC_AHB1Periph_GPIOE

#define LED3_PIN                         GPIO_Pin_4
#define LED3_GPIO_PORT                   GPIOE
#define LED3_GPIO_CLK                    RCC_AHB1Periph_GPIOE

typedef enum
{
    LED2 = 0,
    LED3 = 1,
} LedType;

//-------------------------------------------------------------------
//                              函数声明
//-------------------------------------------------------------------
extern void drv_led_init( void );
extern void drv_led_on( LedType Led );
extern void drv_led_off( LedType Led );
extern void drv_led_toggle( LedType Led );


#endif

