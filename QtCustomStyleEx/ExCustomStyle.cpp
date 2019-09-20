#include "ExCustomStyle.h"

CUSTOMSTYLE_BEDGIN_NAMESPACE

ExCustomStyle::ExCustomStyle()
{
}


//重写重载的函数+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExCustomStyle::drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    QCommonStyle::drawPrimitive(pe, opt, p, w);
}

void ExCustomStyle::drawControl(QStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
        switch (element) {
        //滚动条-------------------------------------
        case CE_ScrollBarAddPage: {  //增加页(在滑槽)
            p->fillRect(opt->rect, Qt::green);
            break;
        }
        case CE_ScrollBarSubPage: {  //减少页(在滑槽)
            p->fillRect(opt->rect, Qt::gray);
            break;
        }
        case CE_ScrollBarSlider: {  //滑块
            p->fillRect(opt->rect, Qt::red);
//            p->setBrush();
            break;
        }
        case CE_ScrollBarAddLine: {  //增加按钮
            p->fillRect(opt->rect, Qt::blue);
            break;
        }
        case CE_ScrollBarSubLine: {  //减少按钮
            p->fillRect(opt->rect, Qt::magenta);
            break;
        }
//        case CE_ScrollBarFirst:
//        case CE_ScrollBarLast: break; //未知
        //END+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        default:
            break;
        }

    QCommonStyle::drawControl(element, opt, p, w);
}

QRect ExCustomStyle::subElementRect(QStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const
{
    return QCommonStyle::subElementRect(subElement, option, widget);
}

int ExCustomStyle::pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    return QCommonStyle::pixelMetric(metric, option, widget);
}

QSize ExCustomStyle::sizeFromContents(QStyle::ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const
{
    return QCommonStyle::sizeFromContents(ct, opt, contentsSize, w);
}

int ExCustomStyle::styleHint(QStyle::StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const
{
    return QCommonStyle::styleHint(stylehint, opt, widget, returnData);
}

QIcon ExCustomStyle::standardIcon(QStyle::StandardPixmap standardIcon, const QStyleOption *option, const QWidget *widget) const
{
    return QCommonStyle::standardIcon(standardIcon, option, widget);
}

//END+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

CUSTOMSTYLE_END_NAMESPACE
