/**************************************************************************//**
 * @file     main.c
 * @brief    CMSIS Cortex-M3 GPIO example
 *           a LED using CM3 SysTick
 * @version  V1.30
 * @date     24. Jan 2010
 *
 * @note
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#include <stdint.h>
#include "LPC17xx.h"



int main (void) {
	LPC_SC->PCONP|=(0x01<<1);      //��TIMER0����ʱ��
	LPC_TIM0->MR0=59990;           //PLLʱ��Ƶ��Ϊ60MHZ
	LPC_TIM0->MCR=3;               //����ƥ���жϣ���λ�ж�
	NVIC_EnableIRQ(TIMER0_IRQn);   //��ʱ���ж�ʹ��
	LPC_TIM0->TCR=1;               //������ʱ��
	
//  while (1) {}
}

void TIMER0_IRQHandler(void){
	printf("Hello World\n");       //�����ж�ʱ����ӡ����
}

