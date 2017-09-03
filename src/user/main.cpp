#include "main.h"

#include "gpio_config.h"
#include "uart_config.h"

int main(void)
{
	PB0.init(GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP);
	while (1)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_0);
	}
}
