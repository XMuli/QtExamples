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

#include "mystyle.h"

#include <QDebug>

MyStyle::MyStyle()
{

}

void MyStyle::polish(QWidget *widget)
{
    QCommonStyle::polish(widget);
}

void MyStyle::unpolish(QWidget *widget)
{
    QCommonStyle::unpolish(widget);
}

void MyStyle::drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    QCommonStyle::drawPrimitive(pe, opt, p, w);
}

void MyStyle::drawControl(QStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    return QCommonStyle::drawControl(element, opt, p, w);
}

QRect MyStyle::subElementRect(QStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const
{
    return QCommonStyle::subElementRect(subElement, option, widget);
}

void MyStyle::drawComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *widget) const
{
    QCommonStyle::drawComplexControl(cc, opt, p, widget);
}

QRect MyStyle::subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex *opt, QStyle::SubControl sc, const QWidget *widget) const
{
    return QCommonStyle::subControlRect(cc, opt, sc, widget);
}

int MyStyle::pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    return QCommonStyle::pixelMetric(metric, option, widget);
}

QSize MyStyle::sizeFromContents(QStyle::ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const
{
    return QCommonStyle::sizeFromContents(ct, opt, contentsSize, w);
}

int MyStyle::styleHint(QStyle::StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const
{
    return QCommonStyle::styleHint(stylehint, opt, widget, returnData);
}




