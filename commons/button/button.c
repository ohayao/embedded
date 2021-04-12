#include "button.h"

void BtnInit(void){
	nrf_gpio_cfg_input(BTN_1,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(BTN_2,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(BTN_3,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(BTN_4,NRF_GPIO_PIN_PULLUP);
}

uint32_t BtnDown(void){
	for(int i=BTN_Start;i<=BTN_End;i++){
		if(nrf_gpio_pin_read(i)==0){
			nrf_delay_ms(80);
			if(nrf_gpio_pin_read(i)==0){
				while(nrf_gpio_pin_read(i)==0) return i;
			}
		}
	}
	return 0;
}
