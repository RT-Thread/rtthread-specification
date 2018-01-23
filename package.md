# package规范

一个package应该包含以下几个部分：

* pkginfo，有关于这个包的介绍，配置等，需要提交、添加到 [RT-Thread/packages包索引仓库](https://github.com/RT-Thread/packages) 中。应该包括两个文件Kconfig，package.json
* package本身的代码。

例如针对一个最简单的hello的package，这两部分分别是：

* [pkginfo](https://github.com/RT-Thread/packages/tree/master/misc/hello)
* [package代码](https://github.com/BernardXiong/hello/)

## pkginfo

### Kconfig

软件包的Kconfig主要由menuconfig（包括软件包管理器）进行使用，所以一些选项必须在Kconfig中定义出来：

* 一个软件包（package）必须包含一个以`PKG_USING_`开头的配置项，这样RT-Thread的包管理器才能正确识别这个是一个软件包；
* 假设这个包的名称叫做SOFTA，那么软件包总选项应该是`PKG_USING_SOFTA`，如果被定义，那么代表这个软件包被加入到系统中；
* 和这个SOFTA软件包相关的其他选项，需要以`SOFTA_`开头的配置项进行定义，可以是`SOFTA_USING_A`或者`SOFTA_ENABLE_A`等的方式。
* 针对软件包是放于git仓库的包，可以使用`latest`代表最终的`master`最新版。但支持`latest`方式，必须也加入某个固定版本，以防止在某个时候找不到合适的版本。

### package.json

package.json是package软件包的描述信息文件，包括例如软件包名称，软件包描述，作者等信息，以及必须的package代码下载链接。另外，请务必包含许可证的说明，使用了哪种许可证（GPLv2，LGPLv2.1，MIT，Apache license v2.0，BSD等）。

一个简单的package.json如下：
```json
{
    "name": "EasyLogger",
    "description": "A ultra-lightweight(ROM<1.6K, RAM<0.3k), high-performance C/C++ log library",
    "keywords": [
        "logger", "C", "high-performance", "lightweight", "C/C++"
    ],
    "readme": "A ultra-lightweight(ROM<1.6K, RAM<0.3k), high-performance C/C++ log library. More information on https://github.com/armink/EasyLogger",
    "author": {
        "name": "armink",
        "email": "armink.ztl@gmail.com"
    },
    "repository": "https://github.com/armink-rtt-pkgs/EasyLogger",
    "site" : [
        {"version": "v2.0.0", "URL": "https://github.com/armink-rtt-pkgs/EasyLogger/archive/2.0.0.zip", "filename": "EasyLogger-2.0.0.zip"},
        {"version": "latest", "URL": "https://github.com/armink-rtt-pkgs/EasyLogger.git", "filename": "EasyLogger.zip", "VER_SHA": "master" }
    ]
}
```

## package

一个package代码应该由以下部分组成：

* 根目录下的README.md文件，以说明这个package用于什么；
* 根目录下的docs文件夹，包括一份使用说明；
* 根目录下的SConscript文件，用于和RT-Thread环境一起进行编译；
* 根目录下的examples文件夹，用于提供一份使用的例子；
* package软件包的其他代码；
* 如果需要加入submodule，则可以直接在这个根目录下添加。
