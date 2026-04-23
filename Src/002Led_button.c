/*
 * 002Led_button.c
 *
 *  Created on: Apr 23, 2026
 *      Author: Himanshu Singh
 */

#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"

#define LOW            0
#define BTN_PRESSED     LOW

void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}
int main()
{
	GPIO_Handle_t GpioLed, GPIOBtn;

	 // Led configuration initialization
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed);

	// Intialize Push button on board

	GPIOBtn.pGPIOx = GPIOC;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	//GPIOBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOC, ENABLE);

	GPIO_Init(&GPIOBtn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == BTN_PRESSED){

			delay();

 		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);


		}
	}

}
