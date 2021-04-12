#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"

#include "led.h"
#include "button.h"

int main(void){
	LedInit();
	BtnInit();
	LedsAllFlash(10,100,0);
	LedFlash(Led1,5,300);
	LedFlash(Led4,6,300);
	while(true){
		switch (BtnDown()){
			case BTN_1:
				LedFlash(Led1,5,100);
			break;
			case BTN_2:
				LedToggle(Led2);
			break;
			case BTN_3:
				LedsAllFlash(10,100,0);
			break;
			case BTN_4:
				LedToggle(Led4);
			break;
			default:
				
				break;
		}
//		for(int i=LedStart;i<=LedEnd;i++) LedOn(i);
//		for(int a=0;a<3;a++){
//			for(int i=LedStart;i<=LedEnd;i++){
//				nrf_delay_ms(100);
//				LedOff(i);
//			}
//			nrf_delay_ms(100);
//			for(int i=LedEnd;i>=LedStart;i--){
//				nrf_delay_ms(100);
//				LedOn(i);
//			}
//			nrf_delay_ms(100);
//			for(int i=LedEnd;i>=LedStart;i--){
//				nrf_delay_ms(100);
//				LedOff(i);
//			}
//			nrf_delay_ms(100);
//			for(int i=LedStart;i<=LedEnd;i++){
//				nrf_delay_ms(100);
//				LedOn(i);
//			}
//		}
//		nrf_delay_ms(100);
//		LedsAllFlash(7,200,0);
	}
}
