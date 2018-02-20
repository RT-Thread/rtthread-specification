# RT-Thread 移植、设备驱动接口实现规范

标签： RT-Thread规范

---

本文档描述了如何进行RT-Thread针对一个芯片架构的移植，以及设备驱动的接口规范。系统工程师根据本文档进行RT-Thread对不同芯片的移植，并编写对应的外设驱动，集成到RT-Thread系统中。

## 目录结构

| 目录名 | 说明 |
| ------ | ---- |
| [porting][1] | 和CPU移植相关的文档 |
| [drivers][2] | 和外设驱动移植相关的文档 |
| [bsp_skeleton][3] | 一份空白的BSP模版，包括SConscript编译脚本等 |

## 名字

对一份BSP移植，需要遵循一定的命名规范，请参阅[这份文档][4]。

## 提交PR

当完成一份BSP移植并需要提交到RT-Thread的git repo时，请参阅和PR相关的[文档][5]。

  [1]: porting/README.md
  [2]: drivers/README.md
  [3]: bsp_skeleton/
  [4]: name-specification.md
  [5]: git_pr.md
