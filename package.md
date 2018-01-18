# 针对package的规范

## Kconfig

* 一个软件包（package）必须包含一个以`PKG_USING_`开头的配置项，这样RT-Thread的包管理器才能正确识别这个是一个软件包；
* 假设这个包的名称叫做SOFTA，那么软件包总选项应该是`PKG_USING_SOFTA`，如果被定义，那么代表这个软件包被加入到系统中；
* 和这个SOFTA软件包相关的其他选项，需要以`SOFTA_`开头的配置项进行定义，可以是`SOFTA_USING_A`或者`SOFTA_ENABLE_A`等的方式。
* 针对软件包是放于git仓库的包，可以使用`latest`代表最终的`master`最新版。但支持`latest`方式，必须也加入某个固定版本，以防止在某个时候找不到合适的版本。
