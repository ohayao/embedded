#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"

#include "led.h"
#include "gpiote.h"

/*
GPIOTE
*/

int main(void){
	LedInit();
	LedsAllFlash(10,100,0);
	LedOn(Led1);
	LedOn(Led2);
	LedOff(Led3);
	LedOff(Led4);
	
	//���ð����ж�
	BtnExitInit();
	//�ȴ�
	while(true){
	
	}
	
}
