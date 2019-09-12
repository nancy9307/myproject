#include "drv_led.h"



//LED�˿���Դ���鶨��
GPIO_TypeDef *LED_GPIO_PORT[LEDn] = { LED2_GPIO_PORT, LED3_GPIO_PORT };
const INT16U    LED_GPIO_PIN[LEDn] = { LED2_PIN, LED3_PIN };
const INT32U    LED_GPIO_CLK[LEDn] = { LED2_GPIO_CLK, LED3_GPIO_CLK };

//============================================================================
// ���ƣ�drv_led_init
// ���ܣ�����LED���߳�ʼ��
// ��������
// ���أ���
// ˵����ϵͳ��ʼ��ʱ����
//============================================================================
void drv_led_init( void )
{
    INT8U i;
    GPIO_InitTypeDef  GPIO_InitStructure;

    for( i = 0; i < LEDn; i++ )                             //����Ƴ�ʼ��
    {
        RCC_AHB1PeriphClockCmd(LED_GPIO_CLK[i], ENABLE);

        GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN[i];
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;    //GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

        GPIO_Init(LED_GPIO_PORT[i], &GPIO_InitStructure);

        drv_led_off((LedType )i);//�ص�
    }
}

//============================================================================
// ���ƣ�drv_led_on
// ���ܣ�LED��
// ������Led��LED��ţ�LED1~LEDn
// ���أ���
// ˵������
//============================================================================
void drv_led_on( LedType Led )
{
    LED_GPIO_PORT[Led]->BSRRH = LED_GPIO_PIN[Led];
}

//============================================================================
// ���ƣ�drv_led_off
// ���ܣ�LED��
// ������Led��LED��ţ�LED1~LEDn
// ���أ���
// ˵������
//============================================================================
void drv_led_off( LedType Led )
{
    LED_GPIO_PORT[Led]->BSRRL = LED_GPIO_PIN[Led];
}

//============================================================================
// ���ƣ�drv_led_toggle
// ���ܣ�LED״̬��ת
// ������Led��LED��ţ�LED1~LEDn
// ���أ���
// ˵������
//============================================================================
void drv_led_toggle( LedType Led )
{
    LED_GPIO_PORT[Led]->ODR ^= LED_GPIO_PIN[Led];
}


