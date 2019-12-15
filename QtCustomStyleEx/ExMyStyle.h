/*
 * Copyright (C)  2019 ~ 2019 touwoyimuli.  All rights reserved.
 *
 * Author:  touwoyimuli <touwoyimuli@gmai.com>
 *
 * github:  https://github.com/touwoyimuli
 * blogs:   https://touwoyimuli.github.io/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://touwoyimuli.github.io/>.
 */
#ifndef EXMYSTYLE_H
#define EXMYSTYLE_H

#include "ExMyGlobal.h"

#include "qglobal.h"
#include <QCommonStyle>

QT_BEGIN_NAMESPACE
//class QCommonStyle;
QT_END_NAMESPACE

EXWIDGET_BEGIN_NAMESPACE
class ExMyStyle : public QCommonStyle
{
//    Q_OBJECT

public:
    ExMyStyle();

//    enum ControlElement {
//        CE_SwitchButton = QStyle::CE_CustomBase + 1,
//        CE_CustomBase = QStyle::CE_CustomBase + 0xf00000
//    };

public:
//    enum PrimitiveElement {
//        PE_ItemBackground = QStyle::PE_CustomBase + 1,          //列表项的背景色
//        PE_SwitchButtonGroove,
//        PE_SwitchButtonHandle,
//        PE_CustomBase = QStyle::PE_CustomBase + 0xf00000
//    };

//    enum ControlElement {
//        CE_IconButton = QStyle::CE_CustomBase + 1,
//        CE_SwitchButton,
//        CE_CustomBase = QStyle::CE_CustomBase + 0xf00000
//    };

//    enum SubElement {
//        SE_IconButtonIcon = QStyle::SE_CustomBase + 1,
//        SE_SwitchButtonGroove,
//        SE_SwitchButtonHandle,
//        SE_CustomBase = QStyle::SE_CustomBase + 0xf00000
//    };

//    enum PixelMetric {
//        PM_FocusBorderWidth = QStyle::PM_CustomBase + 1,        //控件焦点状态的边框宽度
//        PM_FrameRadius,
//        PM_CustomBase = QStyle::PM_CustomBase + 0xf00000
//    };

//    enum ContentsType {
//        CT_IconButton = QStyle::CT_CustomBase + 1,
//        CT_SwitchButton,
//        CT_CustomBase = QStyle::CT_CustomBase + 0xf00000
//    };

//    enum StyleHint {
//        SH_CustomBase = QStyle::SH_CustomBase + 0xf00000
//    };

//    enum StandardPixmap {
//        SP_CustomBase = QStyle::SP_CustomBase + 0xf00000
//    };

//    /*枚举通过按位 ~ ^ | !来计算得到需要组合
//     * //0b对应的二进制        0x十六进制    对应的十进制
//     *   0b0000 0001       0x0000 0001       1
//     *   0b0000 0010       0x0000 0002       2
//     *   0b0000 0100       0x0000 0004       4
//     *   0b0000 1000       0x0000 0006       8
//     *   0b0001 0000       0x0000 0010      16
//    */

//    enum StyleState {
//        SS_NormalState = 0x00000000,
//        SS_HoverState  = 0x00000001,
//        SS_PressState  = 0x00000002,
//    };
//    Q_DECLARE_FLAGS(StateFlags, StyleState)  //而类型定义(typedef)和操作符重载正是宏Q_DECLARE_FLAGS 和 Q_DECLARE_OPERATORS_FOR_FLAGS  (均无关于元对象系统)

    //静态static函数
//    static void drawPrimitive(const QStyle *style, ExCustomStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w);
//    static void drawControl(const QStyle *style, ExCustomStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w);
//    static int pixelMetric(const QStyle *style, QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget);
//    static QRect subElementRect(const QStyle *style, ExCustomStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget);
//    static QSize sizeFromContents(const QStyle *style, ExCustomStyle::ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w);
//    static QIcon standardIcon(const QStyle *style, ExCustomStyle::StandardPixmap standardIcon, const QStyleOption *option, const QWidget *widget);


    //内联inline函数,然后[自动选择]是调用静态函数,还是重写的基类的函数
    inline void drawPrimitive(ExMyStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const;
//    inline void drawControl(ExCustomStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const;
//    inline QRect subElementRect(ExCustomStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const;
//    inline int pixelMetric(ExCustomStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const;
//    inline QSize sizeFromContents(ExCustomStyle::ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const;
//    inline int styleHint(ExCustomStyle::StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const;

//    inline void drawComplexControl(ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *widget) const;     //这三个不用写成内联函数,且会编译不通过
//    inline QRect subControlRect(ComplexControl cc, const QStyleOptionComplex *opt, SubControl sc, const QWidget *widget) const;
//    inline QStyle::SubControl hitTestComplexControl(ComplexControl cc, const QStyleOptionComplex *opt, const QPoint &pt, const QWidget *widget) const;
//    virtual void polish(QPalette &palette) override;        //通常在此函数内指定配色方案，也即配置调色板
//    virtual void polish(QWidget *widget) override;          //当样式应用到窗口部件时，polish(QWidget*)就会调用,从而允许我们进行最后的定制
//    virtual void unpolish(QWidget *widget) override;        //当动态改变样式的时候，unpolish就会调用，来撤销polish的影响。polish(QWidget*)一般用做窗口部件的事件过滤器。

    // QStyle interface    重写QCommonStyle重载的函数
public:
    virtual void polish(QWidget *widget) override;
    virtual void unpolish(QWidget *widget) override;
    virtual void drawControl(ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual void drawComplexControl(ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *widget) const override;
    virtual QSize sizeFromContents(ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const override;
    virtual QRect subElementRect(SubElement subElement, const QStyleOption *option, const QWidget *widget) const override;
    virtual int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const override;
    virtual int styleHint(StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const override;


    //重实现,使得父类的多个同名 函数 (不同参数) 任然可以在本类里面使用
    using QCommonStyle::drawPrimitive;
    using QCommonStyle::drawControl;
    using QCommonStyle::subElementRect;
    using QCommonStyle::pixelMetric;
    using QCommonStyle::sizeFromContents;
    using QCommonStyle::styleHint;
    using QCommonStyle::standardIcon;

public:
};
EXWIDGET_END_NAMESPACE

#endif // EXMYSTYLE_H
