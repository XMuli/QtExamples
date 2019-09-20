#ifndef EXCUSTOMSTYLE_H
#define EXCUSTOMSTYLE_H

//Qt自带的库
#include <QCommonStyle>
#include <QPainter>
#include <QStyleOption>

//自定义的文件或库
#include "ExDefineGlobal.h"

CUSTOMSTYLE_BEDGIN_NAMESPACE

//一些工具函数:绘画圈,叉,对号,阴影等功能函数
CUSTOM_BEGIN_NAMESPACE
CUSTOMSTYLE_END_NAMESPACE

class ExCustomStyle : public QCommonStyle
{
    Q_OBJECT

public:
    ExCustomStyle();

public:
    enum PrimitiveElement {
        PE_ItemBackground = QStyle::PE_CustomBase + 1,          //列表项的背景色
        PE_SwitchButtonGroove,
        PE_SwitchButtonHandle,
        PE_CustomBase = QStyle::PE_CustomBase + 0xf00000
    };

    enum ControlElement {
        CE_IconButton = QStyle::CE_CustomBase + 1,
        CE_SwitchButton,
        CE_CustomBase = QStyle::CE_CustomBase + 0xf00000
    };

    enum SubElement {
        SE_IconButtonIcon = QStyle::SE_CustomBase + 1,
        SE_SwitchButtonGroove,
        SE_SwitchButtonHandle,
        SE_CustomBase = QStyle::SE_CustomBase + 0xf00000
    };

    enum PixelMetric {
        PM_FocusBorderWidth = QStyle::PM_CustomBase + 1,        //控件焦点状态的边框宽度
        PM_FrameRadius,
        PM_CustomBase = QStyle::PM_CustomBase + 0xf00000
    };

    enum ContentsType {
        CT_IconButton = QStyle::CT_CustomBase + 1,
        CT_SwitchButton,
        CT_CustomBase = QStyle::CT_CustomBase + 0xf00000
    };

    enum StyleHint {
        SH_CustomBase = QStyle::SH_CustomBase + 0xf00000
    };

    enum StandardPixmap {
        SP_CustomBase = QStyle::SP_CustomBase + 0xf00000
    };

    /*枚举通过按位 ~ ^ | !来计算得到需要组合
     * //0b对应的二进制        0x十六进制    对应的十进制
     *   0b0000 0001       0x0000 0001       1
     *   0b0000 0010       0x0000 0002       2
     *   0b0000 0100       0x0000 0004       4
     *   0b0000 1000       0x0000 0006       8
     *   0b0001 0000       0x0000 0010      16
    */

    enum StyleState {
        SS_NormalState = 0x00000000,
        SS_HoverState  = 0x00000001,
        SS_PressState  = 0x00000002,
    };
    Q_DECLARE_FLAGS(StateFlags, StyleState)  //而类型定义(typedef)和操作符重载正是宏Q_DECLARE_FLAGS 和 Q_DECLARE_OPERATORS_FOR_FLAGS  (均无关于元对象系统)


    //内联函数,然后自己选择是调用静态函数,还是重写的基类的函数
    inline void drawPrimitive(ExCustomStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
    { proxy()->drawPrimitive(static_cast<QStyle::PrimitiveElement>(pe), opt, p, w); }



    //重写QCommonStyle重载的函数
    virtual void drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual void drawControl(QStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual QRect subElementRect(QStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const override;
    virtual int pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const override;
    virtual QSize sizeFromContents(QStyle::ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const override;
    virtual int styleHint(QStyle::StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const override;
    virtual QIcon standardIcon(QStyle::StandardPixmap standardIcon, const QStyleOption *option, const QWidget *widget) const override;

//    virtual void polish(QPalette &palette) override;        //通常在此函数内指定配色方案，也即配置调色板
//    virtual void polish(QWidget *widget) override;          //当样式应用到窗口部件时，polish(QWidget*)就会调用,从而允许我们进行最后的定制
//    virtual void unpolish(QWidget *widget) override;        //当动态改变样式的时候，unpolish就会调用，来撤销polish的影响。polish(QWidget*)一般用做窗口部件的事件过滤器。
};

CUSTOMSTYLE_END_NAMESPACE

#endif // EXCUSTOMSTYLE_H
