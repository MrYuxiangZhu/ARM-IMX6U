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

#ifndef __IMX6UL_H
#define __IMX6UL_H

#include "imx6ul_type.h"

/* 
 * CCM相关寄存器地址 
 */
#define CCM_CCGR0 			*((__IO uint32_t *)0X020C4068)
#define CCM_CCGR1 			*((__IO uint32_t *)0X020C406C)

#define CCM_CCGR2 			*((__IO uint32_t *)0X020C4070)
#define CCM_CCGR3 			*((__IO uint32_t *)0X020C4074)
#define CCM_CCGR4 			*((__IO uint32_t *)0X020C4078)
#define CCM_CCGR5 			*((__IO uint32_t *)0X020C407C)
#define CCM_CCGR6 			*((__IO uint32_t *)0X020C4080)

/* 
 * IOMUX相关寄存器地址 
 */
#define SW_MUX_GPIO1_IO03 	*((__IO uint32_t *)0X020E0068)
#define SW_PAD_GPIO1_IO03 	*((__IO uint32_t *)0X020E02F4)

/* 
 * GPIO1相关寄存器地址 
 */
#define GPIO1_DR 			*((__IO uint32_t *)0X0209C000)
#define GPIO1_GDIR 			*((__IO uint32_t *)0X0209C004)
#define GPIO1_PSR 			*((__IO uint32_t *)0X0209C008)
#define GPIO1_ICR1 			*((__IO uint32_t *)0X0209C00C)
#define GPIO1_ICR2 			*((__IO uint32_t *)0X0209C010)
#define GPIO1_IMR 			*((__IO uint32_t *)0X0209C014)
#define GPIO1_ISR 			*((__IO uint32_t *)0X0209C018)
#define GPIO1_EDGE_SEL 		*((__IO uint32_t *)0X0209C01C)

#endif

