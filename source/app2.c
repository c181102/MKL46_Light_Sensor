#include <MKL46Z4.h>
#include "light_sensor.h"
#include "uart.h"
#include "pit.h"

uint16_t data;

static void UART_Rx_Callback(uint8_t ch)
{
	if (ch == 'S')
	{
		light_display_data();
	}
	else
	{
		UART0_SendString("\nInvalid command!\n", sizeof("\nInvalid command!\n"), 0);
	}
}

static void Timer_Callback(PIT_Channel_Type channel)
{
	data = light_get_data();
	light_push_data(data);
}

PIT_Config_Type timer_config = {
		.chain		= PIT_CHN_NOT_CHAINED,
		.tie		= PIT_TIE_ENABLE,
		.pCallback	= &Timer_Callback,
		.timeout	= 1000,
};

UART_Config_Type uart_config = {
		.baudrate = 9600,
		.dataLength = UART_DATA_8BIT,
		.MsbLsb = UART_LSB_FIRST,
		.stopBit = UART_SBNS_1BIT,
		.parity = UART_PARITY_NONE,
		.txEnable = true,
		.rxEnable = true,
		.tx = {PORTA, 2U},
		.rx = {PORTA, 1U},
		.RxCallback = &UART_Rx_Callback,
};

int main()
{
	UART0_Init(&uart_config);
	UART0_SendString("\nAPPLICATION 1\n", sizeof("\nAPPLICATION 1\n"), 0);
	NVIC_SetPriority(UART0_IRQn, 1);

	PIT_Init(PIT_CHANNEL_0, &timer_config);
	NVIC_SetPriority(PIT_IRQn, 0);

	light_sensor_init();

	PIT_StartTimer(PIT_CHANNEL_0);

	UART0_ReceiveCharNonBlocking();

	while(1)
	{

	}
}
