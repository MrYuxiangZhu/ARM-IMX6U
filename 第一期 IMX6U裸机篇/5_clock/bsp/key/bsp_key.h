/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : bsp_key.h
作者 : 朱宇祥
版本 : V1.0
描述 : 按键驱动头文件。
其他 : 无
论坛 : 
日志 : 2021/4/9 朱宇祥创建
**************************************************************/
#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "imx6ul.h"

/* 定义按键值 */
typedef enum
{
	KEY_NONE   = 0,
	KEY0_VALUE,
	KEY1_VALUE,
	KEY2_VALUE,
}KEY_VALUE;

/* 函数声明 */
void key_init(void);
int key_get_value(void);

#endif
