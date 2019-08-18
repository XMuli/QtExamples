# QtExamples

<img src="https://raw.githubusercontent.com/touwoyimuli/FigureBed/master/img/20190818185031.png"/>

​                                                                                                          我也不知道为什么，就是想放这么一张图在这里。



## 项目介绍：

Qt5 各个控件使用的一个例子、以及一些底层原理或者技巧性的理解，即是自己所学记录，亦可以互相交流共享学习，**有朋自远方互联网而来，不亦说乎？** 



刚大学毕业，大二开始正式(日以继夜的敲)学习c/c++路线知识，但今年已经的毕业，虽然学习过程中，距今学习qt知识，也有一年多了，中间有写一些比如[**中国象棋**](https://blog.csdn.net/qq_33154343/article/details/89284983)，**QQ**（的 [登录](https://blog.csdn.net/qq_33154343/article/details/80448144)/ [私聊](https://blog.csdn.net/qq_33154343/article/details/79341062)、[群聊](https://blog.csdn.net/qq_33154343/article/details/96437681)等功能），**但是却总是感觉有一种半路出家的学习qt的柑橘**，想着`c++`的知识还算学习的比较系统且完备(个人感觉)。一直在想要不要过的轻松点，把qt给**推到重来**，期间犹豫不定，工作的话，用到相关知识，再去百度谷歌一下，够用即可，后面或许会去学习其他部分的知识，qt也许只是一个过渡呢？但是写着写着，发现这个跨平台是真的好用，越发发现其设计的简洁、方便还带一种设计的美感，让我逐渐沉迷其中，近日想清楚了，**下定决心，还是推倒重来**，全过程的熟悉和了解的qt的所有相关，或许期间会比较辛苦(毕竟还附带同时维护两个blog和一个github)，但是我想着，以qt为媒介，学会使用、思想、架构设计、经验，或许会耗时一两年吧，倘若那个时候，这个系列也已经写完了的话，应该对这个也有一定的认知，到时候，再去接触，学习更高的平台和架构思想，应该会有较大的帮助。算是一个人生今后的一个短暂规划，学习不用急于求成而焦虑，自然水到渠成。

​																																					2019-08-18

## 说明：

会将该系列的源码，文章等系列，全部托管于这个仓库，该系列的主线任务只是讲解qt的相关文章，超出或者其他部分。

<font color=#70AD47 size=4 face="幼圆">**开发环境：**</font>    `win10 x64 专业版 1803`   <font color=#70AD47 size=4 face="幼圆">**操作系统版本**</font>：`17134.829` 

<font color=#70AD47 size=4 face="幼圆">**开发软件：** </font>  `Qt Creator 4.8.2 (Enterprise)` 、 `Qt 5.9.8`

<font color=#70AD47 size=4 face="幼圆">**编码语言：**</font>![](https://img.shields.io/badge/language-c++-orange.svg)

<font color=#70AD47 size=4 face="幼圆">**支持平台：**</font>![](https://img.shields.io/conda/pn/conda-forge/qt?style=plastic)

<br>

## 项目文章系列：

### 第一部分：预备知识

- `windows`环境下安装`Qt Creator`作为`c++`的**IDE**开发工具，学习和使用**qt**  (推荐)
- [Qt Creator 安装SDK，在MSVC编译模式下使用CDB调试器](https://blog.csdn.net/qq_33154343/article/details/98779698) 
- `windows`环境下安装`Qt Creator` + `Visual Studio 2015`作为`c++`的`IDE`开发工具，学习和使用**qt**  (备选)
- [`windows`环境下安装`Qt Creator 5.9` + `Visual Studio 2017专业版`](https://blog.csdn.net/qq_33154343/article/details/78587699)  参考此文 （备选）
- `Qt Creator` **IDE**的界面组成和使用讲解
- 编写一个**qt**的第一个项目： `Hello World`的项目

### 第二部分：qt生成原理/运行机制

- [`make` `makefile` `cmake` `qmake`都是什么，有什么区别？](https://blog.csdn.net/qq_33154343/article/details/98170236) 

### 第三部分：常用控件



### 补充部分：补充较杂的知识点

##### 乱码相关：

- [ 输出乱码原因：古文码、口字码、符号码、问号码、棍拷码](https://blog.csdn.net/qq_33154343/article/details/99617767) 
- [qt5 中文乱码解决](https://blog.csdn.net/qq_33154343/article/details/95344312) 
- [Qt字符串有中文，编译不通过解决方法：](https://blog.csdn.net/qq_33154343/article/details/79130275) 
- [乱码原因（Qt版本）_附上语文的pdf版本](https://blog.csdn.net/qq_33154343/article/details/79039644) 
- [qt中文乱码问题](https://blog.csdn.net/qq_33154343/article/details/78686103)  
- [借Qt中文乱码谈谈Coding中的编码问题](https://blog.csdn.net/qq_33154343/article/details/78686075) 



- [Qt5与Qt4的信号接收差异](https://blog.csdn.net/qq_33154343/article/details/79130732) 

- `qt`的信号和槽关系
- `qt`中Lam表达式

### 

<br>

## 编译

倘若自己的个人版本，不同于作者，且又编译运行屡次失败，**靠谱方法**：请重装系统之后，安装与我的同一版本，发开编程环境[qt-opensource-windows-x86-5.9.8.exe](http://download.qt.io/archive/qt/5.9/5.9.8/qt-opensource-windows-x86-5.9.8.exe)。 请使用下载**这一版本**5.9.8的`QtCreator`编译运行项目，可以保证运行成功  （使用Desktop Qt 5.9.8 MinGW 32 bit 直接编译运行）

<br>

## 互助
若是帮助到了你，可以点击该项目的的<img src="https://raw.githubusercontent.com/touwoyimuli/FigureBed/master/project_log/20190709023321.png" height="18" width="18"/>   **Star** 和<img src="https://raw.githubusercontent.com/touwoyimuli/FigureBed/master/project_log/20190709023317.png" height="18" width="18"/>  **Fork** 的两个图标，方便抬手之间，表示点个赞，手有余香


<br>

## 关于作者：

<font color=#70AD47 size=4 face="幼圆">**touwoyimuli：** </font> touwoyimuli@gmai.com         [作者更多联系方式](https://touwoyimuli.github.io/about/)

<br>

## 协议：

<img src='https://raw.githubusercontent.com/touwoyimuli/FigureBed/master/project_log/20190709052645.png' width='127' height='51'/>

<font color=#70AD47 size=4 face="幼圆">**touwoyimuli**</font> 博客代码基于GNU General Public License v3.0 协议进行分发和使用，更多信息参见[协议文件](/LICENSE)。

<img src='https://raw.githubusercontent.com/touwoyimuli/FigureBed/master/project_log/20190709052632.png' width='145.77' height='51'/>

<font color=#70AD47 size=4 face="幼圆">**touwoyimuli**</font> 所含文章使用以下协议进行保护：[署名-非商业性使用-禁止演绎](http://creativecommons.org/licenses/by-nc-nd/3.0/cn/)。