/**
*****************************************************************************
**
**  File        : serial_io.c
**
**  Abstract    : System Workbench functions to set the serial port as
**  			  characters input/output
**
**  Environment : System Workbench for MCU
**
**  Distribution: The file is distributed “as is,” without any warranty
**                of any kind.
**
*****************************************************************************
**
** <h2><center>&copy; COPYRIGHT(c) 2014 Ac6</center></h2>
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**   1. Redistributions of source code must retain the above copyright notice,
**      this list of conditions and the following disclaimer.
**   2. Redistributions in binary form must reproduce the above copyright notice,
**      this list of conditions and the following disclaimer in the documentation
**      and/or other materials provided with the distribution.
**   3. Neither the name of Ac6 nor the names of its contributors
**      may be used to endorse or promote products derived from this software
**      without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
** DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
** CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
** OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
*****************************************************************************
*/


#include "stm324xg_eval.h"
			

#include "serial_io.h"

int __io_putchar(int ch) __attribute__((weak, alias ("__serial_io_putchar")));
int __io_getchar(void) __attribute__((weak, alias ("__serial_io_getchar")));

void __serial_io_init() {
	USART_InitTypeDef USART_InitStructure;

	/*## Configure the UART peripheral ##############################*/
	/* Put the USART peripheral in the Asynchronous mode (UART Mode) */
	/* UART configured as follow:
		- BaudRate = 115200 baud
		- Word Length = 8 Bits
		- Stop Bit = One Stop bit
		- Parity = none
		- Hardware flow control disabled (RTS and CTS signals) */
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	STM_EVAL_COMInit(COM1, &USART_InitStructure);

	// This is just to keep Eclipse happy, but generates no code; without this
	// Eclipse will generate an "unused" warning for the weak declarations above.
	if (0) __io_putchar(__io_getchar());
}


int __serial_io_putchar(int ch) {
	/* Write a character to the EVAL_COM1 and Loop until transmitted */
	while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_TXE) == RESET) {}
	USART_SendData(EVAL_COM1, (uint8_t)ch);
	return 0;
}

int __serial_io_getchar(void) {
	/* Read a character from the EVAL_COM1 and Loop until received */
	while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_RXNE) == RESET) {}
	return USART_ReceiveData(EVAL_COM1);
}
