This example project uses CMSIS and demonstrates 
the use of Systick in interrupt driven mode

LandTiger GPIO Example
/*********************** Design by PowerAVR *********************/
Design: www.PowerMCU.com
		www.PowerAVR.com
Board:  LandTiger Evaluation Board
Device: LPC1768
/*********************** Design by PowerAVR *********************/

Example functionality:                                                   
 - Clock Settings:
   - XTAL    =           12.00 MHz
   - SYSCLK  =          100.00 MHz

-- CMSIS ---------------------------------------------
SystemInit       called from startup_LPC17xx.s
SystemCoreClock  is 100000000Hz
SysTick          runs in interrupt mode

JP8 jumper 
			Open:   LED disabled    
			Short:	LED active (default)
/****************************************************************/
·�������� GPIOʵ��

��������ǽ�·���������ϵİ˸�LED��������100���룬
����SYStick ��ʱ���жϷ�ʽ����ʱ  ϵͳʱ��������100MHZ
ʹ��ʱ����·JP8����ʹ��LED��
