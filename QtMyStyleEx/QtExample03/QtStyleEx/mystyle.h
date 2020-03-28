/*
 *
 * Gmail:   touwoyimuli@gmai.com
 * blogs:   https://blog.csdn.net/qq_33154343
 *
 * -------------------------------------------------
 * Copyright 2019~2020 touwoyimuli
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MYSTYLE_H
#define MYSTYLE_H

#include <QCommonStyle>
#include <QPainter>

class MyStyle : public QCommonStyle
{
    Q_OBJECT //connect qobject_cast

public:
    //这里新增加的枚举，是属于 MyStyle:: , 而非 QStyle:: 范围
    enum ControlElement {
        CE_SwitchButton = QStyle::CE_CustomBase + 1,                   //switchButton 控件
        CE_CustomBase = QStyle::CE_CustomBase + 0xf00000
    };

    enum SubElement {
        SE_SwitchButtonGroove = QStyle::SE_CustomBase + 1,             //滑槽矩形大小
        SE_SwitchButtonHandle,                                         //滑块矩形大小
        SE_CustomBase = QStyle::SE_CustomBase + 0xf00000
    };

    enum PixelMetric {
        PM_SwitchButtonHandleWidth = QStyle::PM_CustomBase + 1,        //switch Handle width
        PM_SwithcButtonHandleHeight,                                   //switch Handle height
        PM_CustomBase = QStyle::PM_CustomBase + 0xf00000
    };

    enum PrimitiveElement {
        PE_SwitchButtonGroove = QStyle::PE_CustomBase + 1,             //滑槽
        PE_SwitchButtonHandle,                                         //滑块
        PE_CustomBase = QStyle::PE_CustomBase + 0xf00000
    };

public:
    MyStyle();

    // QStyle interface
public:

    //static 函数，供 MyStylrHelp 调用 [用来绘画自增加的控件枚举]
    static void drawPrimitive(const QStyle *style, MyStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w = nullptr);
    static void drawControl(const QStyle *style, MyStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w);
    static QRect subElementRect(const QStyle *style, MyStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget);
    static int pixelMetric(const QStyle *style, MyStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget);

    //新增加的枚举属 MyStyle:: , 之能够在此内敛函数里面调用
    //[主要用来绘画 自定义新增 的控件枚举 --> 实际调用在 下面的 virtual 里面绘画]
    inline void drawPrimitive(MyStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w = nullptr) const;
    inline void drawControl(MyStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const;
    inline QRect subElementRect(MyStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const;
    inline int pixelMetric(MyStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const;

    //这里的快捷方式创建的枚举,都是不带QStyle:: ; 但是快捷方式的定义是带是QStyle:: , 此处声明的地方必须加上 QStyle:: /*后面改写更复杂的得写上MyStyle:: 因添加自定义的枚举*/
    //这里 override 的虚函数，只能够调用旧有的  QStyle:: 的函数
    //[主要用来绘画 Qt 、 自定义新增 的控件枚举]
    virtual void drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual void drawControl(QStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual QRect subElementRect(QStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const override;
    virtual void drawComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *widget) const override;
    virtual QRect subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, SubControl sc, const QWidget *widget) const override;
    virtual int pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const override;
    virtual QSize sizeFromContents(QStyle::ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const override;
    virtual int styleHint(QStyle::StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const override;
    virtual void polish(QWidget *widget) override;
    virtual void unpolish(QWidget *widget) override;

    //重实现,使得父类的多个同名 函数 (不同参数) 任然可以在本类里面使用
    using QCommonStyle::polish;
    using QCommonStyle::unpolish;
    using QCommonStyle::drawPrimitive;
    using QCommonStyle::drawControl;
    using QCommonStyle::subElementRect;
    using QCommonStyle::drawComplexControl;
    using QCommonStyle::subControlRect;
    using QCommonStyle::pixelMetric;
    using QCommonStyle::sizeFromContents;
    using QCommonStyle::styleHint;
};

class MyStyleHelp
{
public:
    inline MyStyleHelp (const QStyle* style = nullptr);

    inline void setStyle(const QStyle* style);

    inline const QStyle* qStyle() const;
    inline const MyStyle* myStyle() const;

    inline void drawPrimitive(MyStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w = nullptr) const;
    inline void drawControl(MyStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const;
    inline QRect subElementRect(MyStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const;
    inline int pixelMetric(MyStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const;

private:
    const QStyle* m_qStyle;
    const MyStyle* m_myStyle;
};

class MyStylePainter : public QPainter
{
public:
    MyStylePainter();
    MyStylePainter(QWidget* w);
    ~MyStylePainter() {}

    void drawPrimitive(MyStyle::PrimitiveElement pe, const QStyleOption *opt);
    void drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt);
    void drawControl(MyStyle::ControlElement element, const QStyleOption *opt);
    void drawControl(QStyle::ControlElement element, const QStyleOption *opt);

private:
    QWidget* m_widget;
    QStyle* m_qStyle;
    MyStyleHelp m_myStyleHelp;
};
#endif // MYSTYLE_H
