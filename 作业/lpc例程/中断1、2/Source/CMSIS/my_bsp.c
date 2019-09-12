
/* Includes ------------------------------------------------------------------*/
#include "my_include_H.h"
#include "bsp_led.h"
#include "my_bsp.h"
#include "bsp_timer.h"
#include "bsp_iic.h"



/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/


/***************************************************************************************
** ��������: NVIC_Configuration
** ��������: stm32f10x���û��������ж�
** ��    ��: None
** �� �� ֵ: None       
****************************************************************************************/
void NVIC_Configuration(void)
{
	#ifdef USE_IAP
	 //---Set the Vector Table base location at 0x2000
		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x2000);
	#else
  //---Set the Vector Table base location at 0x8000000
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x000);		// ��ӳ��������
	#endif
	// �ж����ȼ�����:ѡ��ʹ�����ȼ������4��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);		// ����/��Ӧ���ȼ�����(16 * 0)---����16���׼�
}

/********************************************************************************************************
*	�� �� ��: ALL_GPIO_Ini
*	����˵��: ��ʼ������GPIOΪĬ��״̬
*	��    �Σ���
*	�� �� ֵ: ��
********************************************************************************************************/
void ALL_GPIO_Ini(void)
{
		GPIO_DeInit(GPIOA);
		GPIO_DeInit(GPIOB);
		GPIO_DeInit(GPIOC);
		GPIO_DeInit(GPIOD);
		GPIO_DeInit(GPIOE);
		GPIO_DeInit(GPIOF);
		GPIO_DeInit(GPIOG);
		GPIO_DeInit(GPIOH);
		GPIO_DeInit(GPIOI);
		
		//GPIO_PinAFConfig(GPIOB, GPIO_Pin_9, GPIO_AF_RTC_50Hz);
}

RCC_ClocksTypeDef RCC_ClocksStatus;
/********************************************************************************************************
*	�� �� ��: RCC_ReConfig
*	����˵��: ϵͳʱ���������������
*	��    �Σ���
*	�� �� ֵ: ��
********************************************************************************************************/
void RCC_ReConfig(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);	//Enable CRC clock
	RCC_GetClocksFreq(&RCC_ClocksStatus);
	
}


/********************************************************************************************************
*	�� �� ��: Init_Board
*	����˵��: Power on initialization, onboard hardware peripherals
*	��    �Σ���
*	�� �� ֵ: ��
********************************************************************************************************/
void Init_Board(void)
{

	Close_TI();
	RCC_ReConfig();				//ϵͳʱ������ 
	NVIC_Configuration();				//�����ж�����	
	Open_TI();
	
	//Timer_InitHard(TIM2, 1680, 100, 3);//�������:1ms	
	bsp_InitTimer();
	
	ALL_GPIO_Ini();
	IIC_InitHard();
	
	
	Led_InitHard();
	
	
}

/************************************END OF FILE*****************************************/
