/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "bspTP1/bspTP1.h"

uint8_t colorRGB = 0;

int main(void) {

	BSP_Init();

	while (1) {

		colorRGB = BSP_GetBrightness(); //leo el ADC y lo guardo en brighness

		led_setBrightRojo(LED_ROJO, colorRGB); //llamo a cada funcion de cada color
		led_setBrightVerde(LED_VERDE, colorRGB);
		led_setBrightAzul(LED_AZUL, colorRGB);
		}
}

