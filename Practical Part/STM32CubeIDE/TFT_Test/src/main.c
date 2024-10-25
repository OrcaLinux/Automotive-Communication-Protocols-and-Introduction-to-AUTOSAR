/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 14 Dec 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : main.c                     *****************/
/****************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
/**< HAL */
#include "TFT_interface.h"
/**< APP */
#include "image.h"
void main(void)
{
	/**< Init SysClk */
	MCAL_RCC_InitSysClock();
	/**< Enable CLK for SPI and Port A */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_SPI1EN);

	/**< Set Pin Mode: SPI pins and TFT pins */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_PUSH_PULL_2MHZ); // TFT: D/C pin
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_PUSH_PULL_2MHZ); // TFT: RST pin

	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT_AF_PUSH_PULL_10MHZ); // SPI: SCLK pin
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN7, GPIO_OUTPUT_AF_PUSH_PULL_10MHZ); // SPI: MOSI pin

	/**< SPI Config */
	SPI_Config_t spi1;
	spi1.BaudRateDIV   = SPI_BAUD_RATE_DIV2;
	spi1.ClockPhase    = SPI_WRITE_READ;
	spi1.ClockPolarity = SPI_IDLE_HIGH;
	spi1.DataFrame     = SPI_DATA_FRAME_8BIT;
	spi1.FrameFormat   = SPI_MSB_FIRST;
	SPI_Init(&spi1);

	/**< TFT Config */
	TFT_Config_t tft1;
	tft1.TFT_DCPin.TFT_Port = GPIO_PORTA;
	tft1.TFT_DCPin.TFT_Pin  = GPIO_PIN0;
	tft1.TFT_RESPin.TFT_Pin = GPIO_PORTA;
	tft1.TFT_RESPin.TFT_Pin = GPIO_PIN1;
	TFT_Init(&tft1);

	/**< Display image */
	TFT_DisplayImage(&tft1, image);

	//for(;;);

}

