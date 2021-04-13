#ifndef __TEST_BEEP_H
#define __TEST_BEEP_H

#include "nrf_gpio.h"
// 蜂鸣器位置
#define PinBeep 12

#ifdef GLOBALS
bool IsBeeping;
#else
extern bool IsBeeping;
#endif


// 初始化蜂鸣器
void BeepInit(void);
// 打开蜂鸣器
void BeepON(void);
// 关闭蜂鸣器
void BeepOFF(void);
// 切换蜂鸣器开关
void BeepToggle(void);

#endif
