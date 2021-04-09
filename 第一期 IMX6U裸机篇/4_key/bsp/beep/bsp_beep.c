/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : bsp_beep.c
作者 : 朱宇祥
版本 : V1.0
描述 : I.MX6U开发板裸机实验2 C语言驱动蜂鸣器
	   使用C语言来驱动开发板上的蜂鸣器，学习和掌握如何用C语言来
	   完成对I.MX6U处理器的GPIO初始化和控制。
其他 : 无
论坛 : 
日志 : 2021/4/9 朱宇祥创建
**************************************************************/
#include "bsp_beep.h"

/*
 * @description	: 初始化蜂鸣器对应的GPIO
 * @param 		: 无
 * @return 		: 无
 */
void beep_init(void)
{
	/*初始化SNVS_TAMPER1复用功能*/
	IOMUXC_SW_MUX_CTL_PAD_SNVS_TAMPER1 = 0X00000005; /*复用为GPIO5_IO01*/
	
	/* 配置GPIO5_IO01的IO属性
	 * bit 16		: 0   HYS关闭
	 * bit [15:14]	: 00  默认下拉模式
	 * bit [13]		: 0   keeper功能
	 * bit [12]		: 1   pull/keeper使能
	 * bit [11]		: 0   关闭开路输出
	 * bit [11]		: 0   关闭开路输出
     * bit [7:6]	: 10  速度100Mhz
     * bit [5:3]	: 110 R0/6驱动能力
     * bit [0]		: 0   低转换率
	 */
	 
	IOMUXC_SW_PAD_CTL_PAD_SNVS_TAMPER1 = 0X000010B0;
	
	/*初始化GPIO*/
	GPIO5_GDIR = 0X00000002;	/* GPIO5_IO01设置为输出 */
	
	/* 设置GPIO5_IO01输出高电平，关闭蜂鸣器 */
	GPIO5_DR = 0X00000002;
}

/*
 * @description	: 控制蜂鸣器
 * @param 		: 无
 * @return 		: 无
 */
void beep_control(BEEP_STATE beep_ctrl)
{
	switch (beep_ctrl)
	{
	case BEEP_ON:
		GPIO5_DR &= ~(1<<1);/*GPIO5_DR的bit1清零*/
		break;
	case BEEP_OFF:
		GPIO5_DR |= (1<<1);;/*GPIO5_DR的bit1置1*/
		break;		
	}
}
