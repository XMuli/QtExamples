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

class MyStyle : public QCommonStyle
{
public:
    MyStyle();

    // QStyle interface
public:
    virtual void polish(QWidget *widget) override;
    virtual void unpolish(QWidget *widget) override;
    virtual void drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual void drawControl(ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const override;
    virtual QRect subElementRect(SubElement subElement, const QStyleOption *option, const QWidget *widget) const override;
    virtual void drawComplexControl(ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *widget) const override;
    virtual QRect subControlRect(ComplexControl cc, const QStyleOptionComplex *opt, SubControl sc, const QWidget *widget) const override;
    virtual int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const override;
    virtual QSize sizeFromContents(ContentsType ct, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const override;
    virtual int styleHint(StyleHint stylehint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const override;

};

#endif // MYSTYLE_H
