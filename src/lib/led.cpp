#include "led.h"

LED::LED(GPIO* gpio)
{
	this->gpio = gpio;
}

void LED::init()
{
	this->gpio->init(GPIO_Mode_OUT, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL);
}

void LED::on()
{
	this->gpio->reset();
}

void LED::off()
{
	this->gpio->set();
}

void LED::toggle()
{
	this->gpio->toggle();
}
