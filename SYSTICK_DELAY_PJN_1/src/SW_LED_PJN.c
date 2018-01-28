/**
  ******************************************************************************
  * @file    SW_LED_PJN.c
  * @author  PRASHANT JAGANNATH NAMEKAR
  * @version V1.0
  * @date    05-10-2016
  * @brief   This file consist the configuration of the SWITCH and LED connected
  * to the STM3240G board. SWITCH is connected to the PG15 pin.
  * LED connected to the PC7 pin.
  ******************************************************************************
*/

#include "stm324xg_eval.h"
#include "LED_SW_PJN.h"




GPIO_InitTypeDef gpio_pjn;  // structure declaration consisting the configuration of gpio.
GPIO_InitTypeDef gpio_pjn1;






//Configuring the PIN connected to the SWITCH


void SWITCH_CONFIG_PJN(void)
{
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG,ENABLE); // Enabling the clock of PORTG connected to AHB1 BUS
gpio_pjn.GPIO_Pin=GPIO_Pin_15;         //selecting the PIN
gpio_pjn.GPIO_Mode=GPIO_Mode_IN;       //Making it as an input PORT
gpio_pjn.GPIO_PuPd=GPIO_PuPd_UP;     //
GPIO_Init(GPIOG,&gpio_pjn);   //Passing the configuration
}


// Configuring the LED PORT
void LED_CONFIG_PJN(void)
{
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
gpio_pjn1.GPIO_Pin=GPIO_Pin_7;
gpio_pjn1.GPIO_Mode=GPIO_Mode_OUT;
gpio_pjn1.GPIO_OType=GPIO_OType_PP;
gpio_pjn1.GPIO_Speed=GPIO_Speed_2MHz;
GPIO_Init(GPIOC,&gpio_pjn1);

}
