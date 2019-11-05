#include "ExCustomStyle.h"

CUSTOMSTYLE_BEDGIN_NAMESPACE

ExCustomStyle::ExCustomStyle()
{
}

//静态static的函数+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExCustomStyle::drawPrimitive(const QStyle *style, ExCustomStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w)
{
//    DStyleHelper dstyle(style);
    switch (pe) {
//    case value:
//        break;
    default:
        break;
    }
}

void ExCustomStyle::drawControl(const QStyle *style, ExCustomStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w)
{
    switch (element) {
//    case CE_IconButton:
//        break;
    default:
        break;
    }
}

int ExCustomStyle::pixelMetric(const QStyle *style, QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget)
{
    //全部都是return 一个数值
    //    DStyleHelper dstyle(style);
    switch (metric) {
    case PM_FrameRadius:

        return 8;
    default:
        return -1;
    }
}

QRect ExCustomStyle::subElementRect(const QStyle *style, ExCustomStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget)
{
    switch (subElement) {
//    case SE_SwitchButtonGroove: {
//        return option->rect;
//    }
    default:
        return QRect(-1, -1, -1, -1);
    }
}

QSize ExCustomStyle::sizeFromContents(const QStyle *style, ExCustomStyle::ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w)
{
    switch (ct) {
//    case CT_ButtonBoxButton: {
//        QSize size(100, 100);
//        return size;
//    }
    default:
        return contentsSize;
    }
}

QIcon ExCustomStyle::standardIcon(const QStyle *style, ExCustomStyle::StandardPixmap standardIcon, const QStyleOption *option, const QWidget *widget)
{
    //使用宏, 来表示方便和快捷
    #define CASE_ICON(Value) \
        case SP_##Value: { \
            DStyledIconEngine *icon_engine = new DStyledIconEngine(DDrawUtils::draw##Value, QStringLiteral(#Value)); \
            return QIcon(icon_engine); }

    switch (standardIcon) {
//    CASE_ICON(ForkElement)
//    CASE_ICON(DecreaseElement)
//    CASE_ICON(IncreaseElement)
//    CASE_ICON(MarkElement)
//    case SP_EditElement:
//        return QIcon::fromTheme("edit");
//    case SP_MediaVolumeLowElement:
//        return QIcon::fromTheme("volume_low");
    default:
        return QIcon();
    }
}

//内联inline的函数+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//实际上,只需要在实现处添加inline,声明出不需要写inline
inline void ExCustomStyle::drawPrimitive(ExCustomStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    proxy()->drawPrimitive(static_cast<QStyle::PrimitiveElement>(pe), opt, p, w);
}

inline void ExCustomStyle::drawControl(ExCustomStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
  proxy()->drawControl(static_cast<QStyle::ControlElement>(element), opt, p, w);
}

inline QRect ExCustomStyle::subElementRect(ExCustomStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const
{
    proxy()->subElementRect(static_cast<QStyle::SubElement>(subElement), option, widget);
}

inline int ExCustomStyle::pixelMetric(ExCustomStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    proxy()->pixelMetric(static_cast<QStyle::PixelMetric>(metric), option, widget);
}

inline QSize ExCustomStyle::sizeFromContents(ExCustomStyle::ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const
{
    proxy()->sizeFromContents(static_cast<QStyle::ContentsType>(ct), opt, contentsSize, w);
}

inline int ExCustomStyle::styleHint(ExCustomStyle::StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const
{
    proxy()->styleHint(static_cast<QStyle::StyleHint>(stylehint), opt, widget, returnData);
}

inline QIcon ExCustomStyle::standardIcon(ExCustomStyle::StandardPixmap standardIcon, const QStyleOption *option, const QWidget *widget) const
{
    proxy()->standardIcon(static_cast<QStyle::StandardPixmap>(standardIcon), option, widget);
}

//重写重载的函数====================================================================================================
void ExCustomStyle::drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    QCommonStyle::drawPrimitive(pe, opt, p, w);
}

void ExCustomStyle::drawControl(QStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
//    if (Q_UNLIKELY(element < QStyle::CE_CustomBase)) {
//        return QCommonStyle::drawControl(element, opt, p, w);
//    }

//    drawControl(this, static_cast<ControlElement>(element), opt, p, w);

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

void ExCustomStyle::drawComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *widget) const
{
    return QCommonStyle::drawComplexControl(cc, opt, p, widget);
}

QRect ExCustomStyle::subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, SubControl sc, const QWidget *widget) const
{
    return QCommonStyle::subControlRect(cc, opt, sc, widget);
}

QStyle::SubControl ExCustomStyle::hitTestComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, const QPoint &pt, const QWidget *widget) const
{
    return QCommonStyle::hitTestComplexControl(cc, opt, pt, widget);
}

//END+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

CUSTOMSTYLE_END_NAMESPACE
