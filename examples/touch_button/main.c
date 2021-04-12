#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"

#include "led.h"
#include "touch.h"

int main(void){
	LedInit();
	TouchBtnInit();
	LedsAllFlash(10,100,0);
	LedOn(Led1);
	LedOn(Led2);
	LedOff(Led3);
	LedOff(Led4);
	while(true){
		if(TouchBtnDown()){
			LedToggle(Led1);
			LedToggle(Led2);
			LedToggle(Led3);
			LedToggle(Led4);
		}
	}
}
