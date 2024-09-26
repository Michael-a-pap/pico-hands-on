

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#define ANALOG_PIN 26

void setup() {
	stdio_init_all();
	adc_init();
	adc_gpio_init(ANALOG_PIN);
	adc_select_input(0); //0 means the 0th position of the analog multiplexer which corresponds to the 26GPIO
	
}
int main() {
	setup();
	while(1) {
		uint16_t value = adc_read();
		printf("The raw value of the adc is: %d\n", value);
		sleep_ms(1000);
	}
}

