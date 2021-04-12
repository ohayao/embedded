#include "nrf52.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "touch.h"

void TouchBtnInit(void){
	nrf_gpio_cfg_input(TouchBtn,NRF_GPIO_PIN_PULLUP);
}

bool TouchBtnDown(void){
	if(nrf_gpio_pin_read(TouchBtn)==1){
		nrf_delay_ms(270);
		if(nrf_gpio_pin_read(TouchBtn)==1){
			while(nrf_gpio_pin_read(TouchBtn)==1) return true;
		}
	}
	return false;
}
