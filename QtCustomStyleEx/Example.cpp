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
#include "Example.h"

#include <QStyleFactory>
#include <QDebug>
#include <QTableWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QApplication>
#include <QSlider>
#include <QScrollBar>

#include "MyWidget/ExSwitchButton.h"

EXWIDGET_USE_NAMESPACE

Example::Example(QWidget *parent)
    : QWidget(parent)
{

}

Example::~Example()
{

}

void Example::init()
{
    QTableWidget *table = new QTableWidget(10, 10, this);
    QScrollBar *scrollBarH = new QScrollBar(this);
    QScrollBar *scrollBarV = new QScrollBar(this);

    table->move(10, 10);

    scrollBarH->move(300, 50);
    scrollBarH->setRange(0, 100);
    scrollBarH->setValue(34);
    scrollBarH->resize(380, 20);
    scrollBarH->setOrientation(Qt::Horizontal);

    scrollBarV->move(50, 250);
    scrollBarV->setRange(0, 100);
    scrollBarV->setValue(67);
    scrollBarV->resize(20, 380);
    scrollBarV->setOrientation(Qt::Vertical);

    int i = 0;
    QStringList listStyle = QStyleFactory::keys();
    foreach(QString val, listStyle) {   //打印当前系统支持的系统风格
        QPushButton *btn = new QPushButton(val, this);
        btn->move(this->rect().right() - 100, this->rect().top() + i++ * 40);
        connect(btn, &QPushButton::clicked, this, [=](){
            qApp->setStyle(val);
        });
    }

    QPushButton *btn = new QPushButton("ExMyStyle", this);
    btn->move(this->rect().right() - 100, this->rect().top() + i++ * 40);
    connect(btn, &QPushButton::clicked, this, [=](){
        qApp->setStyle(new ExMyStyle());
    });
}
