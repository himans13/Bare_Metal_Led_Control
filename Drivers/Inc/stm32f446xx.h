/*
 * stm32f446xx.h
 *
 *  Created on: Apr 13, 2026
 *      Author: LENOVO
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

#define _vo  volatile
/* Base addresses of on-chip memory regions in STM32 microcontroller */

#define FLASH_BASEADDR      0x08000000U   /*!< Base address of Flash memory (program storage) */

#define SRAM1_BASEADDR      0x20000000U   /*!< Base address of SRAM1 (main data memory used during execution) */

#define SRAM2_BASEADDR      0x2001C000U   /*!< Base address of SRAM2 (additional RAM, often used for backup or specific applications) */

#define ROM_BASEADDR        0x1FFF0000U   /*!< Base address of System Memory (ROM) containing bootloader code */

#define SRAM               SRAM1_BASEADDR

/* AHBx and APBx Bus Peripheral Base addresses */

#define PERIPH_BASE            0x40000000U
#define APB1PERIPH_BASEADDR    PERIPH_BASE
#define APB2PERIPH_BASEADDR    0x40010000U
#define AHB1PERIPH_BASEADDR    0x40020000U
#define AHB2PERIPH_BASEADDR    0x50000000U
/* Base addresses of Peripherals Hanging on AHB1 Bus */

#define GPIOA_BASEADDR       (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR       (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR       (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR       (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR       (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR       (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR       (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR       (AHB1PERIPH_BASEADDR + 0x1C00)

#define RCC_BASEADDR         (AHB1PERIPH_BASEADDR + 0x3800)

/* Base addresses of Peripherals Hanging on APB1 Bus */

#define I2C1_BASEADDR        (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR        (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR        (APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR        (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR        (APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR      (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR      (APB1PERIPH_BASEADDR + 0x4800)

#define UART4_BASEADDR       (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR       (APB1PERIPH_BASEADDR + 0x5000)

/* Base addresses of Peripherals hanging on APB2 Bus */
#define SP1_BASEADDR        (APB2PERIPH_BASEADDR + 0x3000)
#define USART1_BASEADDR     (APB2PERIPH_BASEADDR + 0x1000)
#define EXTI_BASEADDR       (APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR     (APB2PERIPH_BASEADDR + 0x3800)

/***************************Peripheral register definition structures*********************/
/*-------------- Register structure of GPIOx----------------------*/
typedef struct
{
	_vo uint32_t  MODER;
	_vo uint32_t  OTYPER;
	_vo uint32_t  OSPEEDER;
	_vo uint32_t  PUPDR;
	_vo uint32_t  IDR;
	_vo uint32_t  ODR;
	_vo uint32_t  BSRR;
	_vo uint32_t  LCKR;
	_vo uint32_t  AFR[2];
}GPIO_RegDef_t;


/* ---------------Register Structure of RCC---------------*/

/* RCC (Reset and Clock Control) Register Definition Structure */

typedef struct
{
    _vo uint32_t CR;            /*!< RCC clock control register,                          Address offset: 0x00 */
    _vo uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                      Address offset: 0x04 */
    _vo uint32_t CFGR;          /*!< RCC clock configuration register,                    Address offset: 0x08 */
    _vo uint32_t CIR;           /*!< RCC clock interrupt register,                        Address offset: 0x0C */

    _vo uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                  Address offset: 0x10 */
    _vo uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                  Address offset: 0x14 */
    _vo uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                  Address offset: 0x18 */
    _vo uint32_t RESERVED1;     /*!< Reserved,                                            Address offset: 0x1C */

    _vo uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                  Address offset: 0x20 */
    _vo uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                  Address offset: 0x24 */
    _vo uint32_t RESERVED2;     /*!< Reserved,                                            Address offset: 0x28 */
    _vo uint32_t RESERVED3;     /*!< Reserved,                                            Address offset: 0x2C */

    _vo uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock enable register,           Address offset: 0x30 */
    _vo uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock enable register,           Address offset: 0x34 */
    _vo uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock enable register,           Address offset: 0x38 */
    _vo uint32_t RESERVED4;     /*!< Reserved,                                            Address offset: 0x3C */

    _vo uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,           Address offset: 0x40 */
    _vo uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,           Address offset: 0x44 */
    _vo uint32_t RESERVED5;     /*!< Reserved,                                            Address offset: 0x48 */
    _vo uint32_t RESERVED6;     /*!< Reserved,                                            Address offset: 0x4C */

    _vo uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode,  Address offset: 0x50 */
    _vo uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode,  Address offset: 0x54 */
    _vo uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode,  Address offset: 0x58 */
    _vo uint32_t RESERVED7;     /*!< Reserved,                                            Address offset: 0x5C */

    _vo uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode,  Address offset: 0x60 */
    _vo uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode,  Address offset: 0x64 */
    _vo uint32_t RESERVED8;     /*!< Reserved,                                            Address offset: 0x68 */
    _vo uint32_t RESERVED9;     /*!< Reserved,                                            Address offset: 0x6C */

    _vo uint32_t BDCR;          /*!< RCC Backup domain control register,                  Address offset: 0x70 */
    _vo uint32_t CSR;           /*!< RCC clock control & status register,                 Address offset: 0x74 */
    _vo uint32_t RESERVED10;    /*!< Reserved,                                            Address offset: 0x78 */
    _vo uint32_t RESERVED11;    /*!< Reserved,                                            Address offset: 0x7C */

    _vo uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,       Address offset: 0x80 */
    _vo uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                   Address offset: 0x84 */
    _vo uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                   Address offset: 0x88 */
    _vo uint32_t DCKCFGR;       /*!< RCC dedicated clocks configuration register,         Address offset: 0x8C */

    _vo uint32_t CKGATENR;      /*!< RCC clocks gated enable register,                    Address offset: 0x90 */
    _vo uint32_t DCKCFGR2;      /*!< RCC dedicated clocks configuration register 2,       Address offset: 0x94 */

} RCC_RegDef_t;
/* ---------------- Peripheral definition ( Peripheral base typecasted to xxx_RegDef_t)---------*/

#define GPIOA               ((GPIO_RegDef_t*)(GPIOA_BASEADDR))
#define GPIOB               ((GPIO_RegDef_t*)(GPIOB_BASEADDR))
#define GPIOC               ((GPIO_RegDef_t*)(GPIOC_BASEADDR))
#define GPIOD               ((GPIO_RegDef_t*)(GPIOD_BASEADDR))
#define GPIOE               ((GPIO_RegDef_t*)(GPIOE_BASEADDR))
#define GPIOF               ((GPIO_RegDef_t*)(GPIOF_BASEADDR))
#define GPIOG               ((GPIO_RegDef_t*)(GPIOG_BASEADDR))
#define GPIOH               ((GPIO_RegDef_t*)(GPIOH_BASEADDR))

#define RCC                 ((RCC_RegDef_t*)(RCC_BASEADDR))

/*
 * Clock Enable Macros for GPIOx Peripherals
 */
#define GPIOA_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 7))

/*
 * Clock Enable Macros for I2C Peripherals
 */
#define I2C1_PCLK_EN()         ( RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()         ( RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()         ( RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable Macros For SPI Peripherals
 */

#define SPI1_PCLK_EN()   (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()   (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()   (RCC->APB1ENR |= (1 << 15))

/*
 * Clock Enable Macros for USART Peripherals
 */

#define USART1_PCLK_EN()   (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()   (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()   (RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()    (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()    (RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN()   (RCC->APB2ENR |= (1 << 5))

/*
 * Clock Enable Macro for SYSCFG
 */

#define SYSCFG_PCLK_EN()   (RCC->APB2ENR |= (1 << 14))

/*
 * There is no clock enable for EXTI it uses SYSCFG
 */

/*
 * Clock disable macros for GPIOx Peripherals
 */
#define GPIOA_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 7))

/*
 * Clock disable macros for I2Cx Peripherals
 */

#define I2C1_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock disable macros for SPIx Peripherals
 */

#define SPI1_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 15))

/*
 * Clock disable macros for USART/UART Peripherals
 */

#define USART1_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()    (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()    (RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 5))

/*
 * Macros to reset GPIOx Peripherals
 */
#define GPIOA_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)

// Some Generic Macros

#define ENABLE             1
#define DISABLE            0
#define SET             ENABLE
#define RESET           DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_REST   RESET

#include "stm32f446xx_gpio_driver.h"

#endif /* INC_STM32F446XX_H_ */
