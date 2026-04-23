/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: Apr 17, 2026
 *      Author: Himanshu Singh
 */

#include "stm32f446xx_gpio_driver.h"


/**
 * @brief  Enable or disable peripheral clock for a given GPIO port.
 * @param  pGPIOx : Base address of the GPIO port (GPIOA–GPIOH)
 * @param  EnorDi : ENABLE or DISABLE macros
 * @note   This function configures the corresponding bit in RCC AHB1ENR register.
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
   if(EnorDi == ENABLE)
   {
	   if(pGPIOx == GPIOA)
	   {
		   GPIOA_PCLK_EN();
	   }else if (pGPIOx == GPIOB)
	   {
		   GPIOB_PCLK_EN();
	   }else if (pGPIOx == GPIOC)
	   {
		   GPIOC_PCLK_EN();
	   }else if (pGPIOx == GPIOD)
	   {
		   GPIOD_PCLK_EN();
	   }else if (pGPIOx == GPIOE)
	   {
		   GPIOE_PCLK_EN();
	   }else if (pGPIOx == GPIOF)
	   {
		   GPIOF_PCLK_EN();
	   }else if (pGPIOx == GPIOG)
	   {
		   GPIOG_PCLK_EN();
	   }else if(pGPIOx == GPIOH)
	   {
		   GPIOH_PCLK_EN();
	   }
   }
   else if (EnorDi == DISABLE){
	   if(pGPIOx == GPIOA)
	   {
		   GPIOA_PCLK_DI();
	   }else if (pGPIOx == GPIOB)
	   {
		   GPIOB_PCLK_DI();
	   }else if (pGPIOx == GPIOC)
	   {
		   GPIOC_PCLK_DI();
	   }else if (pGPIOx == GPIOD)
	   {
		   GPIOD_PCLK_DI();
	   }else if (pGPIOx == GPIOE)
	   {
		   GPIOE_PCLK_DI();
	   }else if (pGPIOx == GPIOF)
	   {
		   GPIOF_PCLK_DI();
	   }else if (pGPIOx == GPIOG)
	   {
		   GPIOG_PCLK_DI();
	   }else if (pGPIOx == GPIOH)
	   {
		   GPIOH_PCLK_DI();
	   }

   }
   else{
	   // Undefined input
   }
}


/**
 * @brief  Initialize GPIO pin according to configuration structure.
 * @param  pGPIOHandle : Pointer to GPIO handle structure
 * @note   Configures following registers:
 *         - MODER   : Pin mode (Input, Output, Alternate, Analog)
 *         - OTYPER  : Output type (Push-pull/Open-drain)
 *         - OSPEEDR : Output speed
 *         - PUPDR   : Pull-up/Pull-down configuration
 *         - AFR     : Alternate function selection
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    uint32_t temp = 0;    //temp register

    // 1. Configure the mode of gpio pin

    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
    	// Non interrupt mode
    	temp = ( pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    	pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    	pGPIOHandle->pGPIOx->MODER |= temp;

    }
    else{
    	//this part will code later (interrupt mode)
    }
    temp = 0;

    // 2. configure the speed
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDER &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));  //Clearing
    pGPIOHandle->pGPIOx->OSPEEDER |= temp;

    temp = 0;

    //3. configure the pupd setting

     temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
 	pGPIOHandle->pGPIOx->PUPDR &= ~( 0x3 <<( 2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));  //Clearing
     pGPIOHandle->pGPIOx->PUPDR |= temp;

     temp = 0;
     //4. Configure the OP type
     temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
  	pGPIOHandle->pGPIOx->OTYPER &= ~( 0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);  //Clearing
          pGPIOHandle->pGPIOx->OTYPER |= temp;

     temp = 0;

    // 5. Configure the alt functionality
     if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
     {
    	 // Configure the alt function register
    	 uint8_t temp1, temp2;

    	 temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
    	 temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
    	 pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << ( 4 * temp2 ));
    	 pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
     }

}


/**
 * @brief  Reset GPIO port registers to default reset values.
 * @param  pGPIOx : Base address of the GPIO port
 * @note   This is done by setting the corresponding reset bit in RCC AHB1RSTR register.
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	 if(pGPIOx == GPIOA)
		   {
			   GPIOA_REG_RESET();
		   }else if (pGPIOx == GPIOB)
		   {
			   GPIOB_REG_RESET();
		   }else if (pGPIOx == GPIOC)
		   {
			   GPIOC_REG_RESET();
		   }else if (pGPIOx == GPIOD)
		   {
			   GPIOD_REG_RESET();
		   }else if (pGPIOx == GPIOE)
		   {
			   GPIOE_REG_RESET();
		   }else if (pGPIOx == GPIOF)
		   {
			   GPIOF_REG_RESET();
		   }else if (pGPIOx == GPIOG)
		   {
			   GPIOG_REG_RESET();
		   }else if(pGPIOx == GPIOH)
		   {
			   GPIOH_REG_RESET();
		   }

}


/**
 * @brief  Read the logic level from a specific input pin.
 * @param  pGPIOx    : Base address of the GPIO port
 * @param  PinNumber : GPIO pin number (0–15)
 * @retval uint8_t   : Returns 0 or 1
 * @note   Reads corresponding bit from IDR (Input Data Register).
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    uint8_t value;
    value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
    return value;

}


/**
 * @brief  Read entire input port value.
 * @param  pGPIOx  : Base address of the GPIO port
 * @retval uint16_t: 16-bit value of IDR register
 * @note   Each bit corresponds to one GPIO pin (0–15).
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
    return (uint16_t)pGPIOx->IDR;
}
/**
 * @brief  Write value to entire GPIO output port.
 * @param  pGPIOx : Base address of the GPIO port
 * @param  Value  : 16-bit value to be written to ODR
 * @note   Directly writes to ODR (Output Data Register).
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
    pGPIOx->ODR = Value;
}


/**
 * @brief  Write logic level to a specific GPIO output pin.
 * @param  pGPIOx    : Base address of the GPIO port
 * @param  PinNumber : GPIO pin number (0–15)
 * @param  Value     : SET (1) or RESET (0)
 * @note   Modifies corresponding bit in ODR register.
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	    {
	    	// Write 1 to the output data register at the bit field corresponding to the pin
	    	pGPIOx->ODR |= (1 << PinNumber);
	    }else
	    {
	    	// Write 0
	    	pGPIOx->ODR &= ~(1 << PinNumber);
	    }
}


/**
 * @brief  Toggle the state of a GPIO output pin.
 * @param  pGPIOx    : Base address of the GPIO port
 * @param  PinNumber : GPIO pin number (0–15)
 * @note   XOR operation is typically used on ODR register.
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
     pGPIOx->ODR ^= (1 << PinNumber);
}


/**
 * @brief  Configure IRQ number, priority and enable/disable IRQ.
 * @param  IRQNumber   : IRQ number (from vector table)
 * @param  IRQPriority : Priority level
 * @param  EnorDi      : ENABLE or DISABLE interrupt
 * @note   Configures NVIC ISER/ICER and IPR registers.
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{
    // TODO: Implement
}


/**
 * @brief  Handle GPIO interrupt for a given pin.
 * @param  PinNumber : GPIO pin number (0–15)
 * @note   Clears EXTI pending register (PR) corresponding to the pin.
 */
void GPIO_IRQHandling(uint8_t PinNumber)
{
    // TODO: Implement
}
