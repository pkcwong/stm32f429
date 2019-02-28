#ifndef _BUTTON_H
#define _BUTTON_H

#include "gpio.h"

class BUTTON
{

public:
	BUTTON(GPIO* gpio, GPIOPuPd_TypeDef pull);
	void init();
	bool read();

private:
	GPIO* gpio;
	GPIOPuPd_TypeDef pull;

};

#endif
