<img src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2023/20230618195256.png" width="80%"/>

　　　　　　　　　　　　　　　　　　　　　　　　　 我也不知道为什么，当初就是想放这么一张图在这里~

# QtExamples

![](https://img.shields.io/badge/language-C%2B%2B%20%2F%20QT-orange) ![](https://img.shields.io/github/license/XMuli/QtExamples) ![](https://img.shields.io/badge/powered%20by-偕臧-ff69b4) 

![](https://img.shields.io/github/languages/code-size/XMuli/QtExamples)   ![](https://img.shields.io/github/stars/XMuli/QtExamples?style=social) ![](https://img.shields.io/github/forks/XMuli/QtExamples?style=social&label=Fork)

<br>

[TOC]

 <br>

## 目录

| 锚点                                                         | 详细                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| **QtExamples**                                               | 本项目已收录于 [Product](https://product.xmuli.tech/)        |
| [目录](#目录)                                                |                                                              |
| [项目介绍](#项目介绍)                                        |                                                              |
| [构建环境](#构建环境)                                        |                                                              |
| [热门作品](#热门作品)                                        |                                                              |
| **楔子**                                                     |                                                              |
| [新手过来](#新手过来)                                        |                                                              |
| [分享所想](#分享所想)                                        |                                                              |
| [热爱开源](#热爱开源)                                        |                                                              |
| [贡献捐赠](#贡献捐赠)                                        |                                                              |
| [联系作者](#联系作者)                                        |                                                              |
| **正文**                                                     |                                                              |
| [1-预备知识](#1-预备知识)                                    | Windows / MacOS / Linux 系统安装 QtCreator 或 Visual Studio 等，演示单步调试，讲解 Shell、PowerShell |
| [2-QT生成原理和运行机制](#2-QT生成原理和运行机制)            | Make，Makefile，CMake，QMake；namespace Ui { class Widget; } 解析 |
| [3-常规GUI控件](#3-常规GUI控件)                              | Qt 原生控件，高级自绘和组合控件，                            |
| [4-网络编程](#4-网络编程)                                    | QHostInfo，QNetworkInterface，QTcpServer，QTcpSocket，QUdpSocket，QNetworkAccessManager |
| [5-DTK重绘控件原理解析-自定义QSTYLE](#5-DTK重绘控件原理解析-自定义QSTYLE) | DTK 历史发展，背景知识，感性理解，DTK 源码解析架构，DTK 项目实战 |
| [6-QT-IDE乱码根因和解决](#6-QT-IDE乱码根因和解决)            | Qt 编译乱码根因和解决：古文码、口字码、符号码、问号码、棍拷码 |
| [7-IDE技巧](#7-IDE技巧)                                      | IDE技巧：Qt Creator ，Visual Studio 和 WinDbg 调试           |
| [8-提交规范和发布QT程序](#8-提交规范和发布QT程序)            | Git 约定式提交规范，Doxygen，.gitignore；各系统上打包和发布可执行程序 .exe .dmg .App .deb .AppImage |
| [9-高级编程](#9-高级编程)                                            | Lambda, 手搓信号和槽实现原理，高分屏处理，向上游 Qt 反馈 Bug，自行编译 Qt 源码 |
| [10-项目商业级项目](#10-项目商业级项目)                      | 见 [项目清单](https://product.xmuli.tech)❤️ 和软件、硬件实现；上架微软商店、购买和应用代码签名证书；刷机路由器 OpenWrt |
| [11-服务器开发之Linux基础编程](#11-服务器开发之Linux基础编程) | GCC/G++，GDB，程序运行原理，文件描述符，PCB                  |
| [12-服务器开发之Linux系统编程](#12-服务器开发之Linux系统编程) | 进程间通信，管道，内存映射区；信号和守护进程，未决信号，阻塞信号；多线程，互斥锁，原子操作，条件变量 |
| [13-服务器开发之Linux网络编程](#13-服务器开发之Linux网络编程) | 基础的网络理论基础知识已会，也写过一些实战项目的代码，可以参考第10章部分 |
| [14-Windows 系统开发验证代码](#14-Windows 系统开发验证代码)  | Windows 系统完整性，少见功能的验证、调研和代码片             |
| [15-研发遇到的疑难杂症经验](#15-研发遇到的疑难杂症经验)      | 见 `研发遇到的疑难杂症经验.md` 文件                          |
| **许可协议**                                                 | Apache-2.0 license                                           |

<br>

## 项目介绍

- [x] `Qt` 的 `GUI` 基础控件用法，网络；

- [x] `DTK` 重绘控件方式的框架解析；

- [x] `QtCreator` 使用和一些小技巧；

- [x] `Qt` 原理/运行机制理解

自己所学记录，亦可以互相交流共享学习，<font color=#D0087E size=4 face="幼圆">**有朋自远方互联网而来，不亦悦乎？**</font>

<br>

## 构建环境

该系列的源码，知识文章等均托管于此仓库；主线目标是讲解 QT5、Linux 基础和系统编程，相关文章

<font color=#70AD47 size=4 face="幼圆">**开发系统：**</font>   `MacOS 10.14-15.x`  |  `win 10-11`  |  `UOS/Deepin 20-25`

<font color=#70AD47 size=4 face="幼圆">**编码软件：** </font> `Qt 5.9-5.15 & 6.x`  | `Visual Studio 2015-2022` 

<br>

## 热门作品

**较火 /  高规格的完整项目** 🔥🔥🔥 【属第10章】

- [极简的电脑管家，一键关闭 Windows Defender (Anti-Virus).](https://github.com/XMuli/windows-defender-close)  【windows-defender-close】[★★]

- 截图三部曲，入门至商业级水准作品：  难 → 易
  1. [SunnyCapturer 跨平台的截图软件，支持离线OCR，图片翻译，贴图，钉图](https://xmuli.blog.csdn.net/article/details/136373241)  [★★★★★ 2023-2025] ：👉 [SunnyCapturer](https://sunnycapturer.xmuli.tech)
  2. [FLIPPED 一款简易且漂亮的跨平台截图和贴图的软件](https://xmuli.blog.csdn.net/article/details/130053230) [★★★]
  3. [ShotX 一个轻量级的 跨平台截图](https://github.com/XMuli/ShotX)  [★]


  - [简洁且易用的ChatGPT&AI的桌面应用程序ThinkyMate → 不需登录](https://xmuli.blog.csdn.net/article/details/135488438)  [★★★★★ 2024]
  - [Sunny 截图上架 Microsoft Store 及Linux等商店的指北](https://xmuli.blog.csdn.net/article/details/136334975)
  - [分享如何拥有一份私人的『开源代码签名证书』](https://xmuli.blog.csdn.net/article/details/135487951)

<br>

# 楔子

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

**Star 增长**

[![Star History Chart](https://api.star-history.com/svg?repos=XMuli/QtExamples&type=Date)](https://star-history.com/#XMuli/QtExamples&Date)

<br>

## 热爱开源

<font color=#D0087E size=4 face="幼圆">虽然不盈利，会累，但因自由和开源软件而写的开心ya， 鸭鸭</font>

<br>

## 贡献捐赠

若是帮助到了你，或者觉得有用，可以点击该项目的的 <font color=#D0087E size=4 face="幼圆">**⭐Star** </font>和<font color=#D0087E size=4 face="幼圆">**🍴 Fork**</font> 的两个图标，方便抬手之间，表示点个赞，手有余香

<details>
    <summary> <b>当然也可以赠与一杯冰阔落[捐赠/打赏  ← 点击展开二维码]</b></summary>
  <p> - If you have something to learn from the project, you can also invite me to share a glass of Fat House Ice and Coke. - </p>
  <pre><img src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2022/202302282339037.png" width="80%"/></pre>
</details>

<br>

## 联系作者

| [![alt text](https://img.shields.io/badge/个人-项目展示-brightgreen)](https://product.xmuli.tech/) : 些许的项目展示 |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [![alt text](https://img.shields.io/badge/Blog-国内镜像-ff69b4)](https://xmuli.blog.csdn.net) ：浏览量 100W+ | [![alt text](https://img.shields.io/badge/Blog-%E5%81%95%E8%87%A7%E7%9A%84%E5%B0%8F%E7%AB%99-ff69b4)](https://xmuli.tech/) : 唯一博客 |
| [![alt text](https://img.shields.io/badge/QQ-%E5%81%95%E8%87%A7-brightgreen)](https://sighttp.qq.com/authd?IDKEY=31f3ef7312b39e2c8dc822ae2f4c3b3118e1a6f31cc83373) : 简单沟通~ | [![alt text](https://img.shields.io/badge/GitHub-XMuli-brightgreen)](https://github.com/XMuli) : 托管的源码库 |

<br>

# 正文

## 1-预备知识

- **Windows 系统**
  - [在 Win10 环境下安装 QtCreator 5.9.8 作 C++ 的 IDE 开发工具](https://xmuli.blog.csdn.net/article/details/103674579)
  - [QtCreator 安装 SDK，在 MSVC 编译模式下使用 CDB 调试器](https://xmuli.blog.csdn.net/article/details/98779698) 
  - [Win10 安装 QtCreator + Visual Studio 2015 作为 C++ 的 IDE 开发工具](https://xmuli.blog.csdn.net/article/details/103755569)
  - [Visual Studio 2017 专业版使用最新版 Qt 5.9.2 教程](https://xmuli.blog.csdn.net/article/details/78587699)  
  - [Win10 安装 CLion + CMake + MSVC / MinGW 作 QT 开发](https://xmuli.blog.csdn.net/article/details/120070828) 

- **MacOS 系统**
  - [ MacOS 安装 QtCreator 5.9.8 作 C++ 的 IDE 开发工具](https://xmuli.blog.csdn.net/article/details/103231202)

- **Linux 系统**
  - [Win10 的 VMware 中安装 UOS 20，在 UOS 中安装 QtCreator 及搭建 DTK 开发环境](https://xmuli.blog.csdn.net/article/details/103733327)
  - [MacOS 安装 Parallels Desktop，再安装 UOS 20 + QtCreaor，及搭建 DTK 开发环境](https://xmuli.blog.csdn.net/article/details/104180794)
  - [MacOS 的 VMware Fusionlimian 中安装 Linux Deepin15.11](https://xmuli.blog.csdn.net/article/details/102789047)
  - [Deepin / UOS 中配置 DTK 开发环境](https://xmuli.blog.csdn.net/article/details/112239518)
  - [重装 UOS / Deepin V20 后必安装软件（个人习惯）](https://xmuli.blog.csdn.net/article/details/106510975)
  - [ArchLinux + DDE 安装教程](https://xmuli.blog.csdn.net/article/details/107696563)
  - [对 GNU/Linux 介绍、ArchLinux社区氛围、DDE移植Arch流程](https://xmuli.blog.csdn.net/article/details/108378441)

- **通用命令交互**
  - [Shell、Bash、CMD、PowerShell 的区别](https://xmuli.blog.csdn.net/article/details/123366377)
  - [Windows-Terminal 配置 OhMyPosh 美化 GitBash](https://xmuli.blog.csdn.net/article/details/120661945)
  - [WWindows 打造颜值和实用可媲美 Linux 的终端：Pwsh7 + OhMyPosh](https://xmuli.blog.csdn.net/article/details/124030501)

<br>

- **IDE 对 Qt 源码函数进行单步调试**
  - [VS2022 And QtCreator 10 调试 Qt 源码教程](https://xmuli.blog.csdn.net/article/details/131491715) [★★★★★]

<br>

## 2-QT生成原理和运行机制

- [Make、Makefile、Cmake、QMake 的区别](https://xmuli.blog.csdn.net/article/details/98170236) 
- [QT 编程中 namespace Ui { class Widget; } 解析](https://xmuli.blog.csdn.net/article/details/98122981) 

<br>

## 3-常规GUI控件

**原生控件**

- 一个默认的`Qt Widget`项目 【空】
- [元对象系统 MOC (Meta-Object System) 的对象 MetaObject 和(含动态)属性 Propert 的用法](https://xmuli.blog.csdn.net/article/details/105925608) 【QtMeatObjectEx】
- [QString 在2 ／8／10／16 进制之间转换](https://xmuli.blog.csdn.net/article/details/100860030) 【QtQStringEx】
- [QString 常用的功能函数的介绍及用法](https://xmuli.blog.csdn.net/article/details/100860270) 【QtQStringFunEx】
- [QSlider + QAbstractSlider 滑动条的介绍及用法](https://xmuli.blog.csdn.net/article/details/100944831)【QtQSliderEx】
- [QSlider + QScrollBar + QProgressBar （ 移动条、滚动条 、进度条）的联动](https://xmuli.blog.csdn.net/article/details/101003081)【QtQProgressBarEx】
- [QSlider 仪表盘 + QLCD_NUmber 数值显示 的介绍及用法](https://xmuli.blog.csdn.net/article/details/101003115)【QtQdialQLCDEx】
- [QTime / QDate / QDateTime 时间日期 +  QTimer 定时器的的介绍及用法](https://xmuli.blog.csdn.net/article/details/101040841)【QtDateTimeEx】
- [QComboBox 下拉列表框 + QPlainTextEdit 多行富文本编辑器的介绍及用法](https://xmuli.blog.csdn.net/article/details/101127870) 【QtQcomboBoxEx】
- [QListWidget 列表控件 + QToolButton 工具按钮的介绍及用法](https://xmuli.blog.csdn.net/article/details/101314908)【QtQListWidgetEx】
- [QTreeWidget 目录树组件 + QDockWidget 停靠区域组件的介绍及用法](https://xmuli.blog.csdn.net/article/details/103467757)【QtQTreeWidgetEx】
- [QTableWidget 表格组件的的介绍及用法](https://xmuli.blog.csdn.net/article/details/103485154)【QtQTableWidgetEx】
- [QFileSystemModel 数据模型获取本机文件系统用法](https://xmuli.blog.csdn.net/article/details/103544820)【QtQFileSystemModelEx】 
- [getOpenFileName 标准对话框和自定义对话框的用法](https://xmuli.blog.csdn.net/article/details/103545066)【QtQDialogEx】
- [QTableView 表格视图 + QStandardItemModel 标准项模型的用法](https://xmuli.blog.csdn.net/article/details/103572418)【QtQStandardItemModelEx】
- [自定义和标准对话框的用法](https://xmuli.blog.csdn.net/article/details/103606981)【QtCustomDialogEx】
- [MDI(Multi-document Interface) 多文档界面的实现 + QMdiArea 的用法](https://xmuli.blog.csdn.net/article/details/103625380)【QtMDIEx】
- [创建 QKeySequenceEdit() 后，显示方块■◆乱码](https://xmuli.blog.csdn.net/article/details/125775732)
- Qt 修改 `*.svg` 文件的颜色【ExChangeSVGColor】

**高级自绘和组合控件**

- [Qt 使用亚克力的透明磨砂效果的窗口思路和解决方案，三种实现思路，支持全平台](https://github.com/XMuli/AcrylicWindow) 【AcrylicWindow】

- [使用 QListWidget 创建的一个 气泡聊天窗口消息的控件 BubbleMessage，且自适应大小](https://github.com/XMuli/BubbleMessage) 【BubbleChat】 [★★★★]

<br>

## 4-网络编程

- [QHostInfo 主机信息查询 + QNetworkInterface 查询 IP 等](https://xmuli.blog.csdn.net/article/details/103707035)【QtQHostInfoEx】
- [TCP 通信之 QTcpServer + QTcpSocket，服务器和客户端通讯](https://xmuli.blog.csdn.net/article/details/103759735)【QtTcpEx】
- [UDP 通信之 QUdpSocket + unicast 单播 / broadcast 广播 / multicast 组播](https://xmuli.blog.csdn.net/article/details/103789843)【QtUdpEx】
- [QNetworkAccessManager + QNetworkReply + QNetworkRequest 协同实现高层网络的操作 HTTP](https://xmuli.blog.csdn.net/article/details/103811638) 【QtHttpEx】

<br>

## 5-DTK重绘控件原理解析-自定义QSTYLE

- **DTK 历史发展**
  - [DTK 的历史起源、发展，和简单入门](https://xmuli.blog.csdn.net/article/details/106189533) [★★]
  - [Deepin、DDE 的历史起源与发展(附 Deepin 所有版本的 DDE 效果图)](https://xmuli.blog.csdn.net/article/details/106195055) [★★]
  - [UOS/Deepin 中配置 DTK 开发环境](https://xmuli.blog.csdn.net/article/details/112239518) [★]
  - [Deepin / DTK 文档参考资料集合](https://xmuli.blog.csdn.net/article/details/112244150)  [★★★]
- **背景知识**
  - QStyle与QPen、QPush、QPalette、QPainter之间的区别 
  - [DTK 基础教程：自定义控件规范](https://xmuli.blog.csdn.net/article/details/108536588)  [★]
  - [QStyle 设置界面的外观和 QCommonStyle 继承关系图讲解和使用](https://xmuli.blog.csdn.net/article/details/104367878) [★★]
  - [Qt 之 proxy() 代理函数探究](https://xmuli.blog.csdn.net/article/details/101571843)
- **感性理解👀**
  - [QT 控件在 UOS 20 + MacOS10.14 下的显示不同的 QStyle「即样式换肤效果」](https://xmuli.blog.csdn.net/article/details/104305154)
  - [QT 控件在 Win 10 + Deepin 10.15 下的显示不同的 QStyle「即样式换肤效果」](https://xmuli.blog.csdn.net/article/details/100148552) 
- **DTK 源码解析架构🤔**
  - [QStyle / DTK 重绘 Qt-GUI 已有控件，举例 QScrollBar](https://xmuli.blog.csdn.net/article/details/104537944) [★★]
  - [QStyle / DTK重绘自定义需求控件，举例 MySwitchButton](https://xmuli.blog.csdn.net/article/details/104987446) [★★] 
  - [DTK 基础教程：自定义控件规范](https://xmuli.blog.csdn.net/article/details/108536588) [★★]
  - [DTK常用和测试代码片 ](https://xmuli.blog.csdn.net/article/details/106187959) 
  - [DTK 每日自动更新其 API 文档](https://xmuli.blog.csdn.net/article/details/108756933)
- **DTK 项目实战**
  - [更换 QT 应用程序的界面 UI，实现换肤，展示自带其它 QStyle 样式](https://xmuli.blog.csdn.net/article/details/100148552) 
  - [QStyle 自定义重绘 QScrollBar](https://xmuli.blog.csdn.net/article/details/100943187) 
  - [QStyle 自定义重绘 QRubberBand 控件](https://xmuli.blog.csdn.net/article/details/100588428) 
  - [QStyle 自定义重绘滑动条 QSlider 控件](https://xmuli.blog.csdn.net/article/details/100545769) 
  - [ QStyle 自定义重绘滑动条 QSlider 控件二](https://xmuli.blog.csdn.net/article/details/100942637) 
  - [QStyle 重绘时 sizeFromContents() 未被调用的分析](https://xmuli.blog.csdn.net/article/details/100941134) 
  - [QStyle 之 PenStyle 的 CustomDashLine 使用](https://xmuli.blog.csdn.net/article/details/100659576) 
  - [Deepin 开发任务栏网速插件 lfxSpeed](https://xmuli.blog.csdn.net/article/details/110672252) [★]
  - [Deepin 任务栏网速插件推荐  NetSpeed  (重构 lfxSpeed)](https://xmuli.blog.csdn.net/article/details/113573870) [★★]
  - [Deepin 自定义修改窗口圆角大小](https://xmuli.blog.csdn.net/article/details/109232878)  [商业开源项目示例 ★★]
  - [Deepin 愿望墙：社区插件等需求调研结果](https://xmuli.blog.csdn.net/article/details/112243878) [社区练手参考]


<br>

## 6-QT-IDE乱码根因和解决

- **此两篇足够**
  - 极简图表解释 -->  [古文码、口字码、符号码、问号码、棍拷码](https://xmuli.blog.csdn.net/article/details/99617767) [★★★★★]

  - 极繁根因分析 -->  [愿编程不再乱码(含Qt)-根因深究](https://xmuli.blog.csdn.net/article/details/120661967) [★★★★★]

  - [字符、字节、编码详细讲解](./www.regexlab.com_zh_encoding.htm.png)



- **产出 “极繁根因分析” 一文的途中的曲折认知**

  - [QT 中文乱码问题](https://xmuli.blog.csdn.net/article/details/78686103)  [★★]
  - [乱码原因产生和解决方案](https://xmuli.blog.csdn.net/article/details/109567352) 
  - [借 QT 中文乱码谈谈 Coding 中的编码问题](https://xmuli.blog.csdn.net/article/details/78686075) 
  - [QT5 中文乱码解决](https://xmuli.blog.csdn.net/article/details/95344312) 


<br>

## 7-IDE技巧

- **Qt Creator**
  - [QtCreator 界面的基本组成简介和入门使用讲解(Win + Linux + MacOS)](https://xmuli.blog.csdn.net/article/details/103942733)

  - [QtCreator 设置代码美化 Astyle 之 Artistic](https://xmuli.blog.csdn.net/article/details/101397429)

  - [QtCreator 关闭 .cpp 文件右侧的黄色警告](https://xmuli.blog.csdn.net/article/details/102943623)

  - [QtCreator 中自定义项目例子置于“欢迎-实例”中](https://xmuli.blog.csdn.net/article/details/115049715)

  - [QtCreator 中自定义项目例子置于“欢迎-实例”中](https://xmuli.blog.csdn.net/article/details/115049715)

  - [Qt 项目用 Doxygen 生成 .qch，嵌入文档到 Assistants](https://xmuli.blog.csdn.net/article/details/114580630)

  - [小技巧：Design 设计师里，无法拖拽 action 到 toolbar 里](https://xmuli.blog.csdn.net/article/details/100168170) 

  - [小技巧：QtCreator 用快捷键秒实现，声明在基类中重写的派生类(纯)虚函数](https://xmuli.blog.csdn.net/article/details/104457739) 

  - [小技巧：设置 QToolBox 的每一页 page 的使用单独的布局（QTabWidget 同理）](https://xmuli.blog.csdn.net/article/details/100185025) 

  - [小技巧：使用 Qt Design 提升自定义控件，报错找不到头文件， <QtCreator - 经验1>](./WINDOWS_MSVC_MinGW%20%26%20LINUX_GCC%20%26%20MACOS_CLANG%20所遇到奇葩问题集锦.md)
- **Visual Studio**
  - [VS2017 调试 Qt 源码，安装 PDB](https://xmuli.blog.csdn.net/article/details/120339797)
  - [VS2019 调试 Qt5 时 QString 显示为内存地址而非字符串](https://xmuli.blog.csdn.net/article/details/116244865) 
  - [VS2022 And QtCreator10调试Qt源码教程](https://xmuli.blog.csdn.net/article/details/131491715) [★★★★★]
  - [Visual Studio 实际仅增删数行，却显示文件所有行均发生变更](https://xmuli.blog.csdn.net/article/details/123366419)
  - [Visual Studio 生成 .vs 隐藏文件夹，导致 Git 命令错误](https://xmuli.blog.csdn.net/article/details/123366493)
  - [Win10 的 20H2 使用 VS 2019，拖曳窗口会崩溃](https://xmuli.blog.csdn.net/article/details/116244656)
  - [Visual Studio 2019 进行远程调试](https://xmuli.blog.csdn.net/article/details/123855765)
  - [Visual Studio 断点调试之箭头偏移进错函数，捉🐛记](https://xmuli.blog.csdn.net/article/details/124482152)
  - [微软 SDK 导致的项目编译失败哦~](https://xmuli.blog.csdn.net/article/details/124736720)
  - [一个微软自带的 Notepad 所导致的问题](https://xmuli.blog.csdn.net/article/details/123508220) 【ExCRLF】
- **WinDbg 调试**
  - [WinDbg：入门分析 dmp 文件『一』](https://xmuli.blog.csdn.net/article/details/123563647)
  - [WinDbg：调试之附加进程生成 dmp『二』](https://xmuli.blog.csdn.net/article/details/123563753)


<br>

## 8-提交规范和发布QT程序

- [约定式提交规范](https://www.conventionalcommits.org/)
- [修改 Doxygen 主题，生成 Qt 风格的文档](https://xmuli.blog.csdn.net/article/details/114591725) 
- [QT 项目在 Windows 平台上面发布成可执行程序](https://xmuli.blog.csdn.net/article/details/96448388) 
- [QT 项目在 MacOS 平台上面发布成可执行程序](https://xmuli.blog.csdn.net/article/details/96448938#comments) 
- [QT 项目在 Linux 平台上面发布成可执行程序](https://xmuli.blog.csdn.net/article/details/96448621) 
- [Linux 中用 dh_make 将 Qt + CMake 项目打包为 deb 文件](https://xmuli.blog.csdn.net/article/details/123778207)

上架 App Store

- [分享如何拥有一份私人的『开源代码签名证书』](https://xmuli.blog.csdn.net/article/details/135487951) [★★★★★]

- [Sunny 截图上架 Microsoft Store 及Linux等商店的指北](https://xmuli.blog.csdn.net/article/details/136334975)

  

<br>

## 9-高级编程

- [Lambda 表达式详解](https://xmuli.blog.csdn.net/article/details/125775706)

- [Qt 信号和槽原理分析，手写实现信号和槽，模拟 moc 生成 moc_xxx.cpp 过程](https://xmuli.blog.csdn.net/article/details/115305903) [★★★]
- [QT 项目 CMake 设置国际化支持](https://xmuli.blog.csdn.net/article/details/114439385) 
- [Qt4 和 Qt5 的信号和槽的用法差异](https://xmuli.blog.csdn.net/article/details/118346008) 
- [高分屏、分辨率、DPI、PPI，及 Qt 处理高分屏](https://xmuli.blog.csdn.net/article/details/108905279) [★★]
- [如何给上游 QT 提交 BUG 反馈和贡献代码 PATCH？](https://xmuli.blog.csdn.net/article/details/107220867)  [★★★★]

- [如何构建 QT5（5.15）](https://xmuli.blog.csdn.net/article/details/114259155) 
- [在 Mac 编译成功运行 QT 5.15 源码：Debug + Release 版本](https://xmuli.blog.csdn.net/article/details/114259186)

<br>

## 10-项目商业级项目

> 更多项目介绍参见 [Product](https://product.xmuli.tech/)

**较火 /  高规格的完整项目** 🔥🔥🔥

- [极简的电脑管家，一键关闭 Windows Defender (Anti-Virus).](https://github.com/XMuli/windows-defender-close)  【windows-defender-close】[★★]

- 截图三部曲，入门至商业级水准作品：  难 → 易
  1. [SunnyCapturer 跨平台的截图软件，支持离线OCR，图片翻译，贴图，钉图](https://xmuli.blog.csdn.net/article/details/136373241)  [★★★★★ 2023-2025] ：👉 [SunnyCapturer 官网](https://sunnycapturer.xmuli.tech)
  2. [FLIPPED 一款简易且漂亮的跨平台截图和贴图的软件](https://xmuli.blog.csdn.net/article/details/130053230) [★★★]
  3. [ShotX 一个轻量级的 跨平台截图](https://github.com/XMuli/ShotX)  [★]


  - [简洁且易用的ChatGPT&AI的桌面应用程序ThinkyMate → 不需登录](https://xmuli.blog.csdn.net/article/details/135488438)  [★★★★★ 2024]
  - [Sunny 截图上架 Microsoft Store 及Linux等商店的指北](https://xmuli.blog.csdn.net/article/details/136334975)
  - [分享如何拥有一份私人的『开源代码签名证书』](https://xmuli.blog.csdn.net/article/details/135487951)

<br>

**新人友好的项目**

- [项目实战：仿 QQ 的单聊，属 GUI 界面 ](https://xmuli.blog.csdn.net/article/details/79341062)
- [项目实战：仿 QQ 的群聊，属 GUI 界面](https://xmuli.blog.csdn.net/article/details/96437681)
- [项目实战：C 语言写 Socket 的 TCP 聊天，属 CUI 控制台](https://xmuli.blog.csdn.net/article/details/81808722)
- [项目实战：C 语言写 Socket 的 UDP 聊天，属 CUI 控制台](https://xmuli.blog.csdn.net/article/details/81809168)
- [项目实战：QT5 的 Quick 仿写 QQ  2019 简洁版的登录界面，含 GUI 界面](https://xmuli.blog.csdn.net/article/details/80448144)
- [QT5/C++项目：QT象棋【初版】](https://xmuli.blog.csdn.net/article/details/80931400) [★★★★★]
- [QT5/C++项目：基于QT的跨平台网络对战象棋（一）](https://xmuli.blog.csdn.net/article/details/89284983) [★★★★★]
- [QT5/C++项目：基于QT的跨平台网络对战象棋（二）](https://xmuli.blog.csdn.net/article/details/89285968) [★★★★★]
- [QT5/C++项目：基于QT的跨平台网络对战象棋（三）](https://xmuli.blog.csdn.net/article/details/89286553) [★★★★★]



**硬件**

- [小米AX6S刷OpenWrt和开启OpenClash，及刷回官网固件](https://xmuli.blog.csdn.net/article/details/128268719)

- [小米路由器 R4A 刷原生 OpenWrt 后的风景](https://xmuli.blog.csdn.net/article/details/128523087)

<br>

## 11-服务器开发之Linux基础编程

💻： UOS20 (Debian8+) 📎 gcc/g++ 8.3.0 📎 gdb 8.0 或 MacOS 10.14.6  📎 gcc/g++ 9.2.0 📎 gdb 8.3

**GCC/G++**

- [在MacOS上面通过brew命令安装gcc编译器集](https://xmuli.blog.csdn.net/article/details/104639656) 【unix_linux_01_test_gcc】
- [gcc和g++的区别，编译.c和.cpp文件的区别](https://xmuli.blog.csdn.net/article/details/104645129) 【unix_linux_02_c_cpp】
- [gcc工作流程：预处理，编译，汇编，链接](https://xmuli.blog.csdn.net/article/details/104693603) 【unix_linux_03_gcc_workflow】
- [Linux下使用gcc生成静态库.a和调用（图文并茂，坑已踩完）](https://xmuli.blog.csdn.net/article/details/104692241) 【unix_linux_04_make_so_a】
- [Linux下使用gcc生成动态库.so和调用（图文并茂，坑已踩完）](https://xmuli.blog.csdn.net/article/details/104692370) 【unix_linux_04_make_so_a】
- [在Linux中，编写入门的makefile文件，然后逐渐迭代](https://xmuli.blog.csdn.net/article/details/104758512) 【unix_linux_05_makefile】

<br>

**GDB**

- [ 在MacOS10.14.6安装最新gdb8.3的详细教程，含可能遇到的所有坑(网上最新教程)](https://xmuli.blog.csdn.net/article/details/104784641) 【unix_linux_06_gdb】
- [gdb调试器的使用，初探全貌](https://xmuli.blog.csdn.net/article/details/104904798) 【unix_linux_06_gdb】

<br>

**程序运行原理，文件描述符，PCB**

- [Linux中文件操作，软硬链接ln，用户权限chmod、chown，文件查找和检索find、grep，压缩gz，bz2](https://xmuli.blog.csdn.net/article/details/105010222) 
- [Linux中虚拟地址空间、pcb、文件描述符、C库函数工作流程、标准库和系统库函数区别](https://xmuli.blog.csdn.net/article/details/105029261) 
- [Linux中man手册，阻塞和非阻塞，stat，文件操作和遍历，文件描述符复制dup()](https://xmuli.blog.csdn.net/article/details/105031987) 【unix_linux_07_sysfun】

<br>

## 12-服务器开发之Linux系统编程

**进程间通信**

- [Linux中fork创建兄弟子进程，验证进程之间全局变量不共享，exec函数族](https://xmuli.blog.csdn.net/article/details/105157044) 【 unix_linux_08_fork / unix_linux_09_exec 】
- [Linux中孤儿进程，僵尸进程，进程回收wait、waitpid函数](https://xmuli.blog.csdn.net/article/details/105164215) 【unix_linux_10_orphan_zombie_process】
- [父子进程、兄弟子进程之间通信方式--匿名管道pipe(适用于有血缘关系的进程)](https://xmuli.blog.csdn.net/article/details/105254078) 【unix_linux_11_pipe】
- [Linux中普通的进程间通信方式--有名管道fifo(适用于无血缘关系的进程)](https://xmuli.blog.csdn.net/article/details/105266919)  【unix_linux_12_fifo】
- [Linux中进程间的通信方式--内存映射区mmap()](https://xmuli.blog.csdn.net/article/details/105322927)  【unix_linux_13_mmap】

<br>

**信号和守护进程**

- [Linux中系统信号初识，和函数kill，raise，abort，alarm，setitimer](https://xmuli.blog.csdn.net/article/details/105357886) 【unix_linux_14_signal】
- [Linux中未决信号集和阻塞信号集的状态关系sigaddset，以及捕捉信号函数](https://xmuli.blog.csdn.net/article/details/105448914) 【unix_linux_15_sys_usr_signal】
- [Linux中创建守护进程setsid()](https://xmuli.blog.csdn.net/article/details/105453850) 【unix_linux_16_daemon】

<br>

**多线程**

- [Linux中创建多线程实例pthread_create()](https://xmuli.blog.csdn.net/article/details/105546234) 【unix_linux_17_thread】
- [Linux中多线程操作函数pthread_exit()、pthread_jion()、pthread_detach()、pthread_cancel()](https://xmuli.blog.csdn.net/article/details/105620043) 【unix_linux_17_thread】
- [Linux中使用使用互斥量(锁)Mutex来操持多线程同步执行pthread_mutex_lock()](https://xmuli.blog.csdn.net/article/details/105779111) 【unix_linux_18_mutex】
- [Linux中原子操作，死锁原因以及解决方法，读写锁的属性和函数使用pthread_rwlock_wrlock()](https://xmuli.blog.csdn.net/article/details/105800949) 【unix_linux_19_pthread_rwlock_wrlock】
- [Linux中多线程使用条件变量阻塞线程，和pthread_cond_wait()函数使用](https://xmuli.blog.csdn.net/article/details/105885580) 【unix_linux_20_conditton】
- [Linux中多线程使用信号量(信号灯)，和sem_wait()函数使用](https://xmuli.blog.csdn.net/article/details/105885816) 【unix_linux_21_semaphore】

<br>

## 13-服务器开发之Linux网络编程

- 感觉基础的网络理论基础知识已会，写过一些实战项目的代码，可以参考第 10 章部分；后面深入底层网络完成，有空再整理文章。

- 见本仓库的 `unix_linux_基础知识_性能优化_操作系统原理_高清图谱.jpg` 文件

- Linux / Unix 学习完整系列（基础 / 编译 / 进程间通信 / 信号 / 守护进程 / 多线程等：可见 [linuxExample](https://github.com/xmuli/linuxExample)

<br>

## 14-Windows 系统开发验证代码

- 对 C++ 和 WebView 的程序开启能效模式，降低CPU和功耗【win_01_efficiency_mode】
- 获取显卡和驱动的版本【win_02_get_gpu_version】

<br>

## 15-研发遇到的疑难杂症经验

- [研发遇到的疑难杂症经验](./研发遇到的疑难杂症经验.md) 

<br>

# 许可协议

<img src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2023/20230618194948.png" width="50%"/>

博客代码基于Apache License 2.0 协议进行分发和使用，更多信息参见 [协议文件](/LICENSE)。

所含文章使用以下协议进行保护：[署名-非商业性使用-禁止演绎](http://creativecommons.org/licenses/by-nc-nd/3.0/cn/)。

