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
#include "ExSwitchButton.h"
#include "ExSwitchButton_p.h"
#include <QDebug>
#include <QPainter>
#include "ExMyStyle.h"

EXWIDGET_BEGIN_NAMESPACE

//xxxPrivate class 会在 xxx.cpp 里面来实现
/*!
 * \~chinese \brief ExSwitchButtonPrivate 的构造函数
 */
ExSwitchButtonPrivate::ExSwitchButtonPrivate(/*ExSwitchButton *qq*/)
{
    init();
}

ExSwitchButtonPrivate::~ExSwitchButtonPrivate()
{

}

void ExSwitchButtonPrivate::init()
{
    m_checked = false;      //xxxxPrivate 自带的变量
    Q_Q(ExSwitchButton);    //Q_Q 可以在 xxxxPrivate 里面调用 xxxx 的方法和变量

    q->setObjectName("ExSwitchButtonPrivate");
    q->setCheckable(true);
    q->connect(q, SIGNAL(toggled(bool)), q, SLOT(onChange(bool)));

    q->onChange(true);
}

ExSwitchButton::ExSwitchButton()
{
    Q_D(ExSwitchButton);
}

ExSwitchButton::~ExSwitchButton()
{

}

void ExSwitchButton::onChange(bool)
{
    Q_D(ExSwitchButton);

   d->m_checked = (!d->m_checked);

   qDebug()<<"------01-----ExSwitchButton::onChange(bool):"<<d->m_checked;
}

void ExSwitchButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QStyleOptionButton opt;
    initStyleOption(&opt);

    ExMyStyle MyStyle;
//    MyStyle.drawControl(ExMyStyle::CE_Sw);


}

void ExSwitchButton::initStyleOption(QStyleOptionButton *option) const
{
    if (!option)
        return;

    option->init(this);      //QStyleOption 对象进行初始化(其中属性很多,整体初始化，然后局部进行参数修改)
    option->initFrom(this);

    if (isChecked()) {
        option->state |= QStyle::State_On;
    } else {
        option->state |= QStyle::State_Off;
    }
}


EXWIDGET_END_NAMESPACE
