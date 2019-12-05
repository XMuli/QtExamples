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
#ifndef EXSWITCHBUTTON_P_H
#define EXSWITCHBUTTON_P_H

#include "ExMyGlobal.h"
#include <QWidget>

EXWIDGET_BEGIN_NAMESPACE

/*!
 * \~chinese \class ExSwitchButtonPrivate
 * \~chinese \brief ExSwitchButton 类的数据类， 便于实现源码/二进制兼容, 通常继承于 “自定义_Private” 的类
 * \~chinese \sa Qt 自带的 QPushButtonPrivate， QPushButton 实现
 */

class ExSwitchButton;
class ExSwitchButtonPrivate      //自定义控件通常继承于 QObjectPrivate 之类的
{
public:
    ExSwitchButtonPrivate(ExSwitchButton *qq);
    ~ExSwitchButtonPrivate();

    void init();

public:
    bool m_checked;   //switch 是否处于开启状态
};

EXWIDGET_END_NAMESPACE

#endif
