/**************************************************************
Copyright © zhuyuxiang Co., Ltd. 1998-2020. All rights reserved.
文件名 : start.s
作者 : 朱宇祥
版本 : V1.0
描述 : ZERO-I.MX6UL/I.MX6ULL开发板启动文件，完成C环境初始化，
	   C环境初始化完成以后跳转到C代码。
其他 : 无
论坛 : 
日志 : 2021/4/6 朱宇祥创建
**************************************************************/

.global _start	/*全局标号*/

/*
 *描述：_start函数，程序从此函数开始执行，此函数主要是初始化C语言运行环境
 */
 
_start:
	/*进入SVC模式*/
	mrs	r0, cpsr			@ 将CPSR寄存器值读到R0寄存器
	and	r0, r0, #0x1f		@ mask mode bits，CPSR的M0~M4清零
	orr	r0, r0, #0x13		@ set SVC mode
	msr	cpsr, r0			@ 将R0的数据写到CPSR寄存器
	
	ldr sp, =0X80200000		@设置栈指针
	b main					@ 跳转到main函数入口


