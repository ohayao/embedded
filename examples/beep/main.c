#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"

#include "led.h"
#include "button.h"
#include "beep.h"

int main(void){
	LedInit();
	BtnInit();
	BeepInit();
	LedsAllFlash(10,100,0);
	LedOn(Led1);
	LedOn(Led2);
	LedOff(Led3);
	LedOff(Led4);
	while(true){
		switch(BtnDown()){
			case BTN_1:
				LedToggle(Led1);
				BeepToggle();
			break;
			case BTN_2:
				LedToggle(Led2);
				BeepToggle();
			break;
			case BTN_3:
				LedToggle(Led3);
				BeepToggle();
				break;
			case BTN_4:
				LedToggle(Led4);
				BeepToggle();
			break;
		}
	}
}
