# QtExamples:

<img src="https://raw.githubusercontent.com/touwoyimuli/FigureBed/blog-imange/img/20190818185031.png"/>
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　我也不知道为什么，就是想放这么一张图在这里。

<br>

## 项目介绍：

　Qt5 各个控件使用的一个例子、以及一些底层原理或者技巧性的理解，即是自己所学记录，亦可以互相交流共享学习，**有朋自远方互联网而来，不亦说乎？**



　刚大学毕业，大二开始正式(日以继夜的敲)学习c/c++路线知识，但今年已经的毕业，虽然学习过程中，距今学习qt知识，也有一年多了，中间有写一些比如[**中国象棋**](https://blog.csdn.net/qq_33154343/article/details/89284983)，**QQ**（的 [登录](https://blog.csdn.net/qq_33154343/article/details/80448144)/ [私聊](https://blog.csdn.net/qq_33154343/article/details/79341062)、[群聊](https://blog.csdn.net/qq_33154343/article/details/96437681)等功能），**但是却总是感觉有一种半路出家的学习qt的柑橘**，想着`c++`的知识还算学习的比较系统且完备(个人感觉)。一直在想要不要过的轻松点，把qt给**推到重来**，期间犹豫不定，工作的话，用到相关知识，再去百度谷歌一下，够用即可，后面或许会去学习其他部分的知识，qt也许只是一个过渡呢？但是写着写着，发现这个跨平台是真的好用，越发发现其设计的简洁、方便还带一种设计的美感，让我逐渐沉迷其中，近日想清楚了，**下定决心，还是推倒重来**，全过程的熟悉和了解的qt的所有相关，或许期间会比较辛苦(毕竟还附带同时维护两个blog和一个github)，但是我想着，以qt为媒介，学会使用、思想、架构设计、经验，或许会耗时一两年吧，倘若那个时候，这个系列也已经写完了的话，应该对这个也有一定的认知，到时候，再去接触，学习更高的平台和架构思想，应该会有较大的帮助。算是一个人生今后的一个短暂规划，学习不用急于求成而焦虑，自然水到渠成。
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　2019-08-18

<br>

## 说明：

　会将该系列的源码，文章等系列，全部托管于这个仓库，该系列的主线任务只是讲解qt的相关文章。

<font color=#70AD47 size=4 face="幼圆">**开发环境：**</font>    `win10 x64 专业版 1803`   <font color=#70AD47 size=4 face="幼圆">**操作系统版本**</font>：`17134.829` 

<font color=#70AD47 size=4 face="幼圆">**开发软件：** </font>  `Qt Creator 4.8.2 (Enterprise)` 、 `Qt 5.9.8`

<font color=#70AD47 size=4 face="幼圆">**编码语言：**</font>![](https://img.shields.io/badge/language-c++-orange.svg)

<font color=#70AD47 size=4 face="幼圆">**支持平台：**</font>![](https://img.shields.io/conda/pn/conda-forge/qt?style=plastic)

<br>

# 项目文章系列：

## 第一部分：预备知识

- `windows`环境下安装`Qt Creator`作为`c++`的**IDE**开发工具，学习和使用**qt**  (推荐)
- [Qt Creator 安装SDK，在MSVC编译模式下使用CDB调试器](https://blog.csdn.net/qq_33154343/article/details/98779698) 
- `windows`环境下安装`Qt Creator` + `Visual Studio 2015`作为`c++`的`IDE`开发工具，学习和使用**qt**  (备选)
- [`windows`环境下安装`Qt Creator 5.9` + `Visual Studio 2017专业版`](https://blog.csdn.net/qq_33154343/article/details/78587699)  参考此文 （备选）
- `Qt Creator` **IDE**的界面组成和使用讲解
- 编写一个**qt**的第一个项目： `Hello World`的项目

<br>

## 第二部分：qt生成原理/运行机制

- [`make` `makefile` `cmake` `qmake`都是什么，有什么区别？](https://blog.csdn.net/qq_33154343/article/details/98170236) 

<br>

## 第三部分：常用控件

- 一个默认的`Qt Widget`项目 【空】
- 元对象系统`moc`(**Meat-Object System**)的对象`MetaObject`和(含动态)属性`Propert`的用法【QtMeatObjectEx】
- [`QString`在2 ／8／10／16进制之间转换](https://blog.csdn.net/qq_33154343/article/details/100860030) 【QtQStringEx】
- [`QString`常用的功能函数的介绍和用法](https://blog.csdn.net/qq_33154343/article/details/100860270) 【QtQStringFunEx】
- [`QSlider`和`QAbstractSlider`的介绍和用法](https://blog.csdn.net/qq_33154343/article/details/100944831)【QtQSliderEx】
- [`QSlider`移动条、`QScrollBar`滚动条、`QProgressBar`进度条控件的联动](https://blog.csdn.net/qq_33154343/article/details/101003081)【QtQProgressBarEx】
- [仪表盘`QSlider`和数值显示`QLCD_NUmber`的讲解和使用](https://blog.csdn.net/qq_33154343/article/details/101003115)【QtQdialQLCDEx】
-  [时间日期(`QTime`/`QDate`/`QDateTime`)和定时器(`QTimer`)的介绍和使用](https://blog.csdn.net/qq_33154343/article/details/101040841)【QtDateTimeEx】
- [`QComboBox`(下拉列表框)和`QPlainTextEdit`(多行富文本编辑器)的用法](https://blog.csdn.net/qq_33154343/article/details/101127870) 【QtQcomboBoxEx】
- [列表控件`QListWidget`和工具按钮`QToolButton`的和用法](https://blog.csdn.net/qq_33154343/article/details/101314908)【QtQListWidgetEx】
- 目录树组件`QTreeWidget`和停靠区域组件`QDockWidget`的用法【QtQTreeWidgetEx】
- 【QtQTableWidgetEx】
- 【QtQFileSystemModelEx】 

<br>

## 第四部分：自定义风格样式QStyle

- 自定义`QStyle`界面所有控件的风格，换肤效果的教程，自定义继承`QCommonStyle`的风格类【QtCustomStyleEx】
- 预备知识：`QStyle`、`QCommonStyle`d等讲解  
- [更换`Qt`应用程序的界面`UI`，实现换肤，改用自带其他默认`QStyle`风格样式](https://mp.csdn.net/mdeditor/100148539#) 
- [`QStyle`自定义重绘滑动条`QSlider`控件](https://blog.csdn.net/qq_33154343/article/details/100545769) 
- [`QStyle`自定义重绘`QRubberBand`控件](https://blog.csdn.net/qq_33154343/article/details/100588428) 
- [重绘的`QStyle`中`sizeFromContents`()没有被调用](https://blog.csdn.net/qq_33154343/article/details/100941134) 
- [`QStyle`之`PenStyle`的`CustomDashLine`使用](https://blog.csdn.net/qq_33154343/article/details/100659576) 
- [`QStyle`自定义重绘滑动条`QSlide`r控件二](https://blog.csdn.net/qq_33154343/article/details/100942637) 
- [QStyle自定义重绘`QScrollBar`](https://blog.csdn.net/qq_33154343/article/details/100943187)

<br>

## 补充部分：补充较杂的知识点

### 使用Qt Creator的小技巧：

- [小技巧：Design设计师里，无法拖拽action到toolbar里](https://blog.csdn.net/qq_33154343/article/details/100168170) 
- [小技巧：设置`QToolBox`的每一页page的使用单独的布局（`QTabWidget`同理）](https://mp.csdn.net/mdeditor/100185025#) 

<br>

### 乱码相关：

- [ 输出乱码原因：古文码、口字码、符号码、问号码、棍拷码](https://blog.csdn.net/qq_33154343/article/details/99617767) 
- [qt5 中文乱码解决](https://blog.csdn.net/qq_33154343/article/details/95344312) 
- [Qt字符串有中文，编译不通过解决方法：](https://blog.csdn.net/qq_33154343/article/details/79130275) 
- [乱码原因（Qt版本）_附上语文的pdf版本](https://blog.csdn.net/qq_33154343/article/details/79039644) 
- [qt中文乱码问题](https://blog.csdn.net/qq_33154343/article/details/78686103)  
- [借Qt中文乱码谈谈Coding中的编码问题](https://blog.csdn.net/qq_33154343/article/details/78686075) 

<br>

- [Qt5与Qt4的信号接收差异](https://blog.csdn.net/qq_33154343/article/details/79130732) 
- `qt`的信号和槽关系
- `qt`中Lam表达式

<br>

## 同步github.io博客：

- github.io的同步总目录：[WiKi](https://github.com/touwoyimuli/QtExamples/wiki/Qt%E6%8E%A8%E5%80%92%E9%87%8D%E5%AD%A6%E7%B3%BB%E5%88%97--%E6%80%BB%E7%9B%AE%E5%BD%95%E3%80%90github.io%E3%80%91) 

- Qt Creator使用小技巧：[WiKi](https://github.com/touwoyimuli/QtExamples/wiki/Qt%E4%BD%BF%E7%94%A8%E7%9A%84%E4%B8%80%E4%B8%8B%E5%B0%8F%E6%8A%80%E5%B7%A7) 

<br>

## 如何编译：

**编译方式:** [WiKi](https://github.com/touwoyimuli/QtExamples/wiki/%E5%A6%82%E4%BD%95%E7%BC%96%E8%AF%91)

<br>

## 约定式提交（规范）：

[github 约定式提交：](https://www.conventionalcommits.org/zh/v1.0.0-beta.3/) 一种规范，用以给提交信息增加人机可读的信息

<br>

## 互助：

若是帮助到了你，或者觉得有用，可以点击该项目的的<img src="https://raw.githubusercontent.com/touwoyimuli/FigureBed/master/project_log/20190709023321.png" height="18" width="18"/>   **Star** 和<img src="https://raw.githubusercontent.com/touwoyimuli/FigureBed/master/project_log/20190709023317.png" height="18" width="18"/>  **Fork** 的两个图标，方便抬手之间，表示点个赞，手有余香

<br>

## 关于作者：

<font color=#70AD47 size=4 face="幼圆">**touwoyimuli：** </font> touwoyimuli@gmai.com         [作者更多联系方式](https://touwoyimuli.github.io/about/)

<br>

## 协议：

<img src='https://raw.githubusercontent.com/touwoyimuli/FigureBed/blog-imange/img/20190709052148.jpg' width='240' height='127'/>

<font color=#70AD47 size=4 face="幼圆">**touwoyimuli：** </font> 博客代码基于Apache License 2.0 协议进行分发和使用，更多信息参见[协议文件](/LICENSE)。

<img src='https://raw.githubusercontent.com/touwoyimuli/FigureBed/blog-imange/img/20190709052153.jpg' width='127' height='127'/>

<font color=#70AD47  size=4 face="幼圆">**touwoyimuli：** </font> 所含文章使用以下协议进行保护：[署名-非商业性使用-禁止演绎](http://creativecommons.org/licenses/by-nc-nd/3.0/cn/)。