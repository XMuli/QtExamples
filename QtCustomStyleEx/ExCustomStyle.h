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

public:  //重写QCommonStyle重载的函数
    virtual void drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual void drawControl(ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual QRect subElementRect(SubElement subElement, const QStyleOption *option, const QWidget *widget) const override;
    virtual int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const override;
    virtual QSize sizeFromContents(ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const override;
    virtual int styleHint(StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const override;
    virtual QIcon standardIcon(StandardPixmap standardIcon, const QStyleOption *option, const QWidget *widget) const override;

public:
};

CUSTOMSTYLE_END_NAMESPACE

#endif // EXCUSTOMSTYLE_H
