/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void delay(uint16_t delay);

#define LED_NARANJA GPIO_PIN_13
#define LED_VERDE GPIO_PIN_12
#define LED_ROJO GPIO_PIN_14
#define LED_AZUL GPIO_PIN_15
#define LEDS_PORT GPIOD

#define LLAVE GPIO_PIN_0
#define LLAVE_PORT GPIOA

int main(void) {

	__GPIOD_CLK_ENABLE()
	;
	__GPIOA_CLK_ENABLE()
	;

	GPIO_InitTypeDef GPIO_Init;

	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Speed = GPIO_SPEED_FAST;

	GPIO_Init.Pin = LED_AZUL | LED_ROJO | LED_NARANJA | LED_VERDE;
	HAL_GPIO_Init(LEDS_PORT, &GPIO_Init);

	GPIO_Init.Mode = GPIO_MODE_INPUT;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Speed = GPIO_SPEED_FAST;

	GPIO_Init.Pin = LLAVE;
	HAL_GPIO_Init(LLAVE_PORT, &GPIO_Init);

	while (1) {

		if (HAL_GPIO_ReadPin(LLAVE_PORT, LLAVE) == 0) {
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_SET);

		} else {
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_SET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
		}

	}
}

void delay(uint16_t delay) {
	uint16_t i = 0xFFFF;
	while (i) {
		while (delay)
			delay--;
		i--;
	}
}
