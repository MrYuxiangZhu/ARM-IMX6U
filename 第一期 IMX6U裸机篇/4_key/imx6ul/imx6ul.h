/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : led.h
作者 : 朱宇祥
版本 : V1.0
描述 : I.MX6ULL寄存器头文件。
其他 : 无
论坛 : 
日志 : 2021/4/6 朱宇祥创建
**************************************************************/
#ifndef __IMX6UL_H
#define __IMX6UL_H

#include "imx6ul_type.h"

typedef enum
{
    GPIO_PIN_0  = 0,
    GPIO_PIN_1  = 1,
    GPIO_PIN_2  = 2,
    GPIO_PIN_3  = 3,
    GPIO_PIN_4  = 4,
    GPIO_PIN_5  = 5,
    GPIO_PIN_6  = 6,
    GPIO_PIN_7  = 7,
    GPIO_PIN_8  = 8,
    GPIO_PIN_9  = 9,
    GPIO_PIN_10 = 10,
    GPIO_PIN_11 = 11,
    GPIO_PIN_12 = 12,
    GPIO_PIN_13 = 13,
    GPIO_PIN_14 = 14,
    GPIO_PIN_15 = 15,
    GPIO_PIN_16 = 16,
    GPIO_PIN_17 = 17,
    GPIO_PIN_18 = 18,
    GPIO_PIN_19 = 19,
    GPIO_PIN_20 = 20,
    GPIO_PIN_21 = 21,
    GPIO_PIN_22 = 22,
    GPIO_PIN_23 = 23,
    GPIO_PIN_24 = 24,
    GPIO_PIN_25 = 25,
    GPIO_PIN_26 = 26,
    GPIO_PIN_27 = 27,
    GPIO_PIN_28 = 28,
    GPIO_PIN_29 = 29,
    GPIO_PIN_30 = 30,
    GPIO_PIN_31 = 31,
}GPIO_PIN_NUM;

/* 
 * CCM相关寄存器地址 
 */
#define CCM_CCGR0 			                        *((__IO uint32_t *)0X020C4068)
#define CCM_CCGR1 			                        *((__IO uint32_t *)0X020C406C)
#define CCM_CCGR1 			                        *((__IO uint32_t *)0X020C406C)
#define CCM_CCGR2 			                        *((__IO uint32_t *)0X020C4070)
#define CCM_CCGR3 			                        *((__IO uint32_t *)0X020C4074)
#define CCM_CCGR4 			                        *((__IO uint32_t *)0X020C4078)
#define CCM_CCGR5 			                        *((__IO uint32_t *)0X020C407C)
#define CCM_CCGR6 			                        *((__IO uint32_t *)0X020C4080)

/* 
 * IOMUX相关寄存器地址 
 */
#define IOMUXC_SW_MUX_CTL_PAD_SNVS_TAMPER1          *((__IO uint32_t *)0X020E0020)
#define IOMUXC_SW_PAD_CTL_PAD_SNVS_TAMPER1          *((__IO uint32_t *)0X020E02AC)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 	        *((__IO uint32_t *)0X020E0068)
#define IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 	        *((__IO uint32_t *)0X020E02F4)
#define IOMUXC_SW_MUX_CTL_PAD_UART1_CTS_B           *((__IO uint32_t *)0X020E008C)
#define IOMUXC_SW_PAD_CTL_PAD_UART1_CTS_B           *((__IO uint32_t *)0X020E0318)

/* 
 * GPIO1相关寄存器地址 
 */
#define GPIO1_DR 			                        *((__IO uint32_t *)0X0209C000)
#define GPIO1_GDIR 			                        *((__IO uint32_t *)0X0209C004)
#define GPIO1_PSR 			                        *((__IO uint32_t *)0X0209C008)
#define GPIO1_ICR1 			                        *((__IO uint32_t *)0X0209C00C)
#define GPIO1_ICR2 			                        *((__IO uint32_t *)0X0209C010)
#define GPIO1_IMR 			                        *((__IO uint32_t *)0X0209C014)
#define GPIO1_ISR 			                        *((__IO uint32_t *)0X0209C018)
#define GPIO1_EDGE_SEL 		                        *((__IO uint32_t *)0X0209C01C)

/* 
 * GPIO2相关寄存器地址 
 */
#define GPIO2_DR 			                        *((__IO uint32_t *)0X020A0000)
#define GPIO2_GDIR 			                        *((__IO uint32_t *)0X020A0004)
#define GPIO2_PSR 			                        *((__IO uint32_t *)0X020A0008)
#define GPIO2_ICR1 			                        *((__IO uint32_t *)0X020A000C)
#define GPIO2_ICR2 			                        *((__IO uint32_t *)0X020A0010)
#define GPIO2_IMR 			                        *((__IO uint32_t *)0X020A0014)
#define GPIO2_ISR 			                        *((__IO uint32_t *)0X020A0018)
#define GPIO2_EDGE_SEL 		                        *((__IO uint32_t *)0X020A001C)

/* 
 * GPIO3相关寄存器地址 
 */
#define GPIO3_DR 			                        *((__IO uint32_t *)0X020A4000)
#define GPIO3_GDIR 			                        *((__IO uint32_t *)0X020A4004)
#define GPIO3_PSR 			                        *((__IO uint32_t *)0X020A4008)
#define GPIO3_ICR1 			                        *((__IO uint32_t *)0X020A400C)
#define GPIO3_ICR2 			                        *((__IO uint32_t *)0X020A4010)
#define GPIO3_IMR 			                        *((__IO uint32_t *)0X020A4014)
#define GPIO3_ISR 			                        *((__IO uint32_t *)0X020A4018)
#define GPIO3_EDGE_SEL 		                        *((__IO uint32_t *)0X020A401C)

/* 
 * GPIO4相关寄存器地址 
 */
#define GPIO4_DR 			                        *((__IO uint32_t *)0X020A8000)
#define GPIO4_GDIR 			                        *((__IO uint32_t *)0X020A8004)
#define GPIO4_PSR 			                        *((__IO uint32_t *)0X020A8008)
#define GPIO4_ICR1 			                        *((__IO uint32_t *)0X020A800C)
#define GPIO4_ICR2 			                        *((__IO uint32_t *)0X020A8010)
#define GPIO4_IMR 			                        *((__IO uint32_t *)0X020A8014)
#define GPIO4_ISR 			                        *((__IO uint32_t *)0X020A8018)
#define GPIO4_EDGE_SEL 		                        *((__IO uint32_t *)0X020A801C)

/* 
 * GPIO5相关寄存器地址 
 */
#define GPIO5_DR 			                        *((__IO uint32_t *)0X020AC000)
#define GPIO5_GDIR 			                        *((__IO uint32_t *)0X020AC004)
#define GPIO5_PSR 			                        *((__IO uint32_t *)0X020AC008)
#define GPIO5_ICR1 			                        *((__IO uint32_t *)0X020AC00C)
#define GPIO5_ICR2 			                        *((__IO uint32_t *)0X020AC010)
#define GPIO5_IMR 			                        *((__IO uint32_t *)0X020AC014)
#define GPIO5_ISR 			                        *((__IO uint32_t *)0X020AC018)
#define GPIO5_EDGE_SEL 		                        *((__IO uint32_t *)0X020AC01C)

#endif

