#include "drv_led.h"



//LED端口资源数组定义
GPIO_TypeDef *LED_GPIO_PORT[LEDn] = { LED2_GPIO_PORT, LED3_GPIO_PORT };
const INT16U    LED_GPIO_PIN[LEDn] = { LED2_PIN, LED3_PIN };
const INT32U    LED_GPIO_CLK[LEDn] = { LED2_GPIO_CLK, LED3_GPIO_CLK };

//============================================================================
// 名称：drv_led_init
// 功能：所有LED口线初始化
// 参数：无
// 返回：无
// 说明：系统初始化时调用
//============================================================================
void drv_led_init( void )
{
    INT8U i;
    GPIO_InitTypeDef  GPIO_InitStructure;

    for( i = 0; i < LEDn; i++ )                             //逐个灯初始化
    {
        RCC_AHB1PeriphClockCmd(LED_GPIO_CLK[i], ENABLE);

        GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN[i];
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;    //GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

        GPIO_Init(LED_GPIO_PORT[i], &GPIO_InitStructure);

        drv_led_off((LedType )i);//关灯
    }
}

//============================================================================
// 名称：drv_led_on
// 功能：LED亮
// 参数：Led：LED编号，LED1~LEDn
// 返回：无
// 说明：无
//============================================================================
void drv_led_on( LedType Led )
{
    LED_GPIO_PORT[Led]->BSRRH = LED_GPIO_PIN[Led];
}

//============================================================================
// 名称：drv_led_off
// 功能：LED灭
// 参数：Led：LED编号，LED1~LEDn
// 返回：无
// 说明：无
//============================================================================
void drv_led_off( LedType Led )
{
    LED_GPIO_PORT[Led]->BSRRL = LED_GPIO_PIN[Led];
}

//============================================================================
// 名称：drv_led_toggle
// 功能：LED状态翻转
// 参数：Led：LED编号，LED1~LEDn
// 返回：无
// 说明：无
//============================================================================
void drv_led_toggle( LedType Led )
{
    LED_GPIO_PORT[Led]->ODR ^= LED_GPIO_PIN[Led];
}


