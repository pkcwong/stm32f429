#include "main.h"

int main(void)
{
	DS0.init();
	DS1.init();
	KEY0.init();
	while (1)
	{
		DS0.on();
		if (KEY0.read())
		{
			DS1.on();
		}
		else
		{
			DS1.off();
		}
	}
}
