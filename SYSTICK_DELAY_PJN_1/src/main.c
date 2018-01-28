/**
  ******************************************************************************
  * @file    main.c
  * @author  Prashant Jagannath Namekar
  * @version V1.0
  * @date    01-December-2016
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm324xg_eval.h"
#include "LED_SW_PJN.h"

__IO static uint32_t delay_time;
uint32_t toggle;



int main(void)
{
	SWITCH_CONFIG_PJN();
	LED_CONFIG_PJN();
	SysTick_Config(SystemCoreClock/1000);



	for(;;);
}






void SysTick_Handler(void)
{
delay_time++;

if(delay_time==1000)
{
	toggle=~toggle;
    GPIO_WriteBit(GPIOC,GPIO_Pin_7,toggle);
	delay_time=0;
}
}

