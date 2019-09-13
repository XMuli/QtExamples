## 说明【https://touwoyimuli.github.io/】：

　会将该系列的源码，文章等系列，全部托管于这个仓库，该系列的主线任务只是讲解qt的相关文章。

<font color=#70AD47 size=4 face="幼圆">**开发环境：**</font>    `win10 x64 专业版 1803`   <font color=#70AD47 size=4 face="幼圆">**操作系统版本**</font>：`17134.829` 

<font color=#70AD47 size=4 face="幼圆">**编程环境：**</font>  `deepin 15.11 x64 专业版 `    <font color=#70AD47 size=4 face="幼圆">**Kernel：**</font>  `x86_64 Linux 4.15.0-30deepin-generic`

<font color=#70AD47 size=4 face="幼圆">**开发软件：** </font>  `Qt Creator 4.8.2 (Enterprise)` 、 `Qt 5.9.8`

<font color=#70AD47 size=4 face="幼圆">**编码语言：**</font>![](https://img.shields.io/badge/language-c++-orange.svg)

<font color=#70AD47 size=4 face="幼圆">**支持平台：**</font>![](https://img.shields.io/conda/pn/conda-forge/qt?style=plastic)

<br>

# 项目文章系列：

[Qt推倒重学系列--总目录](https://touwoyimuli.github.io/2019/08/29/Qt推倒重学系列--总目录/)

<br>

## 第一部分：预备知识

- `windows`环境下安装`Qt Creator`作为`c++`的**IDE**开发工具，学习和使用**qt** <font color=#D0087E size=4 face="幼圆"> (推荐)</font>
- [Qt Creator 安装SDK，在MSVC编译模式下使用CDB调试器](https://touwoyimuli.github.io/2019/08/07/Qt-Creator-%E5%AE%89%E8%A3%85SDK%EF%BC%8C%E5%9C%A8MSVC%E7%BC%96%E8%AF%91%E6%A8%A1%E5%BC%8F%E4%B8%8B%E7%9A%84CDB%E8%B0%83%E8%AF%95%E5%99%A8/) 
- `windows`环境下安装`Qt Creator` + `Visual Studio 2015`作为`c++`的`IDE`开发工具，学习和使用**qt**  (备选) (csdn)
- [`windows`环境下安装`Qt Creator 5.9` + `Visual Studio 2017专业版`](https://blog.csdn.net/qq_33154343/article/details/78587699)  参考此文 （备选）(csdn)
- `Qt Creator` **IDE**的界面组成和使用讲解
- 编写一个**qt**的第一个项目： `Hello World`的项目

<br>

## 第二部分：qt生成原理/运行机制

- [make、makefile、cmake、qmake都是什么？有什么区别？](https://touwoyimuli.github.io/2019/08/01/make-makefile-cmake-qmake-%E9%83%BD%E6%98%AF%E4%BB%80%E4%B9%88%EF%BC%8C%E6%9C%89%E4%BB%80%E4%B9%88%E5%8C%BA%E5%88%AB%EF%BC%9F/) 

<br>

## 第三部分：常用控件

- 一个默认的`Qt Widget`项目 【空】
- 元对象系统`moc`(**Meat-Object System**)的对象`MetaObject`和(含动态)属性`Propert`的用法【QtMeatObjectEx】
- 初识`QString`函数，用`QString`显示2/8/10/16进制互相转化 【QtQStringEx】
- `QString`常用的功能函数的介绍和用法 【QtQStringFunEx】
- `QSlider`的介绍和用法【QtQSliderEx】
- `QSlider`移动条、`QScrollBar`滚动条、`QProgressBar`进度条控件的联动【QtQProgressBarEx】
- `QSlider`仪表盘的用法【QtQdialQLCDEx】
- 时间日期(`QTime`/`QDate`/`QDateTime`)和定时器(`QTimer`)的介绍和使用 【QtDateTimeEx】
- `QComboBox`(下拉列表框)和`QPlainTextEdit`(多行富文本编辑器)的用法 【QtQcomboBoxEx】

<br>

## 第四部分：自定义风格样式QStyle

- 自定义`QStyle`界面所有控件的风格，换肤效果的教程，自定义继承`QCommonStyle`的风格类【QtCustomStyleEx】
- 预备知识：`QStyle`、`QCommonStyle`d等讲解  
- [更换`Qt`应用程序的界面`UI`，实现换肤，改用自带其他默认`QStyle`风格样式](https://touwoyimuli.github.io/2019/08/29/%E6%9B%B4%E6%8D%A2%60Qt%60%E5%BA%94%E7%94%A8%E7%A8%8B%E5%BA%8F%E7%9A%84%E7%95%8C%E9%9D%A2%60UI%60%EF%BC%8C%E5%AE%9E%E7%8E%B0%E6%8D%A2%E8%82%A4%EF%BC%8C%E6%94%B9%E7%94%A8%E8%87%AA%E5%B8%A6%E5%85%B6%E4%BB%96%E9%BB%98%E8%AE%A4%60QStyle%60%E9%A3%8E%E6%A0%BC%E6%A0%B7%E5%BC%8F/) 
- [QStyle自定义重绘QSlider控件](https://touwoyimuli.github.io/2019/09/04/%60QStyle%60%E8%87%AA%E5%AE%9A%E4%B9%89%E9%87%8D%E7%BB%98%60QSlider%60%E6%8E%A7%E4%BB%B6/) 
- [QStyle自定义重绘QRubberBand控件](https://touwoyimuli.github.io/2019/09/07/QStyle%E8%87%AA%E5%AE%9A%E4%B9%89%E9%87%8D%E7%BB%98QRubberBand%E6%8E%A7%E4%BB%B6/) 

<br>

## 补充部分：补充较杂的知识点

#### 乱码相关：

- [输出乱码原因：古文码、口字码、符号码、问号码、棍拷码](https://touwoyimuli.github.io/2019/08/14/%E8%BE%93%E5%87%BA%E4%B9%B1%E7%A0%81%E5%8E%9F%E5%9B%A0%EF%BC%9A%E5%8F%A4%E6%96%87%E7%A0%81%E3%80%81%E5%8F%A3%E5%AD%97%E7%A0%81%E3%80%81%E7%AC%A6%E5%8F%B7%E7%A0%81%E3%80%81%E9%97%AE%E5%8F%B7%E7%A0%81%E3%80%81%E6%A3%8D%E6%8B%B7%E7%A0%81/) 
- [qt5 中文乱码解决](https://touwoyimuli.github.io/2019/07/10/qt5-%E4%B8%AD%E6%96%87%E4%B9%B1%E7%A0%81%E8%A7%A3%E5%86%B3/) 
- [Qt字符串有中文，编译不通过解决方法：](https://blog.csdn.net/qq_33154343/article/details/79130275)  (csdn)
- [乱码原因（Qt版本）_附上语文的pdf版本](https://blog.csdn.net/qq_33154343/article/details/79039644)   (csdn)
- [qt中文乱码问题](https://blog.csdn.net/qq_33154343/article/details/78686103)    (csdn)
- [借Qt中文乱码谈谈Coding中的编码问题](https://blog.csdn.net/qq_33154343/article/details/78686075)   (csdn)

<br>

- [Qt5与Qt4的信号接收差异](https://blog.csdn.net/qq_33154343/article/details/79130732)   (csdn)
- `qt`的信号和槽关系
- `qt`中Lam表达式

<br>