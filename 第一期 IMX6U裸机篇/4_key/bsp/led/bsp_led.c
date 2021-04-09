/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : bsp_led.c
作者 : 朱宇祥
版本 : V1.0
描述 : 使用C语言来点亮开发板上的LED灯，学习和掌握如何用C语言来完成对I.MX6U处理器的GPIO初始化和控制。
其他 : 无
论坛 : 
日志 : 2021/4/9 朱宇祥创建
**************************************************************/
#include "bsp_led.h"

/*
 * @description	: 初始化LED对应的GPIO
 * @param 		: 无
 * @return 		: 无
 */
void led_init(void)
{
	/*初始化IO3复用功能*/
	IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 = 0X00000005; /*复用为GPIO1_IO3*/
	
	/* 配置GPIO1_IO3的IO属性
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
	
	IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 = 0X000010B0;
	 
	/*初始化GPIO*/
	GPIO1_GDIR &= ~(1 << GPIO_PIN_3); 	/* GPIO1_GDIR bit3位清零*/
	GPIO1_GDIR |= (1 << GPIO_PIN_3);	/* GPIO1_GDIR bit3位置1，GPIO1_IO03设置为输出*/
	
	/* 设置GPIO1_IO03输出低电平，关闭LED0 */
	GPIO1_DR &= ~(1 << GPIO_PIN_3);
	GPIO1_DR |= (1 << GPIO_PIN_3);
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
		GPIO1_DR &= ~(1 << 3);/*GPIO1_DR的bit3清零*/
		break;
	case LED_OFF:
		GPIO1_DR |= (1 << 3);;/*GPIO1_DR的bit3置1*/
		break;		
	}
}
