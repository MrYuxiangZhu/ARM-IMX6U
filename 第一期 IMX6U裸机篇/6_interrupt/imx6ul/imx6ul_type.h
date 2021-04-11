/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : imx6ul_type.h
作者 : 朱宇祥
版本 : V1.0
描述 : I.MX6UL开发板公共头文件
其他 : 无
论坛 : 
日志 : 2021/4/6 朱宇祥创建
**************************************************************/
#ifndef _IMX6UL_TYPE_H
#define _IMX6UL_TYPE_H

#define __I		volatile
#define __O		volatile
#define __IO	volatile

typedef enum
{
	FALSE = 0,
	TRUE
}BOOL;

#define GPIO_PIN_READ(addr, pin)			((addr >> pin) & 0x01)

typedef unsigned char						uint8_t;
typedef unsigned short						uint16_t;
typedef unsigned int						uint32_t;
typedef unsigned long long					uint64_t;

typedef signed char							int8_t;
typedef signed short						int16_t;
typedef signed int							int32_t;
typedef signed long long					int64_t;

#endif