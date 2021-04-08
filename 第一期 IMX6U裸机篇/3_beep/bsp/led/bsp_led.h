/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : led.h
作者 : 朱宇祥
版本 : V1.0
描述 : 时钟GPIO1_IO03相关寄存器地址定义。
其他 : 无
论坛 : 
日志 : 2021/4/6 朱宇祥创建
**************************************************************/
#ifndef _LED_H
#define _LED_H

#include "imx6ul.h"

/*
 *LED开关控制枚举
 */
typedef enum
{
	LED_ON = 0,
	LED_OFF,
}LED_STATE;

void led_init(void);
void led_control(LED_STATE led_ctrl);

#endif
