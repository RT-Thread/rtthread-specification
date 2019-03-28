# skeleton 开发板 BSP 说明

标签： ARM Cortex-M0、xxx

---

## 简介

本文档为 xxx 开发团队为 xxx 开发板提供的 BSP (板级支持包) 说明。

主要内容如下：

- 开发板资源介绍
- BSP 快速上手
- 进阶使用方法

通过阅读快速上手章节开发者可以快速地上手该 BSP，将 RT-Thread 运行在开发板上。在进阶使用指南章节，将会介绍更多高级功能，帮助开发者利用 RT-Thread 驱动更多板载资源。

## 开发板介绍

skeleton 开发板是 xxx 公司推出的一款基于 ARM Cortex-M0 内核的开发板，最高主频为 48MHz，xxx 开发板外观如下图所示：

![开发板外观](figures/board.jpg)

该开发板常用**板载资源**如下：

- MCU：xxx，主频 48MHz，32KB SRAM，256KB FLASH，54 GPIOs
- 外部模块：SPI FLASH (MX25L64，8MB)、I2C EEPROM (M24C04，512B)
- 常用外设
  - LED：2 个，(PA12/PC12)
  - 液晶屏：1 个
  - 按键：3 个，K1(PF00)，K2（PF01)，RESET(MRST)
- 常用接口：GPIO、UART、SPI、I2C
- 调试接口: 标准 JTAG/SWD

开发板更多详细信息请参考【厂商名】[xxx 开发板介绍](https://xxx.com/index.htm)。

## 外设支持

本 BSP 目前对外设的支持情况如下：

|**片上外设**     |**支持情况**|**备注**                             |
| :----------------- | :----------: | :------------------------------------- |
| GPIO              |     支持     | PA0, PA1... PK15 ---> PIN: 0, 1...176 |
| UART              |     支持     | UART1/x/x                             |
| SPI               |     支持     | SPI1/x/x                              |
| I2C               |     支持     | 软件 I2C                              |
| SDIO              |   暂不支持   | 即将支持                              |
| RTC               |   暂不支持   | 即将支持                              |
| PWM               |   暂不支持   | 即将支持                              |
| USB Device        |   暂不支持   | 即将支持                              |
| USB Host          |   暂不支持   | 即将支持                              |
| IWG               |   暂不支持   | 即将支持                              |
| xxx               |   暂不支持   | 即将支持                              |
|**板载外设**     |**支持情况**|**备注**                             |
| USB 转串口        |     支持     |                                       |
| SPI Flash         |     支持     |                                       |
| 以太网            |     支持     |                                       |
| SD 卡              |   暂不支持   |                                       |
| CAN               |   暂不支持   |                                       |
|**扩展模块**     |**支持情况**|**备注**                             |
|     xxx 模块      |   支持   |                                      |

## 使用说明

使用说明分为如下两个章节：

- 快速上手

    本章节是为刚接触 RT-Thread 的新手准备的使用说明，遵循简单的步骤即可将 RT-Thread 操作系统运行在该开发板上，看到实验效果 。

- 进阶使用

    本章节是为需要在 RT-Thread 操作系统上使用更多开发板资源的开发者准备的。通过使用 ENV 工具对 BSP 进行配置，可以开启更多板载资源，实现更多高级功能。

### 快速上手

本 BSP 为开发者提供 MDK4、MDK5 和 IAR 工程，并且支持 GCC 开发环境。下面以 MDK5 开发环境为例，介绍如何将系统运行起来。

#### 硬件连接

使用数据线连接开发板到 PC，并连接开发板对应串口到 PC。

#### 编译下载

双击 project.uvprojx 文件，打开 MDK5 工程，编译并下载程序到开发板。

> 工程默认配置使用 xxx 仿真器下载程序，在通过 xxx 连接开发板的基础上，点击下载按钮即可下载程序到开发板。

#### 运行结果

下载程序成功之后，系统会自动运行，观察开发板上 LED 的运行效果，红色 LED 常亮、绿色 LED 会周期性闪烁。

 在终端工具里打开相应的串口（115200-8-1-N），复位设备后，可以看到 RT-Thread 的输出信息:

```c
 \ | /
- RT -     Thread Operating System
 / | \     4.0.1 build Jan 19 2019
 2006 - 2018 Copyright by rt-thread team
msh >
```

### 进阶使用

此 BSP 默认只开启了 GPIO 和 串口 的功能，如果需使用更多功能，需要利用 ENV 工具对 BSP 进行配置，步骤如下：

1. 在 bsp 下打开 env 工具。

2. 输入 `menuconfig` 命令配置工程，配置好之后保存退出。

3. 输入 `pkgs --update` 命令更新软件包。

4. 输入 `scons --target=mdk4/mdk5/iar` 命令重新生成工程。

## 注意事项

xxx

## 维护人信息

- [xxx](https://github.com/xxx)
- [邮箱](xxx@xxx.com)

## 参考资料

* [RT-Thread 文档中心](https://www.rt-thread.org/document/site/)

* [xxx 开发板数据手册](http://abc.com/datasheet.pdf)

* [xxx 开发板参考手册](http://abc.com/reference.pdf)

* [xxx 芯片数据手册](http://abc.com/um.pdf)

