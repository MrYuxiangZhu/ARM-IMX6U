/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : bsp_beep.h
作者 : 朱宇祥
版本 : V1.0
描述 : 蜂鸣器头文件
其他 : 无
论坛 : 
日志 : 2021/4/9 朱宇祥创建
**************************************************************/
#ifndef _BSP_BEEP_H
#define _BSP_BEEP_H

#include "imx6ul.h"

/*
 *BEEP开关控制枚举
 */
typedef enum
{
	BEEP_ON = 0,
	BEEP_OFF,
}BEEP_STATE;

void beep_init(void);
void beep_control(BEEP_STATE beep_ctrl);

#endif