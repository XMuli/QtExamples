<img align=center src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2023/20230618195256.png" width="80%"/>

　　　　　　　　　　　　　　　　　　　　　　　　　 我也不知道为什么，当初就是想放这么一张图在这里~

# QtExamples

![](https://img.shields.io/badge/language-C%2B%2B%20%2F%20QT-orange) ![](https://img.shields.io/github/license/XMuli/QtExamples) ![](https://img.shields.io/badge/powered%20by-XMuli-ff69b4) 

![](https://img.shields.io/github/languages/code-size/XMuli/QtExamples)   ![](https://img.shields.io/github/stars/XMuli/QtExamples?style=social) ![](https://img.shields.io/github/forks/XMuli/QtExamples?style=social&label=Fork)

<br>

[TOC]

 <br>

## 目录

- [项目介绍](#项目介绍)
- [构建环境](#构建环境)
- [正文](#正文)
- [新手过来](#新手过来)
- [分享所想](#分享所想)
- [我所想说🙋‍♀️](#我所想说🙋‍♀️)
- [贡献](#贡献)
- [作者](#作者)
- [协议](#协议)

<br>

## 项目介绍

- [x] `Qt` 的 `GUI` 基础控件用法，网络；

- [x] `DTK` 重绘控件方式的框架解析；

- [x] `QtCrator` 使用和一些小技巧；

- [x] `Qt` 原理/运行机制理解

　　自己所学记录，亦可以互相交流共享学习，<font color=#D0087E size=4 face="幼圆">**有朋自远方互联网而来，不亦悦乎？**</font>

<br>

## 构建环境

该系列的源码，知识文章等均托管于此仓库；主线目标是讲解 QT5 的相关文章。

<font color=#70AD47 size=4 face="幼圆">**开发系统：**</font>   `MacOS 10.14-13.x`  |  `win10 x64 1803-22H2`  |  `UOS/Deepin 20.x`

<font color=#70AD47 size=4 face="幼圆">**编码软件：** </font> `Qt 5.9-5.15`  | `Visual Studio 2015-2019` 

<br>

# 正文

## 「第 1 章」  预备知识

- **Windows 系统**
  - [在 Win10 环境下安装 QtCreator 5.9.8 作 C++ 的 IDE 开发工具](https://blog.csdn.net/qq_33154343/article/details/103674579)
  - [QtCreator 安装 SDK，在 MSVC 编译模式下使用 CDB 调试器](https://blog.csdn.net/qq_33154343/article/details/98779698) 
  - [Win10 安装 QtCreator + Visual Studio 2015 作为 C++ 的 IDE 开发工具](https://blog.csdn.net/qq_33154343/article/details/103755569)
  - [Visual Studio 2017 专业版使用最新版 Qt 5.9.2 教程](https://blog.csdn.net/qq_33154343/article/details/78587699)  
  - [Win10 安装 CLion + CMake + MSVC / MinGW 作 QT 开发](https://blog.csdn.net/qq_33154343/article/details/120070828) 

- **MacOS 系统**
  - [ MacOS 安装 QtCreator 5.9.8 作 C++ 的 IDE 开发工具](https://blog.csdn.net/qq_33154343/article/details/103231202)

- **Linux 系统**
  - [Win10 的 VMware 中安装 UOS 20，在 UOS 中安装 QtCreator 及搭建 DTK 开发环境](https://blog.csdn.net/qq_33154343/article/details/103733327)
  - [MacOS 安装 Parallels Desktop，再安装 UOS 20 + QtCreaor，及搭建 DTK 开发环境](https://blog.csdn.net/qq_33154343/article/details/104180794)
  - [MacOS 的 VMware Fusionlimian 中安装 Linux Deepin15.11](https://blog.csdn.net/qq_33154343/article/details/102789047)
  - [Deepin / UOS 中配置 DTK 开发环境](https://blog.csdn.net/qq_33154343/article/details/112239518)
  - [重装 UOS / Deepin V20 后必安装软件（个人习惯）](https://xmuli.blog.csdn.net/article/details/106510975)
  - [ArchLinux + DDE 安装教程](https://xmuli.blog.csdn.net/article/details/107696563)
  - [对 GNU/Linux 介绍、ArchLinux社区氛围、DDE移植Arch流程](https://blog.csdn.net/qq_33154343/article/details/108378441)

- **通用命令交互**
  - [Shell、Bash、CMD、PowerShell 的区别](https://blog.csdn.net/qq_33154343/article/details/123366377)
  - [Windows-Terminal 配置 OhMyPosh 美化 GitBash](https://blog.csdn.net/qq_33154343/article/details/120661945)
  - [WWindows 打造颜值和实用可媲美 Linux 的终端：Pwsh7 + OhMyPosh](https://blog.csdn.net/qq_33154343/article/details/124030501)

<br>

## 「第 2 章」  QT 生成原理/运行机制

- [Make、Makefile、Cmake、QMake 的区别](https://blog.csdn.net/qq_33154343/article/details/98170236) 
- [QT 编程中 namespace Ui { class Widget; } 解析](https://blog.csdn.net/qq_33154343/article/details/98122981) 

<br>

## 「第 3 章」  常规 GUI 控件

- 一个默认的`Qt Widget`项目 【空】
- [元对象系统 MOC (Meat-Object System) 的对象 MetaObject 和(含动态)属性 Propert 的用法](https://xmuli.blog.csdn.net/article/details/105925608) 【QtMeatObjectEx】
- [QString 在2 ／8／10／16 进制之间转换](https://blog.csdn.net/qq_33154343/article/details/100860030) 【QtQStringEx】
- [QString 常用的功能函数的介绍及用法](https://blog.csdn.net/qq_33154343/article/details/100860270) 【QtQStringFunEx】
- [QSlider + QAbstractSlider 滑动条的介绍及用法](https://blog.csdn.net/qq_33154343/article/details/100944831)【QtQSliderEx】
- [QSlider + QScrollBar + QProgressBar （ 移动条、滚动条 、进度条）的联动](https://blog.csdn.net/qq_33154343/article/details/101003081)【QtQProgressBarEx】
- [QSlider 仪表盘 + QLCD_NUmber 数值显示 的介绍及用法](https://blog.csdn.net/qq_33154343/article/details/101003115)【QtQdialQLCDEx】
- [QTime / QDate / QDateTime 时间日期 +  QTimer 定时器的的介绍及用法](https://blog.csdn.net/qq_33154343/article/details/101040841)【QtDateTimeEx】
- [QComboBox 下拉列表框 + QPlainTextEdit 多行富文本编辑器的介绍及用法](https://blog.csdn.net/qq_33154343/article/details/101127870) 【QtQcomboBoxEx】
- [QListWidget 列表控件 + QToolButton 工具按钮的介绍及用法](https://blog.csdn.net/qq_33154343/article/details/101314908)【QtQListWidgetEx】
- [QTreeWidget 目录树组件 + QDockWidget 停靠区域组件的介绍及用法](https://blog.csdn.net/qq_33154343/article/details/103467757)【QtQTreeWidgetEx】
- [QTableWidget 表格组件的的介绍及用法](https://blog.csdn.net/qq_33154343/article/details/103485154)【QtQTableWidgetEx】
- [QFileSystemModel 数据模型获取本机文件系统用法](https://blog.csdn.net/qq_33154343/article/details/103544820)【QtQFileSystemModelEx】 
- [getOpenFileName 标准对话框和自定义对话框的用法](https://blog.csdn.net/qq_33154343/article/details/103545066)【QtQDialogEx】
- [QTableView 表格视图 + QStandardItemModel 标准项模型的用法](https://blog.csdn.net/qq_33154343/article/details/103572418)【QtQStandardItemModelEx】
- [自定义和标准对话框的用法](https://blog.csdn.net/qq_33154343/article/details/103606981)【QtCustomDialogEx】
- [MDI(Multi-document Interface) 多文档界面的实现 + QMdiArea 的用法](https://blog.csdn.net/qq_33154343/article/details/103625380)【QtMDIEx】
- [创建 QKeySequenceEdit() 后，显示方块■◆乱码](https://blog.csdn.net/qq_33154343/article/details/125775732)
- Qt 修改 `*.svg` 文件的颜色【ExChangeSVGColor】

<br>

## 「第 4 章」  网络编程

- [QHostInfo 主机信息查询 + QNetworkInterface 查询 IP 等](https://blog.csdn.net/qq_33154343/article/details/103707035)【QtQHostInfoEx】
- [TCP 通信之 QTcpServer + QTcpSocket，服务器和客户端通讯](https://blog.csdn.net/qq_33154343/article/details/103759735)【QtTcpEx】
- [UDP 通信之 QUdpSocket + unicast 单播 / broadcast 广播 / multicast 组播](https://blog.csdn.net/qq_33154343/article/details/103789843)【QtUdpEx】
- [QNetworkAccessManager + QNetworkReply + QNetworkRequest 协同实现高层网络的操作 HTTP](https://blog.csdn.net/qq_33154343/article/details/103811638) 【QtHttpEx】

<br>

## 「第 5 章」  DTK 重绘控件原理解析 / 自定义 QStyle

- **DTK 历史发展**
  - [DTK 的历史起源、发展，和简单入门](https://xmuli.blog.csdn.net/article/details/106189533) [★★]
  - [Deepin、DDE 的历史起源与发展(附 Deepin 所有版本的 DDE 效果图)](https://xmuli.blog.csdn.net/article/details/106195055) [★★]
  - [UOS/Deepin 中配置 DTK 开发环境](https://xmuli.blog.csdn.net/article/details/112239518) [★]
  - [Deepin / DTK 文档参考资料集合](https://xmuli.blog.csdn.net/article/details/112244150)  [★★★]
- **背景知识**
  - QStyle与QPen、QPush、QPalette、QPainter之间的区别 
  - [DTK 基础教程：自定义控件规范](https://xmuli.blog.csdn.net/article/details/108536588)  [★]
  - [QStyle 设置界面的外观和 QCommonStyle 继承关系图讲解和使用](https://blog.csdn.net/qq_33154343/article/details/104367878) [★★]
  - [Qt 之 proxy() 代理函数探究](https://blog.csdn.net/qq_33154343/article/details/101571843)
- **感性理解👀**
  - [QT 控件在 UOS 20 + MaOS10.14 下的显示不同的 QStyle「即样式换肤效果」](https://blog.csdn.net/qq_33154343/article/details/104305154)
  - [QT 控件在 Win 10 + Deepin 10.15 下的显示不同的 QStyle「即样式换肤效果」](https://blog.csdn.net/qq_33154343/article/details/100148552) 
- **DTK 源码解析架构🤔**
  - [QStyle / DTK 重绘 Qt-GUI 已有控件，举例 QScrollBar](https://blog.csdn.net/qq_33154343/article/details/104537944) [★★]
  - [QStyle / DTK重绘自定义需求控件，举例 MySwitchButton](https://blog.csdn.net/qq_33154343/article/details/104987446) [★★] 
  - [DTK 基础教程：自定义控件规范](https://xmuli.blog.csdn.net/article/details/108536588) [★★]
  - [DTK常用和测试代码片 ](https://xmuli.blog.csdn.net/article/details/106187959) 
  - [DTK 每日自动更新其 API 文档](https://xmuli.blog.csdn.net/article/details/108756933)
- **DTK 项目实战**
  - [更换 QT 应用程序的界面 UI，实现换肤，展示自带其它 QStyle 样式](https://blog.csdn.net/qq_33154343/article/details/100148552) 
  - [QStyle 自定义重绘 QScrollBar](https://blog.csdn.net/qq_33154343/article/details/100943187) 
  - [QStyle 自定义重绘 QRubberBand 控件](https://blog.csdn.net/qq_33154343/article/details/100588428) 
  - [QStyle 自定义重绘滑动条 QSlider 控件](https://blog.csdn.net/qq_33154343/article/details/100545769) 
  - [ QStyle 自定义重绘滑动条 QSlider 控件二](https://blog.csdn.net/qq_33154343/article/details/100942637) 
  - [QStyle 重绘时 sizeFromContents() 未被调用的分析](https://blog.csdn.net/qq_33154343/article/details/100941134) 
  - [QStyle 之 PenStyle 的 CustomDashLine 使用](https://blog.csdn.net/qq_33154343/article/details/100659576) 
  - [Deepin 开发任务栏网速插件 lfxSpeed](https://xmuli.blog.csdn.net/article/details/110672252) [★]
  - [Deepin 任务栏网速插件推荐  NetSpeed  (重构 lfxSpeed)](https://xmuli.blog.csdn.net/article/details/113573870) [★★]
  - [Deepin 自定义修改窗口圆角大小](https://xmuli.blog.csdn.net/article/details/109232878)  [商业开源项目示例 ★★]
  - [Deepin 愿望墙：社区插件等需求调研结果](https://xmuli.blog.csdn.net/article/details/112243878) [社区练手参考]


<br>

## 「第 6 章」  QT / IDE 乱码根因和解决

- **此两篇足够**
- 极简图表解释 -->  [古文码、口字码、符号码、问号码、棍拷码](https://blog.csdn.net/qq_33154343/article/details/99617767) [★★★★★]
  
- 极繁根因分析 -->  [愿编程不再乱码(含Qt)-根因深究](https://blog.csdn.net/qq_33154343/article/details/120661967) [★★★★★]


- **产出 “极繁根因分析” 一文的途中的曲折认知**

  - [QT 中文乱码问题](https://blog.csdn.net/qq_33154343/article/details/78686103)  [★★]
  - [乱码原因产生和解决方案](https://xmuli.blog.csdn.net/article/details/109567352) 
  - [借 QT 中文乱码谈谈 Coding 中的编码问题](https://blog.csdn.net/qq_33154343/article/details/78686075) 
  - [QT5 中文乱码解决](https://blog.csdn.net/qq_33154343/article/details/95344312) 


<br>

## 「第 7 章」  IDE 技巧

- **Qt Creator**
  - [QtCreator 界面的基本组成简介和入门使用讲解(Win + Linux + MacOS)](https://blog.csdn.net/qq_33154343/article/details/103942733)

  - [QtCreator 设置代码美化 Astyle 之 Artistic](https://blog.csdn.net/qq_33154343/article/details/101397429)

  - [QtCreator 关闭 .cpp 文件右侧的黄色警告](https://blog.csdn.net/qq_33154343/article/details/102943623)

  - [QtCreator 中自定义项目例子置于“欢迎-实例”中](https://blog.csdn.net/qq_33154343/article/details/115049715)

  - [QtCreator 中自定义项目例子置于“欢迎-实例”中](https://xmuli.blog.csdn.net/article/details/115049715)

  - [Qt 项目用 Doxygen 生成 .qch，嵌入文档到 Assistants](https://blog.csdn.net/qq_33154343/article/details/114580630)

  - [小技巧：Design 设计师里，无法拖拽 action 到 toolbar 里](https://blog.csdn.net/qq_33154343/article/details/100168170) 

  - [小技巧：QtCreator 用快捷键秒实现，声明在基类中重写的派生类(纯)虚函数](https://blog.csdn.net/qq_33154343/article/details/104457739) 

  - [小技巧：设置 QToolBox 的每一页 page 的使用单独的布局（QTabWidget 同理）](https://blog.csdn.net/qq_33154343/article/details/100185025) 



- **Visual Studio**

  - [VS2017 调试 Qt 源码，安装 PDB](https://blog.csdn.net/qq_33154343/article/details/120339797)

  - [VS2019 调试 Qt5 时 QString 显示为内存地址而非字符串](https://xmuli.blog.csdn.net/article/details/116244865) 

  - [Visual Studio 实际仅增删数行，却显示文件所有行均发生变更](https://blog.csdn.net/qq_33154343/article/details/123366419)

  - [Visual Studio 生成 .vs 隐藏文件夹，导致 Git 命令错误](https://blog.csdn.net/qq_33154343/article/details/123366493)

  - [Win10 的 20H2 使用 VS 2019，拖曳窗口会崩溃](https://blog.csdn.net/qq_33154343/article/details/116244656)

  - [Visual Studio 2019 进行远程调试](https://blog.csdn.net/qq_33154343/article/details/123855765)

  - [Visual Studio 断点调试之箭头偏移进错函数，捉🐛记](https://blog.csdn.net/qq_33154343/article/details/124482152)

  - [微软 SDK 导致的项目编译失败哦~](https://blog.csdn.net/qq_33154343/article/details/124736720)
  - [一个微软自带的 Notepad 所导致的问题](https://blog.csdn.net/qq_33154343/article/details/123508220) 【ExCRLF】

  

- **WINDOWS-MSVC OR LINUX-GCC**

  - [WINDOWS 所遇到奇葩问题集锦](PLATFORM_MSVC_GCC/WINDOWS%20所遇到奇葩问题集锦.md) [🦄🎣🎁🎁🎁]
  - [LINUX 所遇到编码奇怪的问题](PLATFORM_MSVC_GCC/LINUX%20所遇到编码奇怪的问题.md)  [🦄🎣🎁🎁🎁]



<br>

## 「第 8 章」  提交规范和发布 QT 程序

- [约定式提交规范](https://www.conventionalcommits.org/)
- [修改 Doxygen 主题，生成 Qt 风格的文档](https://xmuli.blog.csdn.net/article/details/114591725) 
- [QT 项目在 Windows 平台上面发布成可执行程序](https://blog.csdn.net/qq_33154343/article/details/96448388) 
- [QT 项目在 MacOS 平台上面发布成可执行程序](https://xmuli.blog.csdn.net/article/details/96448938#comments) 
- [QT 项目在 Linux 平台上面发布成可执行程序](https://blog.csdn.net/qq_33154343/article/details/96448621) 
- [Linux 中用 dh_make 将 Qt + CMake 项目打包为 deb 文件](https://blog.csdn.net/qq_33154343/article/details/123778207)

<br>

## 「第 9 章」  高级

- [Lambda 表达式详解](https://blog.csdn.net/qq_33154343/article/details/125775706)

- [Qt 信号和槽原理分析](https://xmuli.blog.csdn.net/article/details/115305903) [★★★]
- [QT 项目 CMake 设置国际化支持](https://xmuli.blog.csdn.net/article/details/114439385) 
- [Qt4 和 Qt5 的信号和槽的用法差异](https://xmuli.blog.csdn.net/article/details/118346008) 
- [高分屏、分辨率、DPI、PPI，及 Qt 处理高分屏](https://xmuli.blog.csdn.net/article/details/108905279) [★★]
- [如何给上游 QT 提交 BUG 反馈和贡献代码 PATCH？](https://xmuli.blog.csdn.net/article/details/107220867)  [★★★★]

<br>

- [如何构建 QT5（5.15）](https://xmuli.blog.csdn.net/article/details/114259155) 
- [在 Mac 编译成功运行 QT 5.15 源码：Debug + Release 版本](https://xmuli.blog.csdn.net/article/details/114259186)
- [Linux / Unix 学习完整系列（基础 / 编译 / 进程间通信 / 信号 / 守护进程 / 多线程等）](https://xmuli.blog.csdn.net/article/details/105847532)【[linuxExample](https://github.com/xmuli/linuxExample)】[★★★★★]

<br>

## 「第 10 章」  项目

- [项目实战：仿 QQ 的单聊，属 GUI 界面 ](https://blog.csdn.net/qq_33154343/article/details/79341062)
- [项目实战：仿 QQ 的群聊，属 GUI 界面](https://blog.csdn.net/qq_33154343/article/details/96437681)
- [项目实战：C 语言写 Socket 的 TCP 聊天，属 CUI 控制台](https://blog.csdn.net/qq_33154343/article/details/81808722)
- [项目实战：C 语言写 Socket 的 UDP 聊天，属 CUI 控制台](https://blog.csdn.net/qq_33154343/article/details/81809168)
- [项目实战：QT5 的 Quick 仿写 QQ  2019 简洁版的登录界面，含 GUI 界面](https://blog.csdn.net/qq_33154343/article/details/80448144)
- [QT5/C++项目：QT象棋【初版】](https://xmuli.blog.csdn.net/article/details/80931400) [★★★★★]
- [QT5/C++项目：基于QT的跨平台网络对战象棋（一）](https://blog.csdn.net/qq_33154343/article/details/89284983) [★★★★★]
- [QT5/C++项目：基于QT的跨平台网络对战象棋（二）](https://blog.csdn.net/qq_33154343/article/details/89285968) [★★★★★]
- [QT5/C++项目：基于QT的跨平台网络对战象棋（三）](https://blog.csdn.net/qq_33154343/article/details/89286553) [★★★★★]
- [FLIPPED 一款简易且漂亮的跨平台截图软件](https://xmuli.blog.csdn.net/article/details/129719267) [★★★★★★★★★ 2023.06]

<br>

- **自定义绘画控件**
  - [使用 QListWidget 创建的一个 气泡聊天窗口消息的控件 BubbleMessage，且自适应大小](https://github.com/XMuli/BubbleMessage)  [★★★★]

<br>

## 新手过来

　　<font color=#D0087E size=4 face="幼圆">**新手**</font> 在深思熟虑后踏入的编程，容易遭遇如下如下几点:

1. 语言语法不熟悉🤦‍♀️
2. 相关 IDE 安装、配置不会；不懂如何创建自己所需的工程项目🤦‍♀️
3. 基础控件不认识，不会用🤦‍♀️
4. 难以🔍可阅读、成体系的低级博客，多为高热度Title文章🤦‍♀️
5. ...开始步入正轨👣
6. 也不知学编程到是底在学习什么❓👀
7. ...修行靠个人👩‍💻

<br>

## 分享所想

1. 自己想学一遍 GUI 控件
2. 帮助真的新手实现0→1的入门，解决👆的1，2，3，4，6问题
3. 学习于网络，回馈于网络
4. 希望永久被🔍引擎检索到，以博客形式发表📝

<br>

## 我所想说🙋‍♀️

<font color=#D0087E size=4 face="幼圆">虽然不盈利，会累，但因自由和开源软件而写的开心ya， 鸭鸭</font>

<br>

## Star 增长

[![Star History Chart](https://api.star-history.com/svg?repos=XMuli/QtExamples&type=Date)](https://star-history.com/#XMuli/QtExamples&Date)

<br>

## 贡献

若是帮助到了你，或者觉得有用，可以点击该项目的的 <font color=#D0087E size=4 face="幼圆">**⭐Star** </font>和<font color=#D0087E size=4 face="幼圆">**🍴 Fork**</font> 的两个图标，方便抬手之间，表示点个赞，手有余香

<details>
    <summary> <b>当然也可以赠与一杯冰阔落[捐赠/打赏  ← 点击展开二维码]</b></summary>
  <p> - If you have something to learn from the project, you can also invite me to share a glass of Fat House Ice and Coke. - </p>
  <pre><img src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2022/202302282339037.png" width="80%"/></pre>
</details>
<br>

## 作者

[![alt text](https://img.shields.io/badge/QQ-%E5%81%95%E8%87%A7-brightgreen)](https://sighttp.qq.com/authd?IDKEY=31f3ef7312b39e2c8dc822ae2f4c3b3118e1a6f31cc83373) : 直接和我聊天~

[![alt text](https://img.shields.io/badge/GitHub-XMuli-brightgreen)](https://github.com/XMuli) : 查看我的主页

[![alt text](https://img.shields.io/badge/Blog-%E5%81%95%E8%87%A7%E7%9A%84%E5%B0%8F%E7%AB%99-ff69b4)](https://ifmet.cn/) : 好奇我的小窝

[![alt text](https://img.shields.io/badge/Blog-国内镜像-ff69b4)](https://blog.csdn.net/qq_33154343) ：浏览量 100W+

<br>

## 协议

<img src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2023/20230618194948.png" width="50%"/>

博客代码基于Apache License 2.0 协议进行分发和使用，更多信息参见 [协议文件](/LICENSE)。

所含文章使用以下协议进行保护：[署名-非商业性使用-禁止演绎](http://creativecommons.org/licenses/by-nc-nd/3.0/cn/)。
