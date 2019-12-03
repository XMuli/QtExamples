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
public:
    ExMyStyle();

    // QStyle interface
public:
    virtual void polish(QWidget *widget) override;
    virtual void unpolish(QWidget *widget) override;
    virtual void drawControl(ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual void drawComplexControl(ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *widget) const override;
    virtual QSize sizeFromContents(ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const override;
    virtual QRect subElementRect(SubElement subElement, const QStyleOption *option, const QWidget *widget) const override;
    virtual int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const override;
    virtual int styleHint(StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const override;

public:
};
EXWIDGET_END_NAMESPACE

#endif // EXMYSTYLE_H
