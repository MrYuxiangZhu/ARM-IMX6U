/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : bsp_delay.c
作者 : 朱宇祥
版本 : V1.0
描述 : 延时文件。
其他 : 无
论坛 : 
日志 : 2021/4/9 朱宇祥创建
**************************************************************/
#include "bsp_delay.h"

/*
 * @description	: 短时间延时函数
 * @param - n	: 要延时循环次数(空操作循环次数，模式延时)
 * @return 		: 无
 */
void delay_short(__IO uint32_t n)
{
	while(n--) {}
}

/*
 * @description	: 延时函数,在396Mhz的主频下
 * 			  	  延时时间大约为1ms
 * @param - n	: 要延时的ms数
 * @return 		: 无
 */
void delay(__IO uint32_t n)
{
	while(n--)
	{
		delay_short(0x7FF);
	}
}


