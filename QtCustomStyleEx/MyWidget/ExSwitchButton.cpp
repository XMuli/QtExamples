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
//#include "qglobal.h"

EXWIDGET_BEGIN_NAMESPACE

//xxxPrivate class 会在 xxx.cpp 里面来实现
/*!
 * \~chinese \brief ExSwitchButtonPrivate 的构造函数
 */
ExSwitchButtonPrivate::ExSwitchButtonPrivate(ExSwitchButton *qq)
{

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

}

ExSwitchButtonPrivate::ExSwitchButton()
{

}

void ExSwitchButton::onChange(bool)
{
    Q_D(ExSwitchButton);

   d->m_checked = (!d->m_checked);

   qDebug()<<"------01-----ExSwitchButton::onChange(bool):"<<d->m_checked;
}





EXWIDGET_END_NAMESPACE
