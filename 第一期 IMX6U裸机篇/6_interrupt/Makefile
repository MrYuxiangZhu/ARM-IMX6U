###############################################################
#Copyright © zhuyuxiang. All rights reserved.
#文件名 : Makefile
#作者 : 朱宇祥
#版本 : V1.0
#描述 : Makefile
#其他 : 无
#论坛 : 
#日志 : 2021/4/11 朱宇祥创建
###############################################################
CROSS_COMPILE	?= arm-linux-gnueabihf-
TARGET			?= interrupt

CC				:= $(CROSS_COMPILE)gcc
LD				:= $(CROSS_COMPILE)ld
OBJCOPY			:= $(CROSS_COMPILE)objcopy
OBJDUMP			:= $(CROSS_COMPILE)objdump
RM				:= rm -rf

#头文件目录变量
INCDIRS			:= imx6ul \
				   bsp/clk \
				   bsp/led \
				   bsp/delay  \
				   bsp/beep \
				   bsp/key
#源文件目录变量
SRCDIRS			:= project \
				   bsp/clk \
				   bsp/led \
				   bsp/delay \
				   bsp/beep \
				   bsp/key

#所有文件目录加上-I前缀
INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))

#搜索目录中所有.S文件
SFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))

#搜索目录中所有.c文件
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

#所有.S文件去除目录，只保留.S文件名
SFILENDIR		:= $(notdir $(SFILES))

#所有.c文件去除目录，只保留.c文件名
CFILENDIR		:= $(notdir $(CFILES))

#所有.S文件替换为obj/.o文件
SOBJS			:= $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
#所有.c文件替换为obj/.o文件
COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))

OBJS			:= $(SOBJS)$(COBJS)

#定义VPATH表示在指定的路径搜索源文件
VPATH			:= $(SRCDIRS)

.PHONY : clean

$(TARGET).bin : $(OBJS)
	$(LD) -Timx6ul.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

#静态模式，$(SOBJS) : obj/%.o : %.S表示将所有.S文件编译为.o文件存在在obj目录下
$(SOBJS) : obj/%.o : %.S
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<
	
#静态模式，$(COBJS) : obj/%.o : %.c表示将所有.c文件编译为.o文件存在在obj目录下
$(COBJS) : obj/%.o : %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

clean:
	$(RM) $(TARGET).elf $(TARGET).dis $(TARGET).bin $(SOBJS) $(COBJS) load.imx
