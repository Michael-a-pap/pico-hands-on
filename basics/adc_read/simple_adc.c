

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#define ANALOG_PIN0 0  // GPIO 26
#define ANALOG_PIN1 1  // GPIO 27
#define ANALOG_PIN2 2  // GPIO 28
#define ANALOG_PIN3 3  // GPIO 29
#define ANALOG_TEMP 4  //internal temperature ADC


void setup() {
	stdio_init_all();
	adc_init();
	adc_gpio_init(ANALOG_PIN0 + 26); //This makes sure that the pin is defined in a high-Z state
	adc_set_temp_sensor_enabled (true);	
}

int readADC() {
	adc_select_input(ANALOG_PIN0);

	return adc_read();
}

int readTemperature() {
	adc_select_input(ANALOG_TEMP);
	uint16_t adc_value = adc_read();
	
	return (int)(27-((3.3/4096*adc_value)-0.706)/0.001721);

}

int main() {
	setup();

	while(1) {

		printf("The raw value of the adc is: %d\n", readADC());
		printf("The internal temperature is: %d\n", readTemperature());
		sleep_ms(1000);
	}
}

