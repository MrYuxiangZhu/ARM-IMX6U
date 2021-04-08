/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : led.c
作者 : 朱宇祥
版本 : V1.0
描述 : I.MX6U开发板裸机实验2 C语言点灯
	   使用C语言来点亮开发板上的LED灯，学习和掌握如何用C语言来
	   完成对I.MX6U处理器的GPIO初始化和控制。
其他 : 无
论坛 : 
日志 : 2021/4/6 朱宇祥创建
**************************************************************/
#include "led.h"

/*
 * @description	: 使能I.MX6U所有外设时钟
 * @param 		: 无
 * @return 		: 无
 */
void clock_enable(void)
{
	CCM_CCGR0 = 0XFFFFFFFF;
	CCM_CCGR1 = 0XFFFFFFFF;
	CCM_CCGR2 = 0XFFFFFFFF;
	CCM_CCGR3 = 0XFFFFFFFF;
	CCM_CCGR4 = 0XFFFFFFFF;
	CCM_CCGR5 = 0XFFFFFFFF;
	CCM_CCGR6 = 0XFFFFFFFF;
}

/*
 * @description	: 初始化LED对应的GPIO
 * @param 		: 无
 * @return 		: 无
 */
void led_init(void)
{
	/*初始化IO3复用功能*/
	SW_MUX_GPIO1_IO03 = 0X00000005; /*复用为GPIO1_IO3*/
	
	/* 配置GPIO1_IO3的IO属性
	 * bit 16		: 0   HYS关闭
	 * bit [15:14]	: 00  默认下拉模式
	 * bit [13]		: 0   keeper功能
	 * bit [12]		: 1   pull/keeper使能
	 * bit [11]		: 0   关闭开路输出
     * bit [7:6]	: 10  速度100Mhz
     * bit [5:3]	: 110 R0/6驱动能力
     * bit [0]		: 0   低转换率
	 */
	 
	SW_PAD_GPIO1_IO03 = 0X000010B0;
	 
	/*初始化GPIO*/
	GPIO1_GDIR = 0X0000008;	/* GPIO1_IO03设置为输出 */
	 
	/* 设置GPIO1_IO03输出低电平，打开LED0 */
	GPIO1_DR = 0X0;
}

/*
 * @description	: 打开LED灯
 * @param 		: 无
 * @return 		: 无
 */
void led_control(LED_STATE led_ctrl)
{
	switch (led_ctrl)
	{
	case LED_ON:
		GPIO1_DR &= ~(1<<3);/*GPIO1_DR的bit3清零*/
		break;
	case LED_OFF:
		GPIO1_DR |= (1<<3);;/*GPIO1_DR的bit3置1*/
		break;		
	}
}

/*
 * @description	: 短时间延时函数
 * @param - n	: 要延时循环次数(空操作循环次数，模式延时)
 * @return 		: 无
 */
void delay_short(uint32_t n)
{
	while(n--){}
}

/*
 * @description	: 延时函数,在396Mhz的主频下
 * 			  	  延时时间大约为1ms
 * @param - n	: 要延时的ms数
 * @return 		: 无
 */
void delay(uint32_t n)
{
	while(n--)
	{
		delay_short(0x7ff);
	}
}

/*
 * @description	: mian函数
 * @param 	    : 无
 * @return 		: 无
 */
int main(void)
{
	clock_enable();					/* 使能所有的时钟		*/
	led_init();						/* 初始化led 			*/

	while(1)						/* 死循环 				*/
	{	
		led_control(LED_OFF);		/* 关闭LED   			*/
		delay(200);					/* 延时大约200ms 		*/

		led_control(LED_ON);		/* 打开LED		 		*/
		delay(200);					/* 延时大约200ms 		*/
	}
	
	return 0;
}
