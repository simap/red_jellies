/*
 * I've found that the easiest way to keep an STM32Cube project untanged
 * from the generated code is to create a second app/main file and do
 * as little as possible in the generated sources.
 * This way, the ioc file can still be used to change settings and regenerate sources.
 */

#include "main.h" //for hardware defs and GPIO labels
#include "blinky.h"
#include "button.h"

ButtonState button;

static void toggleLED1() {
	HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
}

static void toggleLED2() {
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
}

static bool isButtonPressed() {
	//NOTE: board hardware has an external pull-down resistor, button press sets high level
	return HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_SET;
}

//NOTE: call this from SysTick_Handler() in stm32h7xx_it.c
//this is run once every ms
void blinkySysTick() {
	buttonProcess(&button, isButtonPressed());
}

static void blinkyInit() {
	//NOTE: GPIO for the button and LED are already initialized by HAL

	//Set up the button with debounce for 20ms debounce, 750ms for hold
	buttonInit(&button, 20, 750);
}

//NOTE: call this from main() in main.c
void blinkyMain() {
	blinkyInit();

	while(true) {
		if (buttonPollClickEvent(&button)) {
			toggleLED1();
		}

		if (buttonPollHoldEvent(&button)) {
			toggleLED2();
		}
	}
}
