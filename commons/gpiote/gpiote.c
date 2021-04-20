#include "nrf52.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

#include "gpiote.h"
#include "led.h"

void BtnExitInit(void){
	
	nrf_gpio_cfg_input(BTN_1,NRF_GPIO_PIN_PULLUP);//���ùܽ�λ��������
	nrf_gpio_cfg_input(BTN_2,NRF_GPIO_PIN_PULLUP);//���ùܽ�λ��������
	
	
	//�ж�Ƕ������
	NVIC_EnableIRQ(GPIOTE_IRQn);
	

	NRF_GPIOTE->CONFIG[0]=(GPIOTE_CONFIG_POLARITY_HiToLo<<GPIOTE_CONFIG_POLARITY_Pos)| //���ô���  �����½���
												(BTN_1<<GPIOTE_CONFIG_PSEL_Pos)| //�󶨵�һ������
												(GPIOTE_CONFIG_MODE_Event<<GPIOTE_CONFIG_MODE_Pos);//����GPIOTE��ģʽ
	//ʹ���ж�
	NRF_GPIOTE->INTENSET=GPIOTE_INTENSET_IN0_Set<<GPIOTE_INTENSET_IN0_Pos;
	
	NRF_GPIOTE->CONFIG[1]=(GPIOTE_CONFIG_POLARITY_HiToLo<<GPIOTE_CONFIG_POLARITY_Pos)|
												(BTN_2<<GPIOTE_CONFIG_PSEL_Pos)|
												(GPIOTE_CONFIG_MODE_Event<<GPIOTE_CONFIG_MODE_Pos);
	//ʹ���ж�
	NRF_GPIOTE->INTENSET=GPIOTE_INTENSET_IN1_Set<<GPIOTE_INTENSET_IN1_Pos;
	
}

void GPIOTE_IRQHandler(void){
	if((NRF_GPIOTE->EVENTS_IN[0]==1) && (NRF_GPIOTE->INTENSET & GPIOTE_INTENSET_IN0_Msk)){
		NRF_GPIOTE->EVENTS_IN[0]=0;//�ж��¼�����
		nrf_delay_ms(150);
		if(nrf_gpio_pin_read(BTN_1)==0){
			LedToggle(Led1);
			LedFlash(Led3,5,300);
		}
	}
	if((NRF_GPIOTE->EVENTS_IN[1]==1) && (NRF_GPIOTE->INTENSET & GPIOTE_INTENSET_IN1_Msk)){
		NRF_GPIOTE->EVENTS_IN[1]=0;//�ж��¼�����
		nrf_delay_ms(150);
		if(nrf_gpio_pin_read(BTN_2)==0){
			LedToggle(Led2);
			LedFlash(Led4,5,300);
		}
	}
}
