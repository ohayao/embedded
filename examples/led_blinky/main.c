#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"

#include "led.h"

int main(void){
	LedInit();
	while(true){
		for(int i=LedStart;i<=LedEnd;i++) LedOn(i);
		for(int a=0;a<3;a++){
			for(int i=LedStart;i<=LedEnd;i++){
				nrf_delay_ms(100);
				LedOff(i);
			}
			nrf_delay_ms(100);
			for(int i=LedEnd;i>=LedStart;i--){
				nrf_delay_ms(100);
				LedOn(i);
			}
			nrf_delay_ms(100);
			for(int i=LedEnd;i>=LedStart;i--){
				nrf_delay_ms(100);
				LedOff(i);
			}
			nrf_delay_ms(100);
			for(int i=LedStart;i<=LedEnd;i++){
				nrf_delay_ms(100);
				LedOn(i);
			}
		}
		nrf_delay_ms(100);
		LedsAllFlash(7,200,0);
	}
}
