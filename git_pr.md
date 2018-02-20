# 向RT-Thread的Github仓库提交代码

标签： RT-Thread规范

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

## 自己的git分支维护

向github项目提交PR的通常做法是：
![git pr][1]

从upstream主线总fork一份代码到自己的github仓库中。然后在自己的github仓库中进行修改，并进行提交（注意，**这里只能提交到自己的github仓库中，而upstream仓库一般并无直接提交修改的权限**）。当进行到一定时候，希望自己的修改能更新到upstream主干中，这个时候可以在github上发起一份PR（pull request），请求upstream的维护人合并这部分的修改。如果upstream维护人确认没问题，修改的补丁将自动合并到upstream主干中。

但有的时候，自己维护的git仓库可能会出现混乱。例如：当upstream仓库已经进行改动了，然后再把upstream的改动合并到自己的仓库，这样有可能出现冲突（例如修改了相同的一份文件）。当冲突解决时，再提PR到upstream时，可能会携带一系列的提交记录。

当要把自己的改动提PR到upstream去进行合并时，可能就会出现这样反复修改的记录。

一般比较好的做法是，保留master分支不动，在自己的仓库中另外创建一个分支，例如你自己的dev分支：

    # 创建一份dev分支，并切换过去
    git checkout -b dev

后续相关的修改都在你自己的分支上进行，而不牵涉到master分支。当需要合并到master分支时，先把upstream的最新更改合并到master分支上，然后再在master分支上做rebase，如下图所示。

![git pr2][2]

相关的一些git命令说明：

```sh
    # 先切换回master分支
    git checkout master
    
    # 抓取upstream更改，然后合并到本地master分支上
    git fetch upstream
    git merge upstream/master

    # 把dev分支的更改rebase合并到master分支上
    git rebase dev
    
    # 把本地更改提交到github上自己的分支
    git push origin
```

  [1]: imgs/git_pr1.png
  [2]: imgs/git_pr2.png
