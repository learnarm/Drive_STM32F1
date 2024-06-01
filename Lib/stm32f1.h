#ifndef STM32F1_H_
#define STM32F1_H_

#include <stdint.h>
#define __vo volatile
	
#define NVIC_ISER0 ((__vo uint32_t* )0xE000E100)
#define NVIC_ISER1 ((__vo uint32_t* )0xE000E104)
#define NVIC_ISER2 ((__vo uint32_t* )0xE000E108)
#define NVIC_ISER3 ((__vo uint32_t* )0xE000E10C)

#define NVIC_ICER0 ((__vo uint32_t* )0xE000E180)
#define NVIC_ICER1 ((__vo uint32_t* )0xE000E184)
#define NVIC_ICER2 ((__vo uint32_t* )0xE000E188)
#define NVIC_ICER3 ((__vo uint32_t* )0xE000E18C)

#define NVIC_PR_BASE_ADDR ((__vo uint32_t* )0xE000E400)

// Step 1
#define FLASH_BASEADDR	0x08000000U
#define SRAM_BASEADDR		0x20000000U
#define ROM_BASEADDR		0x1FFFF000U

//Step 2
#define PERIPH_BASEADDR			0x40000000U	
#define APB1PERIPH_BASEADDR PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR	0x40010000U
#define AHBPERIPH_BASEADDR	0x40018000U

// Step 3
#define GPIOA_BASEADDR (APB2PERIPH_BASEADDR + 0x0800)
#define GPIOB_BASEADDR (APB2PERIPH_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR (APB2PERIPH_BASEADDR + 0x1000)
#define GPIOD_BASEADDR (APB2PERIPH_BASEADDR + 0x1400)
#define GPIOE_BASEADDR (APB2PERIPH_BASEADDR + 0x1800)
#define GPIOF_BASEADDR (APB2PERIPH_BASEADDR + 0x1C00)
#define GPIOG_BASEADDR (APB2PERIPH_BASEADDR + 0x2000)

#define AFIO_BASEADDR	(APB2PERIPH_BASEADDR)

#define RCC_BASEADDR (AHBPERIPH_BASEADDR + 0x9000)

#define I2C1_BASEADDR (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR	(APB1PERIPH_BASEADDR + 0x5800)

#define SPI1_BASEADDR (APB2PERIPH_BASEADDR + 0x3000)
#define SPI2_BASEADDR (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR (APB1PERIPH_BASEADDR + 0x3C00)

#define USART1_BASEADDR (APB2PERIPH_BASEADDR + 0x3800)
#define USART2_BASEADDR (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR (APB1PERIPH_BASEADDR + 0x5000)

#define EXTI_BASEADDR (APB1PERIPH_BASEADDR + 0x4400)

// Step 4
typedef struct {
	__vo uint32_t CRL;
	__vo uint32_t CRH;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t BRR;
	__vo uint32_t LCKR; 
}GPIO_RegDef_t;

// Step 5
#define GPIOA ((GPIO_RegDef_t* )GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t* )GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t* )GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t* )GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t* )GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t* )GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t* )GPIOG_BASEADDR)

typedef struct {
    __vo uint32_t EVCR;    // Offset 0x00
    __vo uint32_t MAPR;    // Offset 0x04
    __vo uint32_t EXTICR[3]; // Offset 0x08
   // __vo uint32_t EXTICR2; // Offset 0x0C
   // __vo uint32_t EXTICR3; // Offset 0x10
   // __vo uint32_t EXTICR4; // Offset 0x14
    uint32_t RESERVED;     // Offset 0x18
    __vo uint32_t MAPR2;   // Offset 0x1C
} AFIO_RegDef_t;
#define AFIO ((AFIO_RegDef_t* )AFIO_BASEADDR)

// Step 6

typedef struct {
	__vo uint32_t CR;				/*!< ,									Address offset: 0x00 	*/
	__vo uint32_t CFGR;			/*!< ,									Address offset: 0x04 	*/
	__vo uint32_t CIR;			/*!< ,									Address offset: 0x08 	*/
	__vo uint32_t APB2RSTR;	/*!< ,									Address offset: 0x0C 	*/
	__vo uint32_t APB1RSTR;	/*!< ,									Address offset: 0x010	*/
	__vo uint32_t AHBENR;		/*!< ,									Address offset: 0x14 	*/
	__vo uint32_t APB2ENR;	/*!< ,									Address offset: 0x18	*/
	__vo uint32_t APB1ENR;	/*!< ,									Address offset: 0x1C 	*/
	__vo uint32_t BDCR;			/*!< ,									Address offset: 0x20 	*/
	__vo uint32_t CSR;			/*!< ,									Address offset: 0x24 	*/
}RCC_RegDef_t;
#define RCC ((RCC_RegDef_t* )RCC_BASEADDR)

typedef struct {
	__vo uint32_t IMR;			/*!< ,									Address offset: 0x00 	*/
	__vo uint32_t EMR;			/*!< ,									Address offset: 0x04 	*/
	__vo uint32_t RTSR;			/*!< ,									Address offset: 0x08 	*/
	__vo uint32_t FTSR;			/*!< ,									Address offset: 0x0C 	*/
	__vo uint32_t SWWIER;		/*!< ,									Address offset: 0x10 	*/
	__vo uint32_t PR;				/*!< ,									Address offset: 0x14 	*/
}EXTI_RegDef_t;
#define EXTI ((EXTI_RegDef_t* )EXTI_BASEADDR)

typedef struct {
	__vo uint32_t CR1;			/*!< ,									Address offset: 0x00 	*/
	__vo uint32_t CR2;			/*!< ,									Address offset: 0x04 	*/
	__vo uint32_t SR;				/*!< ,									Address offset: 0x08 	*/
	__vo uint32_t DR;				/*!< ,									Address offset: 0x0C 	*/
	__vo uint32_t CRCPR;		/*!< ,									Address offset: 0x10 	*/
	__vo uint32_t RXCRCR;		/*!< ,									Address offset: 0x14 	*/
	__vo uint32_t TXCRCR;		/*!< ,									Address offset: 0x18 	*/
	__vo uint32_t	I2CSCFGR;	/*!< ,									Address offset: 0x1C 	*/
	__vo uint32_t I2SPR;		/*!< ,									Address offset: 0x20 	*/
}SPI_RegDef_t;	
#define SPI1 ((SPI_RegDef_t* )SPI1_BASEADDR)
#define SPI2 ((SPI_RegDef_t* )SPI2_BASEADDR)
#define SPI3 ((SPI_RegDef_t* )SPI3_BASEADDR)

typedef struct {
	__vo uint32_t CR1;			/*!< ,									Address offset: 0x00 	*/
	__vo uint32_t CR2;			/*!< ,									Address offset: 0x04 	*/
	__vo uint32_t OAR1;			/*!< ,									Address offset: 0x08 	*/
	__vo uint32_t OAR2;			/*!< ,									Address offset: 0x0C 	*/
	__vo uint32_t DR;				/*!< ,									Address offset: 0x10 	*/
	__vo uint32_t SR1;			/*!< ,									Address offset: 0x14 	*/
	__vo uint32_t SR2;			/*!< ,									Address offset: 0x18 	*/
	__vo uint32_t CCR;			/*!< ,									Address offset: 0x1C 	*/
	__vo uint32_t TRISE;		/*!< ,									Address offset: 0x20 	*/
}	I2C_RegDef_t;
#define I2C1 ((I2C_RegDef_t* )I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t* )I2C2_BASEADDR)
#define I2C3 ((I2C_RegDef_t* )I2C3_BASEADDR)

typedef struct {
	__vo uint32_t SR;				/*!< ,									Address offset: 0x00 	*/
	__vo uint32_t DR;				/*!< ,									Address offset: 0x04 	*/
	__vo uint32_t BRR;			/*!< ,									Address offset: 0x08 	*/
	__vo uint32_t CR1;			/*!< ,									Address offset: 0x0C 	*/
	__vo uint32_t CR2;			/*!< ,									Address offset: 0x10 	*/
	__vo uint32_t CR3;			/*!< ,									Address offset: 0x14 	*/
	__vo uint32_t GTPR;			/*!< ,									Address offset: 0x18 	*/
}	UART_RegDef_t;
#define USART1 ((UART_RegDef_t* )USART1_BASEADDR)
#define USART2 ((UART_RegDef_t* )USART2_BASEADDR)
#define USART3 ((UART_RegDef_t* )USART3_BASEADDR)
#define UART4 ((UART_RegDef_t* )UART4_BASEADDR)
#define UART5 ((UART_RegDef_t* )UART5_BASEADDR)

#define AFIO_PCLK_EN() (RCC->APB2ENR |= (1 << 0))

#define GPIOA_PCLK_EN() (RCC->APB2ENR |= (1 << 2))
#define GPIOB_PCLK_EN() (RCC->APB2ENR |= (1 << 3))
#define GPIOC_PCLK_EN() (RCC->APB2ENR |= (1 << 4))
#define GPIOD_PCLK_EN() (RCC->APB2ENR |= (1 << 5))
#define GPIOE_PCLK_EN() (RCC->APB2ENR |= (1 << 6))
#define GPIOF_PCLK_EN() (RCC->APB2ENR |= (1 << 7))
#define GPIOG_PCLK_EN() (RCC->APB2ENR |= (1 << 8))

#define I2C1_PCLK_EN() (RCC->APB1RSTR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1RSTR |= (1 << 22))


#define SPI1_PCLK_EN() (RCC->APB2RSTR |= (1 << 12))
#define SPI2_PCLK_EN() (RCC->APB1RSTR |= (1 << 12))
#define SPI3_PCLK_EN() (RCC->APB1RSTR |= (1 << 13))

#define USART1_PCLK_EN()	(RCC->APB2RSTR |= (1 << 14))
#define USART2_PCLK_EN()	(RCC->APB1RSTR |= (1 << 17))
#define USART3_PCLK_EN()	(RCC->APB1RSTR |= (1 << 18))
#define UART4_PCLK_EN() 	(RCC->APB1RSTR |= (1 << 19))
#define UART5_PCLK_EN() 	(RCC->APB1RSTR |= (1 << 20))



#define GPIOA_PCLK_DI() (RCC->APB2ENR &=~ (1 << 2))
#define GPIOB_PCLK_DI() (RCC->APB2ENR &=~ (1 << 3))
#define GPIOC_PCLK_DI() (RCC->APB2ENR &=~ (1 << 4))
#define GPIOD_PCLK_DI() (RCC->APB2ENR &=~ (1 << 5))
#define GPIOE_PCLK_DI() (RCC->APB2ENR &=~ (1 << 6))
#define GPIOF_PCLK_DI() (RCC->APB2ENR &=~ (1 << 7))
#define GPIOG_PCLK_DI() (RCC->APB2ENR &=~ (1 << 8))

#define I2C1_PCLK_DI() (RCC->APB1RSTR &=~ (1 << 21))
#define I2C2_PCLK_DI() (RCC->APB1RSTR &=~ (1 << 22))


#define SPI1_PCLK_DI() (RCC->APB2RSTR &=~ (1 << 12))
#define SPI2_PCLK_DI() (RCC->APB1RSTR &=~ (1 << 12))
#define SPI3_PCLK_DI() (RCC->APB1RSTR &=~ (1 << 13))

#define USART1_PCLK_DI()	(RCC->APB2RSTR &=~ (1 << 14))
#define USART2_PCLK_DI()	(RCC->APB1RSTR &=~ (1 << 17))
#define USART3_PCLK_DI()	(RCC->APB1RSTR &=~ (1 << 18))
#define UART4_PCLK_DI() 	(RCC->APB1RSTR &=~ (1 << 19))
#define UART5_PCLK_DI() 	(RCC->APB1RSTR &=~ (1 << 20))

#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET
#define FLAG_SET SET
#define FLAG_RESET RESET

#define GPIOA_REG_RESET()		do { (RCC->APB2RSTR |= (1 << 2));	(RCC->APB2RSTR &=~ (1 << 2));	} while(0)
#define GPIOB_REG_RESET()		do { (RCC->APB2RSTR |= (1 << 3));	(RCC->APB2RSTR &=~ (1 << 3));	} while(0)
#define GPIOC_REG_RESET()		do { (RCC->APB2RSTR |= (1 << 4));	(RCC->APB2RSTR &=~ (1 << 4));	} while(0)
#define GPIOD_REG_RESET()		do { (RCC->APB2RSTR |= (1 << 5));	(RCC->APB2RSTR &=~ (1 << 5));	} while(0)
#define GPIOE_REG_RESET()		do { (RCC->APB2RSTR |= (1 << 6));	(RCC->APB2RSTR &=~ (1 << 6));	}	while(0)
#define GPIOF_REG_RESET()		do { (RCC->APB2RSTR |= (1 << 7));	(RCC->APB2RSTR &=~ (1 << 7));	}	while(0)
#define GPIOG_REG_RESET()		do { (RCC->APB2RSTR |= (1 << 8));	(RCC->APB2RSTR &=~ (1 << 8));	}	while(0)

#define EXTI0_IRQ_NUM      6    /*!< ,		EXTI0											*/
#define EXTI1_IRQ_NUM      7    /*!< ,		EXTI1											*/
#define EXTI2_IRQ_NUM      8    /*!< ,		EXTI2											*/
#define EXTI3_IRQ_NUM      9    /*!< ,		EXTI3											*/
#define EXTI4_IRQ_NUM      10   /*!< ,		EX	TI4										*/
#define EXTI9_5_IRQ_NUM   23    /*!< ,		EXTI5 -> EXTI9 (chung)		*/
#define EXTI15_10_IRQ_NUM 40    /*!< ,		EXTI10 -> EXTI15 (chung)	*/

#define USART1_IRQ_NUM    37   	/*!< ,		USART1										*/
#define USART2_IRQ_NUM    38    /*!< ,		USART2										*/
#define SPI1_IRQ_NUM      35    /*!< ,		SPI1											*/
#define SPI2_IRQ_NUM      36    /*!< ,		SPI2											*/
#define TIM1_IRQ_NUM      25    /*!< ,		TIM1											*/
#define TIM2_IRQ_NUM      28    /*!< ,		TIM2											*/
#define TIM3_IRQ_NUM      29    /*!< ,		TIM3											*/
#define EXTI16_IRQ_NUM    23    /*!< ,		EXTI16										*/
#define EXTI17_IRQ_NUM    24    /*!< ,		EXTI17										*/
#define EXTI18_IRQ_NUM    25    /*!< ,		EXTI18										*/

#define GPIO_BASEADDR_TO_CODE(x) ((x == GPIOA)?0 : (x == GPIOB)?1 : (x == GPIOC)?2 : (x == GPIOD)?3 : (x == GPIOE)?4 : (x == GPIOF)?5 : (x == GPIOG)?6 : 0)

#endif	