#ifndef __TEST_BUTTON_TOUCH
#define __TEST_BUTTON_TOUCH

#include "nrf_gpio.h"
#define TouchBtn 12

void TouchBtnInit(void);
bool TouchBtnDown(void);
#endif
