# Github上提交代码

在github上向RT-Thread的仓库提交代码，提交PR请遵循以下事项：

1. 不同的功能请分开来提交，不要把不相关的修改一次性都提交；
2. 提交时的message尽可能的使用英文描述，当然使用中文也问题不大；
3. 提交message分两部分，一个是message title，请以"[module] messsage"方式进行"[module]"部分，请填写正确的名称，例如：
  * [Kernel] -- 指的是内核或者"rt-thread/include"部分修改；
  * [shell] -- 指的是命令行部分修改；
  * [DFS] -- 指的是设备虚拟文件系统部分修改；
  * [lwIP] -- 指的是网络协议栈部分修改；
  * [DeviceDrivers] -- 指的是设备驱动框架部分修改；
  * [Tools] -- 指的是"rt-thread/tools"中相关修改；
  * [examples] -- 指的是"rt-thread/examples"例子的修改；
  * [BSP][stm32f10x] -- 指的是"rt-thread/bsp/stm32f10x"移植包的修改；
4.  message内容主体，请尽可能详细描述为什么要做这样的修改，以及修改了什么；
5. PR的标题请简单说明这次提交PR的内容。
