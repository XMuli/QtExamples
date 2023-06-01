---
title: LINUX/GCC 所遇到编码奇怪的问题
date: 2020-06-30 12:22:28
updated: 2020-06-30 12:22:28
---



**简  述：**　记录一些使用和开发 `Deepin/UOS V20`   过程中的一些奇怪的 `Bug`、或者记录一些奇怪知识。

<!-- more -->

[TOC]

<br>

### [Bug 1]  `Debug` 编译运行成功、`Releas`编译成功、运行崩溃

#### 详细：

在写 `dde-dock` 的时候，遇到编译的网速插件在 `Debug` 模式下会编译成功、运行成功；在 `Release` 下也可以编译成功，但运行会崩溃。环境如下:　**💻：**  `uos20 amd64` 📎 `Qt 5.11.3` 📎 `gcc/g++ 9.0` 📎 `gdb8.0` 

<br>

#### 分析

**本次错误的三个原因：**

- 重写了虚函数，但是里面没有写具体的内容
- 函数有 bool 返回值，但是函数体内部没有写
- 很多虚函数只搭建了框架，里面都是空着的，运行一会后突然崩溃

#### 解决

变量的值未初始化，在  `Debug` 模式会自动赋值，但是 `Release`  模式下会，不会自动赋初值；

<br>

### [Bug 2]  控制中心编译成功、运行崩溃

#### 详细

控制中心  `dde-control-center`  从  `gerrit` 上面新下载的源码， 切换到 `maintain/5.2` 分支，编译成功，运行失败，一定崩溃，界面不会显示出来；后来切换到 `uos` 分支也是一样的结果。

报错如下：

 <img src="https://cdn.jsdelivr.net/gh/xmuli/xmuliPic@pic/2020/image-20201120171014490.png" width="70%"/>

 <img src="https://cdn.jsdelivr.net/gh/xmuli/xmuliPic@pic/2020/image-20201120170952187.png" width="70%"/>

#### 分析

- 重新在 `gerrit` 上拉取一份新的最新代码，旧的可能被未知污染了；同时再找一份电脑编译运行此项目，作为对比验证

- 控制中心运行显示， 后面要加参数 `-s`

- 怀疑可能 `dtk` 版本过低，`dtkcore、dtkgui、dtkwidget` 都升级到最新的版本，对应的 `-dev` 包也升级了一下；

- 然后重启系统；；

- 重建构建生成依赖 `sudo apt build-dep dde-control-center`  或者  `dpkg-checkbuilddeps` ；
- 删除 `.user` 临时文件；然后重来一轮 **重新 清理、构建、运行** 再次尝试；

#### 解决一

然后将 `main.cpp`  的下面此处此行修改为`new` 的形式后，成功运行了：

```cpp
int main(int argc, char *argv[])
{
    DApplication *app = DApplication::globalApplication(argc, argv);

    
int main(int argc, char *argv[])
{
    DApplication *app = new DApplication(argc, argv);
```

#### 解决二

依旧怀疑是 `DTK` 的问题，安装了符号调试包准备调试 `DTK` 时候；运行之后 `sudo apt install libdtkwidget5-dbgsym` 之后，发现不用修改**解决一** ，此 Bug 没有再次复现，也可以成功运行。

#### 其它

如何使用 gdb 带参数调试，fpc 有一篇 markdown 文档；systemd-coredump 是干啥用的，学习一下。

<br>

### [Bug 3] 控制中心没有音频输出

#### 详细

显示器外接而苹果 3.5mm 耳机，显示没有声音，不能听歌；以为是 `dde-control-center` 的 bug ，升级到最新版本；依旧无效

 <img src="https://raw.githubusercontent.com/xmuli/xmuliPic/pic/2020/20210105144911.png" width="70%"/>

#### 解决

显示器使用 `VGA` 连接机箱，没有音频输出，所以耳机没有显示，改为插入 机箱的耳机接口，即回复正常。

PS： 若用 `HTMI` 连接，是自带音频，直接外接显示器

<br>

### [Bug 4] QtCreator 项目，过量的调试信息

#### 问题

使用 `Qt Creator` 运行项目，发现控制台有很多调试信息刷屏，很烦。想屏蔽这个消息

<img src="https://cdn.jsdelivr.net/gh/xmuli/xmuliPic@pic/2020/20210106172513.png" width="50%"/>

#### 解决

在 `/etc/X11/Xsession.d/00deepin-dde-env ` 中注释掉 `QT_LOGGING_RULES="*.debug=true"` 即可，然后注销之后生效。可在 QtCreator 中，`项目-Build & Run-Run-Run Environment` 中，查看到该环境变量。

若为 false 就是啥都不打印， 包括你自己的 qDebug()<< ；为 true 所有的 qtdebug 日志都会打印。



