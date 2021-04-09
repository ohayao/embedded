#ifndef __TEST_LED_H
#define __TEST_LED_H

#include "nrf52.h"

#define Led1 17
#define Led2 18
#define Led3 19
#define Led4 20
#define LedStart 17
#define LedEnd 20

void LedInit(void);
void LedOn(uint32_t pin_number);
void LedOff(uint32_t pin_number);
void LedToggle(uint32_t pin_number);
void LedFlash(uint32_t pin_number,int times,int intervalMilseconds);
void LedsAllFlash(int times,int intervalMilSeconds,int initIsOn);
#endif
