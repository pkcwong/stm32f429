#ifndef _LED_H
#define _LED_H

#include "gpio.h"

class LED
{

public:
	LED(GPIO* gpio);
	void init();
	void on();
	void off();
	void toggle();

private:
	GPIO* gpio;

};

#endif
