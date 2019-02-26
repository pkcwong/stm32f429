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
