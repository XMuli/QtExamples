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

#include "widget.h"
#include "mystyle.h"

#include <QDebug>
#include <QTableWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QApplication>
#include <QSlider>
#include <QScrollBar>
#include <QStyleFactory>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    init();
}

Widget::~Widget()
{

}

void Widget::init()
{
    resize(1000, 600);

    QTableWidget *table = new QTableWidget(10, 10, this);
    table->move(10, 10);

    QScrollBar *scrollBarH = new QScrollBar(this);
    scrollBarH->move(300, 50);
    scrollBarH->setRange(0, 100);
    scrollBarH->setValue(34);
    scrollBarH->resize(380, 20);
    scrollBarH->setOrientation(Qt::Horizontal);

    QScrollBar *scrollBarV = new QScrollBar(this);
    scrollBarV->move(50, 250);
    scrollBarV->setRange(0, 100);
    scrollBarV->setValue(67);
    scrollBarV->resize(20, 380);
    scrollBarV->setOrientation(Qt::Vertical);

    QProgressBar* progreH = new QProgressBar(this);
    progreH->move(300, 100);
    progreH->resize(250, 40);
    progreH->setValue(37);
    progreH->setOrientation(Qt::Horizontal);

    QProgressBar* progreV = new QProgressBar(this);
    progreV->move(100, 300);
    progreV->resize(40, 250);
    progreV->setValue(67);
    progreV->setOrientation(Qt::Vertical);

    int i = 0;
    QStringList listStyle = QStyleFactory::keys();

    //显示 and 使用当前系统支持的系统风格
    foreach(QString val, listStyle) {
        qDebug()<<val<<"  ";
        QPushButton *btn = new QPushButton(val, this);
        btn->move(this->rect().right() - 100, this->rect().top() + i++ * 40);
        connect(btn, &QPushButton::clicked, this, [=](){
            qApp->setStyle(val);
        });
    }

    //若是自定义风格， new 为对象即可
    QPushButton *btn = new QPushButton("My Style", this);
    btn->move(this->rect().right() - 100, this->rect().top() + i++ * 40);
    connect(btn, &QPushButton::clicked, this, [=](){
        qApp->setStyle(new MyStyle());
    });

}
