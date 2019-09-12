
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
** 函数名称: NVIC_Configuration
** 功能描述: stm32f10x配置基本向量中断
** 参    数: None
** 返 回 值: None       
****************************************************************************************/
void NVIC_Configuration(void)
{
	#ifdef USE_IAP
	 //---Set the Vector Table base location at 0x2000
		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x2000);
	#else
  //---Set the Vector Table base location at 0x8000000
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x000);		// 重映射向量表
	#endif
	// 中断优先级分组:选择使用优先级分组第4组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);		// 抢断/响应优先级配置(16 * 0)---分了16个阶级
}

/********************************************************************************************************
*	函 数 名: ALL_GPIO_Ini
*	功能说明: 初始化所有GPIO为默认状态
*	形    参：无
*	返 回 值: 无
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
*	函 数 名: RCC_ReConfig
*	功能说明: 系统时钟相关内容再配置
*	形    参：无
*	返 回 值: 无
********************************************************************************************************/
void RCC_ReConfig(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);	//Enable CRC clock
	RCC_GetClocksFreq(&RCC_ClocksStatus);
	
}


/********************************************************************************************************
*	函 数 名: Init_Board
*	功能说明: Power on initialization, onboard hardware peripherals
*	形    参：无
*	返 回 值: 无
********************************************************************************************************/
void Init_Board(void)
{

	Close_TI();
	RCC_ReConfig();				//系统时钟配置 
	NVIC_Configuration();				//向量中断配置	
	Open_TI();
	
	//Timer_InitHard(TIM2, 1680, 100, 3);//溢出周期:1ms	
	bsp_InitTimer();
	
	ALL_GPIO_Ini();
	IIC_InitHard();
	
	
	Led_InitHard();
	
	
}

/************************************END OF FILE*****************************************/
