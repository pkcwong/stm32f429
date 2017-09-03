#include "gpio.h"

GPIO::GPIO(GPIO_TypeDef* _GPIO_, uint16_t Pin)
{
	this->_GPIO_ = _GPIO_;
	this->GPIO_InitStructure.GPIO_Pin = Pin;
}

void GPIO::init(GPIOMode_TypeDef GPIO_Mode, GPIOSpeed_TypeDef GPIO_Speed, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd)
{
	if (this->_GPIO_ == GPIOA)
	{
		RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	}
	else if (this->_GPIO_ == GPIOB)
	{
		RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	}
	else if (this->_GPIO_ == GPIOC)
	{
		RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	}
	else if (this->_GPIO_ == GPIOD)
	{
		RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	}
	else if (this->_GPIO_ == GPIOE)
	{
		RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	}
	else if (this->_GPIO_ == GPIOF)
	{
		RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	}
	else if (this->_GPIO_ == GPIOG)
	{
		RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
	}
	this->GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
	this->GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
	this->GPIO_InitStructure.GPIO_OType = GPIO_OType;
	this->GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd;
	GPIO_Init(this->_GPIO_, &(this->GPIO_InitStructure));
}

GPIO_TypeDef* GPIO::get_Port()
{
	return this->_GPIO_;
}

uint16_t GPIO::get_Pin()
{
	return this->GPIO_InitStructure.GPIO_Pin;
}

uint8_t GPIO::get_PinSource()
{
	switch(this->GPIO_InitStructure.GPIO_Pin)
	{
		case GPIO_Pin_0:
			return GPIO_PinSource0;
		case GPIO_Pin_1:
			return GPIO_PinSource1;
		case GPIO_Pin_2:
			return GPIO_PinSource2;
		case GPIO_Pin_3:
			return GPIO_PinSource3;
		case GPIO_Pin_4:
			return GPIO_PinSource4;
		case GPIO_Pin_5:
			return GPIO_PinSource5;
		case GPIO_Pin_6:
			return GPIO_PinSource6;
		case GPIO_Pin_7:
			return GPIO_PinSource7;
		case GPIO_Pin_8:
			return GPIO_PinSource8;
		case GPIO_Pin_9:
			return GPIO_PinSource9;
		case GPIO_Pin_10:
			return GPIO_PinSource10;
		case GPIO_Pin_11:
			return GPIO_PinSource11;
		case GPIO_Pin_12:
			return GPIO_PinSource12;
		case GPIO_Pin_13:
			return GPIO_PinSource13;
		case GPIO_Pin_14:
			return GPIO_PinSource14;
		case GPIO_Pin_15:
			return GPIO_PinSource15;
	}
	return 0;
}
