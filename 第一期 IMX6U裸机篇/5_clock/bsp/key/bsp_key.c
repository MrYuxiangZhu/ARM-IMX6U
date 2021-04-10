/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : bsp_key.h
作者 : 朱宇祥
版本 : V1.0
描述 : 按键驱动文件。
其他 : 无
论坛 : 
日志 : 2021/4/9 朱宇祥创建
**************************************************************/
#include "bsp_key.h"
#include "bsp_delay.h"

/*
 * @description	: 初始化按键
 * @param 		: 无
 * @return 		: 无
 */
void key_init(void)
{
	/* 初始化UART1_CTS复用 */
	IOMUXC_SW_MUX_CTL_PAD_UART1_CTS_B = 0X00000005;/*复用为GPIO1_IO18*/

	/* 配置UART1_CTS_B的IO属性	
	 *bit 16:0 HYS关闭
	 *bit [15:14]: 11 默认22K上拉
	 *bit [13]: 1 pull功能
	 *bit [12]: 1 pull/keeper使能
	 *bit [11]: 0 关闭开路输出
	 *bit [7:6]: 10 速度100Mhz
	 *bit [5:3]: 000 关闭输出
	 *bit [0]: 0 低转换率
	 */
	IOMUXC_SW_PAD_CTL_PAD_UART1_CTS_B = 0x0000F080;
	
	/* 初始化GPIO1 */
	GPIO1_GDIR &= ~(1 << GPIO_PIN_18); 	/* GPIO1_GDIR bit18位清零，GPIO1_IO18设置为输入*/
}

/*
 * @description	: 获取按键值 
 * @param 		: 无
 * @return 		: 0 没有按键按下，其他值:对应的按键值
 */
int key_get_value(void)
{
	int ret = 0;
	static uint8_t release = 1; /* 按键松开 */ 

	if ((release == 1) && (0 == GPIO_PIN_READ(GPIO1_DR, GPIO_PIN_18))) 		/* KEY0 */
	{	
		delay(10);		/* 延时消抖 */
		release = 0;	/* 标记按键按下 */
		if (0 == GPIO_PIN_READ(GPIO1_DR, GPIO_PIN_18))
		{
			ret = KEY0_VALUE;
		}
	}
	else if (1 == GPIO_PIN_READ(GPIO1_DR, GPIO_PIN_18))
	{
		ret = 0;
		release = 1; 	/* 标记按键释放 */
	}

	return ret;	
}
