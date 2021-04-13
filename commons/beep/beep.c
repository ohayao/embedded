#include "nrf52.h"
#include "nrf_gpio.h"
#define GLOBALS
#include "beep.h"

void BeepInit(void){
	nrf_gpio_cfg_output(PinBeep);
	IsBeeping=false;
}

void BeepON(void){
	nrf_gpio_pin_set(PinBeep);
	IsBeeping=true;
}

void BeepOFF(void){
	nrf_gpio_pin_clear(PinBeep);
	IsBeeping=false;
}

void BeepToggle(void){
	if(IsBeeping){
		BeepOFF();
		IsBeeping=false;
	}else{
		BeepON();
		IsBeeping=true;
	}
}
