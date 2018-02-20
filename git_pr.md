# Github上提交代码

标签（空格分隔）： RT-Thread规范

---

在github上向RT-Thread的仓库提交代码，提交PR请遵循以下事项：

* 不同的功能请分开来提交，不要把不相关的修改一次性都提交；
* 提交时的message尽可能的使用英文描述，当然使用中文也问题不大；
* 提交message分两部分，一个是message title，请以"[module] messsage"方式进行"[module]"部分，请填写正确的名称，可以参见以下的说明：

| 前缀 | 说明 |
| ---- | ---- |
| [Kernel] | 内核或者"rt-thread/include"部分修改；|
| [shell] |  命令行部分修改；|
| [DFS] | 设备虚拟文件系统部分修改；|
| [lwIP] | 网络协议栈部分修改；|
| [DeviceDrivers] | 设备驱动框架部分修改；|
| [Tools] | `rt-thread/tools`中相关修改；|
| [examples] | `rt-thread/examples`例子的修改；|
| [BSP][stm32f10x] | `rt-thread/bsp/stm32f10x` 移植包的修改；|

* message内容主体，请尽可能详细描述为什么要做这样的修改，以及修改了什么；
* PR的标题请简单说明这次提交PR的内容。

## PR提交代码重点注意事项

* 请优先检查代码风格：
    - 移植的代码，请尽量保持原有代码，改动部分尽量少；
    - 和RT-Thread适配的代码，请遵循RT-Thread的代码风格；

以下代码是不妥的，会被拒绝合并到PR中：

1. 缩进不一致
```c
void func(int parameter)
{
    int a;

        if (parameter < 0)
        {
            /* ... */
        }
}
```

`if`语句和前面的缩进不一致；

2. 包含不必要的代码

```c
void func(int parameter)
{
#if 0
    /* ... */
#endif

#if 1
    /* ... */
#endif
}
```

代码中不管是`#if 0`还是`#if 1`，都不应该存在。提交上来的代码，都代表着这是一份正式的代码。
