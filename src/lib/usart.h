#ifndef _USART_H
#define _USART_H

#include <string>
#include "stm32f4xx_usart.h"
#include "gpio.h"

#define APB2_Prescaler 2

class USART
{

public:
	USART(USART_TypeDef* type, GPIO* tx, GPIO* rx);
	void init(uint32_t baudrate);
	void send(const char byte);
	void send(const char* msg);
	void interrupt(void (*callback)(const char byte));

private:
	USART_TypeDef* type;
	GPIO* tx;
	GPIO* rx;

};

extern "C"
{
	void USART1_IRQHandler();
}

#endif
