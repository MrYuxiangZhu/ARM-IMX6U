/**************************************************************
Copyright © zhuyuxiang. All rights reserved.
文件名 : main.c
作者 : 朱宇祥
版本 : V1.0
描述 : I.MX6U开发板裸机实验3蜂鸣器控制
其他 : 无
论坛 : 
日志 : 2021/4/9 朱宇祥创建
**************************************************************/
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"

/*
 * @description	: main函数
 * @param 		: 无
 * @return 		: 无
 */
int main(void)
{
	clk_enable();		/* 使能所有的时钟 			*/
	led_init();			/* 初始化led 			*/
	beep_init();		/* 初始化beep	 		*/

	while(1)			
	{	
		/* 打开LED0和蜂鸣器 */
		led_control(LED_ON);	
		beep_control(BEEP_ON);
		delay(500);

		/* 关闭LED0和蜂鸣器 */
		led_control(LED_OFF);	
		beep_control(BEEP_OFF);
		delay(500);
	}

	return 0;
}
