#include "gpio.h"

GPIO::GPIO(GPIO_TypeDef* port, uint16_t pin)
{
	this->port = port;
	this->structure.GPIO_Pin = pin;
}

void GPIO::init(GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed, GPIOOType_TypeDef output, GPIOPuPd_TypeDef pull)
{
	uint32_t RCC_AHB1Periph;
	if (this->port == GPIOA)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOA;
	}
	if (this->port == GPIOB)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOB;
	}
	if (this->port == GPIOC)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOC;
	}
	if (this->port == GPIOD)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOD;
	}
	if (this->port == GPIOE)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOE;
	}
	if (this->port == GPIOF)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOF;
	}
	if (this->port == GPIOG)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOG;
	}
	if (this->port == GPIOH)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOH;
	}
	if (this->port == GPIOI)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOI;
	}
	if (this->port == GPIOJ)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOJ;
	}
	if (this->port == GPIOK)
	{
		RCC_AHB1Periph = RCC_AHB1Periph_GPIOK;
	}
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph, ENABLE);
	this->structure.GPIO_Mode = mode;
	this->structure.GPIO_OType = output;
	this->structure.GPIO_PuPd = pull;
	GPIO_Init(this->port, &this->structure);
}

void GPIO::set()
{
	GPIO_SetBits(this->port, this->structure.GPIO_Pin);
}

void GPIO::reset()
{
	GPIO_ResetBits(this->port, this->structure.GPIO_Pin);
}

void GPIO::toggle()
{
	GPIO_ToggleBits(this->port, this->structure.GPIO_Pin);
}

bool GPIO::read()
{
	if (this->structure.GPIO_Mode == GPIO_Mode_OUT)
	{
		return GPIO_ReadOutputDataBit(this->port, this->structure.GPIO_Pin);
	}
	else
	{
		return GPIO_ReadInputDataBit(this->port, this->structure.GPIO_Pin);
	}
}

GPIO_TypeDef* GPIO::getPort()
{
	return this->port;
}

uint8_t GPIO::getPinSource()
{
	switch(this->structure.GPIO_Pin)
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
