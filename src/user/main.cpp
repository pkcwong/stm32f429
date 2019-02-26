#include "main.h"

int main(void)
{
	DS0.init();
	DS1.init();
	while (1)
	{
		DS0.on();
		DS1.on();
	}
}
