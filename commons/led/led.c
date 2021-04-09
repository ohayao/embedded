#include "nrf52.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "led.h"

void LedInit(void){
	nrf_gpio_cfg_output(Led1);
	nrf_gpio_cfg_output(Led2);
	nrf_gpio_cfg_output(Led3);
	nrf_gpio_cfg_output(Led4);
}
void LedOn(uint32_t pin_number){
	nrf_gpio_pin_clear(pin_number);
}
void LedOff(uint32_t pin_number){
	nrf_gpio_pin_set(pin_number);
}
void LedToggle(uint32_t pin_number){
	nrf_gpio_pin_toggle(pin_number);
}
void LedFlash(uint32_t pin_number,int times,int intervalMilseconds){
	for(int i=0;i<times;i++){
		LedToggle(pin_number);
		nrf_delay_ms(intervalMilseconds);
	}
}
void LedsAllFlash(int times,int intervalMilSeconds,int initIsOn){
	if(initIsOn==1) for(int j=LedStart;j<=LedEnd;j++) LedOn(j);
	else for(int j=LedStart;j<=LedEnd;j++) LedOff(j);
	for(int i=0;i<times;i++){
		nrf_delay_ms(intervalMilSeconds);
		for(int j=LedStart;j<=LedEnd;j++) LedToggle(j);
	}
}
