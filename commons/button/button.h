#ifndef __TEST_BUTTON_H
#define __TEST_BUTTON_H

#include "nrf52.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

#define BTN_1 13
#define BTN_2 14
#define BTN_3 15
#define BTN_4 16
#define BTN_Start 13
#define BTN_End 16

void BtnInit(void);
uint32_t BtnDown(void);
#endif
