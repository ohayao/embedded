#ifndef __TEST_BEEP_H
#define __TEST_BEEP_H

#include "nrf_gpio.h"
// ������λ��
#define PinBeep 12

#ifdef GLOBALS
bool IsBeeping;
#else
extern bool IsBeeping;
#endif


// ��ʼ��������
void BeepInit(void);
// �򿪷�����
void BeepON(void);
// �رշ�����
void BeepOFF(void);
// �л�����������
void BeepToggle(void);

#endif
