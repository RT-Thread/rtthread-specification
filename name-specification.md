# 系统移植的文件夹、文件命名规范

标签： RT-Thread规范

---

针对配置相关的Kconfig文件，相关文件都命名为 `Kconfig` （注意大小写情况）。

## BSP文件夹

一个新的移植，默认会添加到`rt-thread/bsp`目录下，在进行bsp文件夹命名时，请以如下规则进行：

    MCU型号名称-BOARD名称

例如STM32的nucleo开发板BSP，如`NUCLEO-L476RG`，它使用的是64pin的STM32L476RG MCU，这个时候BSP可以命名为：

`stm32l476-nucleo`

<stm32l476rg，后面的rg可以根据情况保留>

### BSP文件下的子文件夹名及文件名

对一份BSP，建议其下包含如下的子文件夹：

| 目录名 | 说明 |
| ------ | ---- |
| applications | 放置用户入口，例如main.c，及用户应用；|
| drivers | 放置板载驱动；|
| libraries | 和MCU相关的固件库，一般由芯片厂商提供；|

BSP文件夹下需要包含一份本BSP的说明README.md，至少包括：

* BSP针对的MCU情况；
* 开发板简介
* 当要在这块开发板上使用RT-Thread时，相关的注意事项。<例如串口用法（波特率，哪个串口等），烧写，调试等>

可以参见BSP模版中的[README.md][1]情况。

#### applications文件夹

`bsp/applications` 文件夹下放置用户程序入口，包括：

* main.c -- 用户程序主入口
* mnt.c  -- 文件系统装载表相关初始化；

#### drivers文件夹

`bsp/drivers` 文件夹下放置和板子相关的驱动（可能也包括一部分芯片外设驱动），文件命名风格请按照以下的方式：

    drv_*.c/.h

同时也存在板级初始化相关的文件，命名为 `board.c/.h`。

## libcpu文件夹

libcpu文件夹主要是和芯片相关的移植部分，请按照`架构/芯片`的方式进行命名。

  [1]: bsp_skeleton/README.md
