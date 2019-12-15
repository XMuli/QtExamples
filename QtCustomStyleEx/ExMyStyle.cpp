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
#include "ExMyStyle.h"

#include <QProxyStyle>
#include <QDebug>
#include <QPainter>
#include <QStyleOption>
#include <QLinearGradient>

EXWIDGET_BEGIN_NAMESPACE
ExMyStyle::ExMyStyle()
{

}

void ExMyStyle::drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{

}



void ExMyStyle::polish(QWidget *widget)
{
    QCommonStyle::polish(widget);
}

void ExMyStyle::unpolish(QWidget *widget)
{
    QCommonStyle::unpolish(widget);
}

void ExMyStyle::drawControl(QStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    p->setRenderHint(QPainter::Antialiasing);

    switch (element) {
    case CE_ScrollBarAddPage: {  //增加页(在滑槽)
        p->fillRect(opt->rect, QColor("#bfe9ff"));
        return;
    }
    case CE_ScrollBarSubPage: {  //减少页(在滑槽)
        p->fillRect(opt->rect, QColor("#EC6EAD"));
        return;
    }
    case CE_ScrollBarSlider: {  //滑块
        p->fillRect(opt->rect, QColor("#A8BFFF"));
        return;
    }
    case CE_ScrollBarAddLine: {  //增加按钮
        p->fillRect(opt->rect, QColor("#21d4fd"));
        return;
    }
    case CE_ScrollBarSubLine: {  //减少按钮
        p->fillRect(opt->rect, QColor("#de6161"));
        return;
    }
    default:
        break;
    }

    QCommonStyle::drawControl(element, opt, p, w);
}

void ExMyStyle::drawComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *widget) const
{
    switch (cc) {
//    case CC_:
//        break;
    default:
        break;
    }

    QCommonStyle::drawComplexControl(cc, opt, p, widget);
}

QSize ExMyStyle::sizeFromContents(QStyle::ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const
{
    QSize size = QCommonStyle::sizeFromContents(ct, opt, contentsSize, w);

    switch (ct) {
    case CT_ScrollBar: {
        int widget = size.width();
        int height = size.height();

        if (widget < height)
            size.setHeight(height * 1.2);

        if (widget > height)
            size.setWidth(widget * 1.2);

        qDebug()<<"----01----:"<<size;
        return size;
    }
    default:
        break;
    }

    return size;
}

QRect ExMyStyle::subElementRect(QStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const
{
    switch (subElement) {
//    case SE_:
//        break;
    default:
        break;
    }

    return QCommonStyle::subElementRect(subElement, option, widget);
}

int ExMyStyle::pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    switch (metric) {
//    case PM_:
//        return 36;
    default:
        break;
    }

    return QCommonStyle::pixelMetric(metric, option, widget);
}

int ExMyStyle::styleHint(QStyle::StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const
{
    switch (stylehint) {
//    case SH_:
//        break;
    default:
        break;
    }

    return QCommonStyle::styleHint(stylehint, opt, widget, returnData);
}

EXWIDGET_END_NAMESPACE
