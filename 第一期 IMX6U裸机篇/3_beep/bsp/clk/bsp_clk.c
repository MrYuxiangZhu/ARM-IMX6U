/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : bsp_clk.c
作者 : 朱宇祥
版本 : V1.0
描述 : 系统时钟驱动。
其他 : 无
论坛 : 
日志 : 2021/4/9 朱宇祥创建
**************************************************************/
#include "bsp_clk.h"

/*
 * @description	: 使能I.MX6U所有外设时钟
 * @param 		: 无
 * @return 		: 无
 */
void clk_enable(void)
{
	CCM_CCGR0 = 0XFFFFFFFF;
	CCM_CCGR1 = 0XFFFFFFFF;
	CCM_CCGR2 = 0XFFFFFFFF;
	CCM_CCGR3 = 0XFFFFFFFF;
	CCM_CCGR4 = 0XFFFFFFFF;
	CCM_CCGR5 = 0XFFFFFFFF;
	CCM_CCGR6 = 0XFFFFFFFF;
}

