#include "uart.h"

UART::UART(USART_TypeDef* _USART_, GPIO* TX, GPIO* RX)
{
	this->_USART_ = _USART_;
	this->TX = TX;
	this->RX = RX;
}

void UART::init(uint32_t BaudRate)
{
	USART_InitTypeDef USART_InitStructure;
	if (this->_USART_ == USART1)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
		GPIO_PinAFConfig(this->TX->get_Port(), this->TX->get_PinSource(), GPIO_AF_USART1);
		GPIO_PinAFConfig(this->RX->get_Port(), this->RX->get_PinSource(), GPIO_AF_USART1);
	}
	else if (this->_USART_ == USART2)
	{
		RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
		GPIO_PinAFConfig(this->TX->get_Port(), this->TX->get_PinSource(), GPIO_AF_USART2);
		GPIO_PinAFConfig(this->RX->get_Port(), this->RX->get_PinSource(), GPIO_AF_USART2);
	}
	else if (this->_USART_ == USART3)
	{
		RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
		GPIO_PinAFConfig(this->TX->get_Port(), this->TX->get_PinSource(), GPIO_AF_USART3);
		GPIO_PinAFConfig(this->RX->get_Port(), this->RX->get_PinSource(), GPIO_AF_USART3);
	}
	TX->init(GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP);
	RX->init(GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP);
	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1, ENABLE);
}

void UART::interrupt(void (*callback)(const char byte))
{
	NVIC_InitTypeDef NVIC_InitStruct;
	USART_ITConfig(this->_USART_, USART_IT_RXNE, ENABLE);
	if (this->_USART_ == USART1)
	{
		NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	}
	else if (this->_USART_ == USART2)
	{
		NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;
	}
	else if (this->_USART_ == USART3)
	{
		NVIC_InitStruct.NVIC_IRQChannel = USART3_IRQn;
	}
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);
}

void UART::tx_byte(const char byte)
{
	while (USART_GetFlagStatus(this->_USART_, USART_FLAG_TXE) == RESET);
	USART_SendData(this->_USART_, byte);
}

void UART::tx(const char* data, ...)
{
	
}
