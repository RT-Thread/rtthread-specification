# RT-Thread 移植、设备驱动接口实现规范

本文档描述了如何进行RT-Thread针对一个芯片架构的移植，以及设备驱动的接口规范。系统工程师可以根据本文档进行RT-Thread对不同芯片的移植，并编写对应的外设驱动，集成到RT-Thread系统中。

## 目录结构

| 目录名 | 说明 |
| ------ | ---- |
| [porting][1] | 和CPU移植相关的文档 |
| [drivers][2] | 和外设驱动移植相关的文档 |
| [bsp_skeleton][3] | 一份移植的空白模版，包括SConscript编译脚本 |

  [1]: porting/README.md
  [2]: drivers/README.md
  [3]: bsp_skeleton/
