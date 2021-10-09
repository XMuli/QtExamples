# QtExamples:

<div align=center>
<img src="https://raw.githubusercontent.com/touwoyimuli/FigureBed/blog-imange/img02/IMG_GIRL.png"  width="50%"/>
</div>


　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　我也不知道为什么，就是想放这么一张图在这里。

<br>

[TOC]

<br>

## 项目介绍：

　　✅ `Qt` 的 `GUI` 基础控件用法，网络；

　　✅ `DTK` 重绘控件方式的框架解析；

　　✅ `QtCrator` 使用和一些小技巧；

　　✅ `Qt` 原理/运行机制理解

　　自己所学记录，亦可以互相交流共享学习，<font color=#D0087E size=4 face="幼圆">**有朋自远方互联网而来，不亦悦乎？**</font>

<br>

## 关于 QT 系列文章：

​		会将该系列的源码，文章等系列，全部托管于这个仓库，该系列的主线任务是讲解 **Qt** 的相关文章。

<font color=#70AD47 size=4 face="幼圆">**开发系统：**</font>   `MacOS 10.14.6 (18G103)`  |  `win10 x64 专业版 1803`  |  `UOS 20 x64 专业版 `

<font color=#70AD47 size=4 face="幼圆">**编码软件：** </font> `Qt 5.9.8+`  | `Qt Creator 4.8.2 (Enterprise)` 

<font color=#70AD47 size=4 face="幼圆">**编码语言：**</font>![](https://img.shields.io/badge/language-c++-orange.svg)

<br>

# 文章系列：

## 第一部分：预备知识

- **windows 系统：**
    - [`windows10`环境下安装`Qt Creator5.9.8`作为`c++`的**IDE**开发工具，学习和使用**qt**  (最佳推荐)](https://blog.csdn.net/qq_33154343/article/details/103674579)
    - [Qt Creator 安装SDK，在MSVC编译模式下使用CDB调试器](https://blog.csdn.net/qq_33154343/article/details/98779698) 
    - [`windows`环境下安装`Qt Creator` + `Visual Studio 2015`作为`c++`的`IDE`开发工具，学习和使用**qt**  (备选)](https://blog.csdn.net/qq_33154343/article/details/103755569)
    - [`windows`环境下安装`Qt Creator 5.9` + `Visual Studio 2017专业版  `  参考此文 （备选）](https://blog.csdn.net/qq_33154343/article/details/78587699)  
    - [Win10上CLion、CMake、MSVC/MinGW配置Qt开发](https://blog.csdn.net/qq_33154343/article/details/120070828) 
    - [VS2017调试Qt源码，安装PDB](https://blog.csdn.net/qq_33154343/article/details/120339797)
    
    <br>
    
- **MacOS 系统：**
  
    - [`MacOS10.14.6`环境下安装`QtCreator5.9.8`作为`c++`的**IDE**开发工具，学习和使用**qt**(推荐)](https://blog.csdn.net/qq_33154343/article/details/103231202)

<br>

- **Linux 系统:**
    - [在win10里面的VMware安装UOS20，在uos20里面安装QtCreator，配置dtk开发环境](https://blog.csdn.net/qq_33154343/article/details/103733327)
    - [MacOS10.14安装虚拟机Parallels_Desktop，安装UOS20和 QtCreaor，搭建dtk开发环境](https://blog.csdn.net/qq_33154343/article/details/104180794)
    - [在macOS 10.14的虚拟机VMware Fusionlimian里面安装deepin15.11（Linux）](https://blog.csdn.net/qq_33154343/article/details/102789047)
    - [Deepin / UOS 中配置 DTK 开发环境](https://blog.csdn.net/qq_33154343/article/details/112239518)
    - [重装uos/deepin v20后必安装软件(个人习惯)](https://xmuli.blog.csdn.net/article/details/106510975)
    - [ArchLinux + DDE 安装教程](https://xmuli.blog.csdn.net/article/details/107696563)
    - [对 GNU/Linux 介绍、ArchLinux社区氛围、DDE移植Arch流程](https://blog.csdn.net/qq_33154343/article/details/108378441)

<br>

- **IDE 基础讲解：**
    - [Qt Creator` 此**IDE**的界面基本组成和入门使用讲解(Win,Linux,MacOS搭配不同版本 Qt)](https://blog.csdn.net/qq_33154343/article/details/103942733)

<br>

## 第二部分：Qt 生成原理/运行机制

- [`make` `makefile` `cmake` `qmake`都是什么，有什么区别？](https://blog.csdn.net/qq_33154343/article/details/98170236) 
- [Qt 编程中 namespace Ui { class Widget; } 解析](https://blog.csdn.net/qq_33154343/article/details/98122981) 

<br>

## 第三部分：常用 GUI 控件

- 一个默认的`Qt Widget`项目 【空】
- [元对象系统moc(Meat-Object System)的对象MetaObject和(含动态)属性Propert的用法](https://xmuli.blog.csdn.net/article/details/105925608) 【QtMeatObjectEx】
- [`QString`在2 ／8／10／16进制之间转换](https://blog.csdn.net/qq_33154343/article/details/100860030) 【QtQStringEx】
- [`QString`常用的功能函数的介绍和用法](https://blog.csdn.net/qq_33154343/article/details/100860270) 【QtQStringFunEx】
- [`QSlider`和`QAbstractSlider`的介绍和用法](https://blog.csdn.net/qq_33154343/article/details/100944831)【QtQSliderEx】
- [`QSlider`移动条、`QScrollBar`滚动条、`QProgressBar`进度条控件的联动](https://blog.csdn.net/qq_33154343/article/details/101003081)【QtQProgressBarEx】
- [仪表盘`QSlider`和数值显示`QLCD_NUmber`的讲解和使用](https://blog.csdn.net/qq_33154343/article/details/101003115)【QtQdialQLCDEx】
- [时间日期(`QTime`/`QDate`/`QDateTime`)和定时器(`QTimer`)的介绍和使用](https://blog.csdn.net/qq_33154343/article/details/101040841)【QtDateTimeEx】
- [`QComboBox`(下拉列表框)和`QPlainTextEdit`(多行富文本编辑器)的用法](https://blog.csdn.net/qq_33154343/article/details/101127870) 【QtQcomboBoxEx】
- [列表控件`QListWidget`和工具按钮`QToolButton`的和用法](https://blog.csdn.net/qq_33154343/article/details/101314908)【QtQListWidgetEx】
- [目录树组件`QTreeWidget`和停靠区域组件`QDockWidget`的用法](https://blog.csdn.net/qq_33154343/article/details/103467757)【QtQTreeWidgetEx】
- [`QTableWidget`表格组件的属性介绍和使用](https://blog.csdn.net/qq_33154343/article/details/103485154)【QtQTableWidgetEx】
- [`QFileSystemModel`数据模型获取本机文件系统的使用](https://blog.csdn.net/qq_33154343/article/details/103544820)【QtQFileSystemModelEx】 
- [`getOpenFileName`标准对话框和自定义对话框的使用](https://blog.csdn.net/qq_33154343/article/details/103545066)【QtQDialogEx】
- [`QTableView`和`QStandardItemModel`的用法](https://blog.csdn.net/qq_33154343/article/details/103572418)【QtQStandardItemModelEx】
- [自定义和标准对话框的用法](https://blog.csdn.net/qq_33154343/article/details/103606981)【QtCustomDialogEx】
- [多文档界面`MDI`(`Multi-document Interface`)的实现，`QMdiArea`使用](https://blog.csdn.net/qq_33154343/article/details/103625380)【QtMDIEx】

<br>

## 第四部分：网络编程

- [主机信息查询`QHostInfo`和`QNetworkInterface`查询IP等](https://blog.csdn.net/qq_33154343/article/details/103707035)【QtQHostInfoEx】
- [`TCP`通信之`QTcpServer`和`QTcpSocket`，服务器和客户端通讯](https://blog.csdn.net/qq_33154343/article/details/103759735)【QtTcpEx】
- [`Upd`通信之`QUdpSocket`的`unicast`单播、`broadcast`广播、`multicast`组播](https://blog.csdn.net/qq_33154343/article/details/103789843)【QtUdpEx】
- [`QNetworkAccessManager`/`QNetworkReply`/`QNetworkRequest`实现高层网络的操作`http`](https://blog.csdn.net/qq_33154343/article/details/103811638) 【QtHttpEx】

<br>

## 第五部分：DTK 重绘控件原理解析（自定义样式 QStyle ）

- **DTK 历史发展：**
    - [DTK的历史起源、发展，和简单入门](https://xmuli.blog.csdn.net/article/details/106189533) 『🥳🥳』
    - [deepin、dde的历史起源与发展(附deepin所有版本的dde截图)](https://xmuli.blog.csdn.net/article/details/106195055) 『🥳🥳』
    - [UOS/Deepin 中配置 DTK 开发环境](https://xmuli.blog.csdn.net/article/details/112239518) 『🥳🥳』
    - [Deepin / DTK 文档参考资料集合](https://xmuli.blog.csdn.net/article/details/112244150)  『🥳🥳🥳🥳🥳』
- **预备知识：**
    - QStyle与QPen、QPush、QPalette、QPainter之间的区别 
    - [DTK 基础教程：自定义控件规范](https://xmuli.blog.csdn.net/article/details/108536588) 『🥳🥳』
    - [QStyle设置界面的外观和QCommonStyle继承关系图讲解和使用](https://blog.csdn.net/qq_33154343/article/details/104367878) 『👩‍💻👩‍💻👩‍💻』
    - [qt之proxy()代理探究](https://blog.csdn.net/qq_33154343/article/details/101571843)
    - [DTK常用和测试代码片](https://blog.csdn.net/qq_33154343/article/details/106187959)
- **感性理解👀：**
    - [应用软件在「UOS20和 MaOS10.14下」显示应用不同的QStyle「即：所有控件的样式换肤」](https://blog.csdn.net/qq_33154343/article/details/104305154)
    - [应用软件在「windows10 和 deepin10.15下」显示应用不同的`QStyle`「即：所有控件的样式换肤」](https://blog.csdn.net/qq_33154343/article/details/100148552) 
- **DTK 源码解析架构🤔：**
    - [QStyle/DTK重绘Qt-GUI已有控件,举例QScrollBar](https://blog.csdn.net/qq_33154343/article/details/104537944) 『👩‍💻👩‍💻👩‍💻』
    - [QStyle/DTK重绘自定义需求控件,举例MySwitchButton](https://blog.csdn.net/qq_33154343/article/details/104987446) 『👩‍💻👩‍💻👩‍💻』
    - [DTK常用和测试代码片 ](https://xmuli.blog.csdn.net/article/details/106187959) 
    - [DTK 每日自动更新其 API 文档](https://xmuli.blog.csdn.net/article/details/108756933)
    - [DTK 基础教程：自定义控件规范](https://xmuli.blog.csdn.net/article/details/108536588) [★★]

<br>

## 第六部分：Qt / IDE 出现乱码原因和解决：

- [愿编程不再乱码(含Qt)-根因深究](https://blog.csdn.net/qq_33154343/article/details/120661967) [★★★★★]
- [乱码原因产生和解决方案](https://xmuli.blog.csdn.net/article/details/109567352) [★★]
- [ 输出乱码原因：古文码、口字码、符号码、问号码、棍拷码](https://blog.csdn.net/qq_33154343/article/details/99617767) 
- [qt5 中文乱码解决](https://blog.csdn.net/qq_33154343/article/details/95344312) 
- [Qt字符串有中文，编译不通过解决方法：](https://blog.csdn.net/qq_33154343/article/details/79130275) 
- [乱码原因（Qt版本）_附上语文的pdf版本](https://blog.csdn.net/qq_33154343/article/details/79039644) 
- [qt中文乱码问题](https://blog.csdn.net/qq_33154343/article/details/78686103)  
- [借Qt中文乱码谈谈Coding中的编码问题](https://blog.csdn.net/qq_33154343/article/details/78686075) 

<br>

- [Qt4和Qt5的信号和槽的使用差异](https://xmuli.blog.csdn.net/article/details/118346008)
- `qt`中 Lambda 表达式

<br>

## 第七部分：QtCreator 的使用小技巧：

- [QtCreator设置代码美化 astyle 之 Artistic](https://blog.csdn.net/qq_33154343/article/details/101397429)
- [Qt Creator 关闭.cpp文件右侧的黄色警告](https://blog.csdn.net/qq_33154343/article/details/102943623)
- [小技巧：Design设计师里，无法拖拽action到toolbar里](https://blog.csdn.net/qq_33154343/article/details/100168170) 
- [小技巧：设置`QToolBox`的每一页page的使用单独的布局（`QTabWidget`同理）](https://blog.csdn.net/qq_33154343/article/details/100185025) 
- [小技巧：QtCreator用快捷键秒实现，声明在基类中重写的派生类(纯)虚函数](https://blog.csdn.net/qq_33154343/article/details/104457739) 
- [VS2019调试Qt5时QString显示为内存地址而非字符串](https://xmuli.blog.csdn.net/article/details/116244865) 

<br>

## 第八部分：提交规范和发布 Qt 程序：

- [约定式提交规范](https://www.conventionalcommits.org/zh-hans/v1.0.0-beta.4/)
- [Qt 项目在 Windows 平台上面发布成可执行程序](https://blog.csdn.net/qq_33154343/article/details/96448388) 
- [Qt 项目在 MacOS 平台上面发布成可执行程序](https://xmuli.blog.csdn.net/article/details/96448938#comments) 
- [Qt 项目在 Linux 平台上面发布成可执行程序](https://blog.csdn.net/qq_33154343/article/details/96448621) 
- [如何给上游 Qt 提交 Bug 反馈和贡献代码 PATCH？](https://xmuli.blog.csdn.net/article/details/107220867) 
- [Qt 项目用 Doxygen 生成 .qch，嵌入文档到 Assistants](https://xmuli.blog.csdn.net/article/details/114580630) 
- [修改 Doxygen 主题，生成 Qt 风格的文档](https://xmuli.blog.csdn.net/article/details/114591725) 
- [QtCreator 中自定义项目例子置于“欢迎-实例”中](https://xmuli.blog.csdn.net/article/details/115049715)

<br>

## 第 九部分：高级

- [高分屏、分辨率、DPI、PPI，及 Qt 处理高分屏](https://xmuli.blog.csdn.net/article/details/108905279) 
- [Qt 项目(Cmake)设置国际化支持](https://xmuli.blog.csdn.net/article/details/114439385) 
- [如何构建 QT5（5.15）](https://xmuli.blog.csdn.net/article/details/114259155) 
- [在 Mac 编译成功运行 qt5.15 源码：debug 和 release 版本](https://xmuli.blog.csdn.net/article/details/114259186)
- [Qt 信号和槽原理分析](https://xmuli.blog.csdn.net/article/details/115305903)

<br>

## 第十部分：项目

### 网络

- [QT5/C++项目：基于QT的跨平台网络对战象棋（一）（推荐★★★★）](https://blog.csdn.net/qq_33154343/article/details/89284983)
- [QT5/C++项目：基于QT的跨平台网络对战象棋（二）（推荐★★★★）](https://blog.csdn.net/qq_33154343/article/details/89285968)
- [QT5/C++项目：基于QT的跨平台网络对战象棋（三）（推荐★★★★）](https://blog.csdn.net/qq_33154343/article/details/89286553)
- [项目实战：Qt5／C++：TCP的C/S的聊天小程序 （带界面 GUI）](https://blog.csdn.net/qq_33154343/article/details/79341062)
- [项目实战：仿QQ的QQ简洁版2019群聊项目（带界面 GUI）](https://blog.csdn.net/qq_33154343/article/details/96437681)
- [项目实战Small example：C:Socket之Tcp编程 [终端 Terminal]](https://blog.csdn.net/qq_33154343/article/details/81808722)
- [项目实战Small example：C:Socket之UDP编程 [终端 Terminal]](https://blog.csdn.net/qq_33154343/article/details/81809168)
- [项目实战：Qt5／Quick：模仿扣扣登录界面[小程序]](https://blog.csdn.net/qq_33154343/article/details/80448144)

<br>

### 其它(Qt/DTK)

- [更换`Qt`应用程序的界面`UI`，实现换肤，改用自带其他默认`QStyle`风格样式](https://blog.csdn.net/qq_33154343/article/details/100148552) 
- [`QStyle`自定义重绘滑动条`QSlider`控件](https://blog.csdn.net/qq_33154343/article/details/100545769) 
- [`QStyle`自定义重绘`QRubberBand`控件](https://blog.csdn.net/qq_33154343/article/details/100588428) 
- [重绘的`QStyle`中`sizeFromContents`()没有被调用](https://blog.csdn.net/qq_33154343/article/details/100941134) 
- [`QStyle`之`PenStyle`的`CustomDashLine`使用](https://blog.csdn.net/qq_33154343/article/details/100659576) 
- [`QStyle`自定义重绘滑动条`QSlide`r控件二](https://blog.csdn.net/qq_33154343/article/details/100942637) 
- [QStyle自定义重绘`QScrollBar`](https://blog.csdn.net/qq_33154343/article/details/100943187) 
- [Deepin 自定义修改窗口圆角大小](https://xmuli.blog.csdn.net/article/details/109232878)  [商业开源项目★★★]
- [Deepin 开发任务栏网速插件 lfxSpeed](https://xmuli.blog.csdn.net/article/details/110672252) [★★★]
- [Deepin 愿望墙：社区插件等需求调研结果](https://xmuli.blog.csdn.net/article/details/112243878) [社区练手参考]
- [Deepin 任务栏网速插件推荐 lfxNet (重构 lfxSpeed)](https://xmuli.blog.csdn.net/article/details/113573870) [★★★★]

<br>

## 新手过来：

　　<font color=#D0087E size=4 face="幼圆">**新手**</font> 在深思熟虑后踏入的编程，容易遭遇如下如下几点:

1. 语言语法不熟悉🤦‍♀️
2. 相关 IDE 安装、配置不会；不懂如何创建自己所需的工程项目🤦‍♀️
3. 基础控件不认识，不会用🤦‍♀️
4. 难以🔍可阅读、成体系的低级博客，多为高热度Title文章🤦‍♀️
5. ...开始步入正轨👣
6. 也不知学编程到是底在学习什么❓👀
7. ...修行靠个人👩‍💻

<br>

## 分享所想：

1. 自己想学一遍 GUI 控件
2. 帮助真的新手实现0→1的入门，解决👆的1，2，3，4，6问题
3. 学习于网络，回馈于网络
4. 希望永久被🔍引擎检索到，以博客形式发表📝

<br>

## 我所想说：🙋‍♀️

<font color=#D0087E size=4 face="幼圆">虽然不盈利，会累，但因自由和开源软件而写的开心ya， 鸭鸭</font>

<br>

## 贡献：

若是帮助到了你，或者觉得有用，可以点击该项目的的<img src="https://raw.githubusercontent.com/touwoyimuli/FigureBed/master/project_log/20190709023321.png" height="18" width="18"/><font color=#D0087E size=4 face="幼圆">**Star**</font> 和<img src="https://raw.githubusercontent.com/touwoyimuli/FigureBed/master/project_log/20190709023317.png" height="18" width="18"/><font color=#D0087E size=4 face="幼圆">**Fork**</font> 的两个图标，方便抬手之间，表示点个赞，手有余香

<br>

## 作者：

[偕臧 | xmuli ](https://ifmet.cn)

<br>

## 协议：

<img src='https://raw.githubusercontent.com/touwoyimuli/FigureBed/blog-imange/img/20190709052148.jpg' width='240' height='127'/>

<font color=#70AD47 size=4 face="幼圆">**偕藏：** </font> 博客代码基于Apache License 2.0 协议进行分发和使用，更多信息参见[协议文件](/LICENSE)。

<img src='https://raw.githubusercontent.com/touwoyimuli/FigureBed/blog-imange/img/20190709052153.jpg' width='127' height='127'/>

<font color=#70AD47  size=4 face="幼圆">**偕藏：** </font> 所含文章使用以下协议进行保护：[署名-非商业性使用-禁止演绎](http://creativecommons.org/licenses/by-nc-nd/3.0/cn/)。