#ifndef _GPIO_H
#define _GPIO_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

class GPIO
{

	private:
	GPIO_TypeDef* _GPIO_;
	GPIO_InitTypeDef GPIO_InitStructure;

	public:
	GPIO(GPIO_TypeDef* _GPIO_, uint16_t Pin);
	void init(GPIOMode_TypeDef GPIO_Mode, GPIOSpeed_TypeDef GPIO_Speed, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd);
	GPIO_TypeDef* get_Port();
	uint16_t get_Pin();
	uint8_t get_PinSource();

};

#endif
