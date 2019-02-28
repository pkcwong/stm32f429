#ifndef _GPIO_H
#define _GPIO_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

class GPIO
{

public:
	GPIO(GPIO_TypeDef* GPIO_PORT, uint16_t Pin);
	void init(GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed, GPIOOType_TypeDef output, GPIOPuPd_TypeDef pull);
	void set();
	void reset();
	void toggle();
	bool read();

private:
	GPIO_TypeDef* port;
	GPIO_InitTypeDef structure;

};

#endif
