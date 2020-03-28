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

#include <QPainter>
#include <QStyleOption>

MyStyle::MyStyle()
{

}

//******************************************************************
void MyStyle::drawPrimitive(const QStyle *style, MyStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w)
{

}

void MyStyle::drawControl(const QStyle *style, MyStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w)
{
}

QRect MyStyle::subElementRect(const QStyle *style, MyStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget)
{
    return QRect();
}

int MyStyle::pixelMetric(const QStyle *style, MyStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget)
{
    return 0;
}

//******************************************************************
void MyStyle::drawPrimitive(MyStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    proxy()->drawPrimitive(static_cast<QStyle::PrimitiveElement>(pe), opt, p, w);
}

void MyStyle::drawControl(MyStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    proxy()->drawControl(static_cast<QStyle::ControlElement>(element), opt, p, w);
}

QRect MyStyle::subElementRect(MyStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const
{
    return proxy()->subElementRect(static_cast<QStyle::SubElement>(subElement), option, widget);
}

int MyStyle::pixelMetric(MyStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    return proxy()->pixelMetric(static_cast<QStyle::PixelMetric>(metric), option, widget);
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
    switch (pe) {
    case PE_SwitchButtonGroove: {
        if (const QStyleOptionButton* switchBtn = qstyleoption_cast<const QStyleOptionButton*>(opt)) {
            p->setPen(Qt::NoPen);
            if (switchBtn->state & State_On)
                p->setBrush(QColor("#77d472"));

            if (switchBtn->state & State_Off) {
                p->setPen(QPen(QColor("#e5e5e5"), 2));
                p->setBrush(QColor("#fdfefd"));
            }

            p->drawRoundedRect(switchBtn->rect.adjusted(1, 1, -1, -1), switchBtn->rect.height() / 2.0, switchBtn->rect.height() / 2.0);
        }
    }
        break;
    case PE_SwitchButtonHandle: {
        if (const QStyleOptionButton* switchBtn = qstyleoption_cast<const QStyleOptionButton*>(opt)) {
            p->setPen(Qt::NoPen);
            if (switchBtn->state & State_On)
                p->setBrush(QColor("#fefffe"));

            if (switchBtn->state & State_Off)
                p->setPen(QPen(QColor("#e5e5e5"), 2));

            QRect rectHandle = switchBtn->rect.adjusted(1, 1, -1, -1);
            int r = qMin(rectHandle.width() / 2.0, rectHandle.height() / 2.0);
            p->drawEllipse(rectHandle.center(), r, r);
        }
    }
        break;
    default:
        break;
    }

    QCommonStyle::drawPrimitive(pe, opt, p, w);

    //后续分离开为模块的判断
//    if (Q_UNLIKELY(pe < QStyle::PE_CustomBase))
//    else
//        drawPrimitive(this, static_cast<MyStyle::PrimitiveElement>(pe), opt, p, w);
}

void MyStyle::drawControl(QStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    p->setRenderHint(QPainter::Antialiasing);

    switch (element) {
    case CE_ScrollBarAddPage: {  //增加滑槽
        p->fillRect(opt->rect, QColor("#bfe9ff"));
        return;
    }
    case CE_ScrollBarSubPage: {  //减少滑槽
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
    case CE_SwitchButton: {
        if (const QStyleOptionButton *switchBtn = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            QStyleOptionButton option = *switchBtn;
            option.palette = switchBtn->palette;

            option.rect = subElementRect(SE_SwitchButtonGroove, opt, w);
            drawPrimitive(PE_SwitchButtonGroove, &option, p, w);

            option.rect = subElementRect(SE_SwitchButtonHandle, opt, w);
            drawPrimitive(PE_SwitchButtonHandle, &option, p, w);
        }
        break;
    }
    default:
        break;
    }

    return QCommonStyle::drawControl(element, opt, p, w);
}

QRect MyStyle::subElementRect(QStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const
{
    switch (subElement) {
    case SE_SwitchButtonGroove: {
        if (const QStyleOptionButton* switchBtn = qstyleoption_cast<const QStyleOptionButton*>(option))
            return switchBtn->rect;
    }
        break;
    case SE_SwitchButtonHandle: {
        if (const QStyleOptionButton* switchBtn = qstyleoption_cast<const QStyleOptionButton*>(option)) {
            int handleWidth = pixelMetric(PM_SwitchButtonHandleWidth, option, widget);
            QRect rectHandle(0, 0, 0, 0);
            rectHandle.setHeight(switchBtn->rect.height());

            if (switchBtn->rect.width() / 2.0 <= handleWidth)
                rectHandle.setWidth(switchBtn->rect.width() / 2.0);
            else
                rectHandle.setWidth(handleWidth);

            if (switchBtn->state & QStyle::State_Off)
                rectHandle.moveLeft(switchBtn->rect.left() + 5);
            if (switchBtn->state & QStyle::State_On)
                rectHandle.moveRight(switchBtn->rect.right() - 5);

            return rectHandle;
        }
    }
        break;
    default:
        break;
    }

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
    switch (metric) {
    case PM_SwitchButtonHandleWidth:
        return 30;
    case PM_SwithcButtonHandleHeight:
        return 12;
    default:
        break;
    }

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

//******************************************************************
MyStyleHelp::MyStyleHelp(const QStyle* style)
{
    setStyle(style);
}

void MyStyleHelp::setStyle(const QStyle* style)
{
    m_qStyle = style;
    m_myStyle = qobject_cast<const MyStyle *>(style);
}

const QStyle *MyStyleHelp::qStyle() const
{
    return m_qStyle;
}

const MyStyle *MyStyleHelp::myStyle() const
{
    return m_myStyle;
}

void MyStyleHelp::drawPrimitive(MyStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    m_myStyle ? m_myStyle->drawPrimitive(pe, opt, p, w)
              : MyStyle::drawPrimitive(m_qStyle, pe, opt, p, w);
}

void MyStyleHelp::drawControl(MyStyle::ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    m_myStyle ? m_myStyle->drawControl(element, opt, p, w)
              : MyStyle::drawControl(m_qStyle, element, opt, p, w);
}

QRect MyStyleHelp::subElementRect(MyStyle::SubElement subElement, const QStyleOption *option, const QWidget *widget) const
{
    return m_myStyle ? m_myStyle->subElementRect(subElement, option, widget)
                     : MyStyle::subElementRect(m_qStyle, subElement, option, widget);
}

int MyStyleHelp::pixelMetric(MyStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    return m_myStyle ? m_myStyle->pixelMetric(metric, option, widget)
                     : MyStyle::pixelMetric(m_qStyle, metric, option, widget);
}

//******************************************************************
void MyStylePainter::drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt)
{
    m_qStyle->drawPrimitive(pe, opt, this, m_widget);
}

MyStylePainter::MyStylePainter()
    : QPainter()
{
    m_widget = nullptr;
    m_myStyleHelp = nullptr;
}

MyStylePainter::MyStylePainter(QWidget* w)
{
    m_widget = w;
    m_qStyle = w->style();
    m_myStyleHelp.setStyle(m_qStyle);
    QPainter::begin(w); //是调用父类的 begin(), 调试半天才发现
}

void MyStylePainter::drawPrimitive(MyStyle::PrimitiveElement pe, const QStyleOption *opt)
{
    m_myStyleHelp.drawPrimitive(pe, opt, this, m_widget);
}

void MyStylePainter::drawControl(QStyle::ControlElement element, const QStyleOption *opt)
{
    m_qStyle->drawControl(element, opt, this, m_widget);
}

void MyStylePainter::drawControl(MyStyle::ControlElement element, const QStyleOption *opt)
{
    m_myStyleHelp.drawControl(element, opt, this, m_widget);
}
