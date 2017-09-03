#ifndef _UART_H
#define _UART_H

#include "stm32f4xx_usart.h"
#include "misc.h"
#include "gpio.h"

class UART
{

	private:
	USART_TypeDef* _USART_;
	GPIO* TX;
	GPIO* RX;

	public:
	void (*listener)(const char byte);
	UART(USART_TypeDef* _USART_, GPIO* TX, GPIO* RX);
	void init(uint32_t BaudRate);
	void interrupt(void (*callback)(const char byte));
	void tx_byte(const char byte);
	void tx(const char* data, ...);

};

#endif
