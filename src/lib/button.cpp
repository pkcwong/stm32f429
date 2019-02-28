#include "button.h"

BUTTON::BUTTON(GPIO* gpio, GPIOPuPd_TypeDef pull)
{
	this->gpio = gpio;
	this->pull = pull;
}

void BUTTON::init()
{
	this->gpio->init(GPIO_Mode_IN, GPIO_Speed_50MHz, GPIO_OType_PP, this->pull);
}

bool BUTTON::read()
{
	return !(this->pull == GPIO_PuPd_DOWN) ^ this->gpio->read();
}
