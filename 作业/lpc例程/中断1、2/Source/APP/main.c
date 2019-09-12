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
#include "my_bsp.h"
//#include "bsp_led.h"
//#include "bsp_timer.h"
//#include "iic_protocol.h"
#define EINT0		0x00000001
#define EINT1		0x00000002
#define EINT2		0x00000004
#define EINT3		0x00000008

#define EINT0_EDGE	0x00000001
#define EINT1_EDGE	0x00000002
#define EINT2_EDGE	0x00000004
#define EINT3_EDGE	0x00000008

#define EINT0_RISING	0x00000001
#define EINT1_RISING	0x00000002
#define EINT2_RISING	0x00000004
#define EINT3_RISING	0x00000008

volatile uint32_t eint1_counter;               
volatile uint32_t eint2_counter;

void EINT1_IRQHandler (void) 
{
  LPC_SC->EXTINT = EINT1;
		
  eint1_counter++;
  if ( eint1_counter & 0x01 )	/* alternate the LED display */
  {
	LPC_GPIO2->FIOSET = 0x0000000F;	/* turn off P2.0~3 */	
	LPC_GPIO2->FIOCLR = 0x000000F0;	/* turn on P2.4~7 */
  }
  else
  {
	LPC_GPIO2->FIOSET = 0x000000F0;	/* turn on P2.0~3 */	
	LPC_GPIO2->FIOCLR = 0x0000000F;	/* turn off P2.4~7 */
  }

}
/*****************************************************************************

*****************************************************************************/
void EINT2_IRQHandler (void) 
{
  LPC_SC->EXTINT = EINT2;		/*清中断 */
  LPC_SC->EXTINT = EINT1;
		
  eint2_counter++;
  if ( eint2_counter & 0x01 )	/* alternate the LED display */
  {
	LPC_GPIO2->FIOSET = 0x0000000F;	/* turn off P2.0~3 */	
	LPC_GPIO2->FIOCLR = 0x000000F0;	/* turn on P2.4~7 */
  }
  else
  {
	LPC_GPIO2->FIOSET = 0x000000F0;	/* turn on P2.0~3 */	
	LPC_GPIO2->FIOCLR = 0x0000000F;	/* turn off P2.4~7 */
  }

}

/*****************************************************************************

*****************************************************************************/
void EINTInit( void )
{

  LPC_PINCON->PINSEL4 = 0x01400000;	/* set P2.10 as EINT0 and  P2.0~7 LED GPIO output */
  LPC_GPIO2->FIODIR = 0x000000FF;	/* port 2, bit 0~7 only */
  LPC_GPIO2->FIOCLR = 0x000000FF;	/* turn off LEDs */

  LPC_GPIOINT->IO2IntEnF = 0x200;	/* Port2.10 is falling edge. */
  LPC_SC->EXTMODE = 0x00000006;		/* INT0 edge trigger */
  LPC_SC->EXTPOLAR = 0;				/* INT0 is falling edge by default */

  NVIC_EnableIRQ(EINT1_IRQn);	//
  NVIC_EnableIRQ(EINT2_IRQn);	//
}


int main (void) {

 	
 // if (SysTick_Config(SystemCoreClock / 1000)) { /* Setup SysTick Timer for 1 msec interrupts  */
 //   while (1);                                  /* Capture error */
//  }
                             /* initialize system               */
	EINTInit();	 //	 初始化中断
//	Init_Board();
//	NVIC_Configuration();
  while (1);	

}



