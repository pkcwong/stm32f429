#include "main.h"

void echo(const char byte)
{
	COM1.send(byte);
}

int main(void)
{
	DS0.init();
	DS1.init();
	KEY0.init();
	COM1.init(9600);
	COM1.interrupt(&echo);
	DS0.on();
	while (1)
	{
		if (KEY0.read())
		{
			DS1.on();
			COM1.send('A');
		}
		else
		{
			DS1.off();
		}
	}
}
