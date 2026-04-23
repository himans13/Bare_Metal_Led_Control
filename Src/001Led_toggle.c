/*
 * 001Led_toggle.c
 *
 *  Created on: Apr 21, 2026
 *      Author: Himanshu Singh
 */

#include "stm32f446xx.h"
//#include "stm32f446xx_gpio_driver.h"

void delay(void)
{
	for(volatile uint32_t i = 0; i < 500000; i++);
}

int main()
{
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed);

	GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_SET);
	while(1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		//delay();
	}

	return 0;
}

