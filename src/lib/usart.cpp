#include "usart.h"

void (*USART1_Handler)(const char byte) = 0;

USART::USART(USART_TypeDef* type, GPIO* tx, GPIO* rx)
{
	this->type = type;
	this->tx = tx;
	this->rx = rx;
}

void USART::init(uint32_t baudrate)
{
	this->tx->init(GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP);
	this->rx->init(GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP);
	USART_InitTypeDef USART_InitStructure;
	if (this->type == USART1)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
		GPIO_PinAFConfig(this->tx->getPort(), this->tx->getPinSource(), GPIO_AF_USART1);
		GPIO_PinAFConfig(this->rx->getPort(), this->rx->getPinSource(), GPIO_AF_USART1);
	}
	float temp = (float)(SystemCoreClock / APB2_Prescaler / (baudrate * 16));
	u16 mantissa = temp;
	u16 fraction = (temp - mantissa) * 16;
	mantissa <<= 4;
	mantissa += fraction;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(this->type, &USART_InitStructure);
	USART1->BRR = mantissa;
	USART_Cmd(this->type, ENABLE);
	USART_ITConfig(this->type, USART_IT_RXNE, ENABLE);
	NVIC_InitTypeDef NVIC_InitStruct;
	if (this->type == USART1)
	{
		NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	}
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);
}

void USART::send(const char byte)
{
	while (USART_GetFlagStatus(this->type, USART_FLAG_TXE) == RESET);
	USART_SendData(this->type, byte);
}

void USART::send(const char* msg)
{
	for (char* ptr = (char*) msg; *ptr != '\0'; ptr++)
	{
		this->send(*ptr);
	}
}

void USART::interrupt(void (*callback)(const char byte))
{
	if (this->type == USART1)
	{
		USART1_Handler = callback;
	}
}

void USART1_IRQHandler()
{
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
		if (USART1_Handler)
		{
			USART1_Handler((unsigned char) USART_ReceiveData(USART1));
		}
	}
}
