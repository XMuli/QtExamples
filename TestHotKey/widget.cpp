/*
 * Copyright (C)  2019~2022  偕臧  All rights reserved.
 *
 * Author:  XMuli  xmulitech@gmail.com
 *
 * GitHub:  https://github.com/XMuli
 * Blog:    https://ifmet.cn
 * CSDN:    https://blog.csdn.net/qq_33154343
 */
#include "widget.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QRect>
#include <QDebug>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);

    QDesktopWidget *desktop = QApplication::desktop();  // 获取桌面的窗体对象
    const QRect geom = desktop->geometry();             // 多屏的矩形取并集
    setWindowFlags(Qt::FramelessWindowHint /*| Qt::WindowStaysOnTopHint */| windowFlags()); // 去掉标题栏 + 置顶

//    setAttribute(Qt::WA_ShowWithoutActivating,true);
//    setFocusPolicy(Qt::StrongFocus);
//    setFixedSize(QSize(geom.size().width() / 4, geom.size().height()));
    setFixedSize(QSize(512, geom.size().height()));
    setMouseTracking(true);
}

Widget &Widget::instance()
{
    static Widget m_instance;
    return m_instance;
}

void Widget::getScrnShots()
{
//    QWidget::setFocus();
    show();
}

Widget::~Widget()
{
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        qDebug() << "Key_Escape";
        hide();
        //close();   // 销毁会有问题,已经排查：1. tray 有关，改用 qpushbutton 和 close即可； 2.单例有关，该市建议修改为 new 指针的比较合适
    } else if (event->key() == Qt::Key_A) {
        qDebug() << "Key_A";
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    m_pos = event->globalPos();

    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter pa(this);
    pa.drawText(100, 200, QString("m_pos(%1, %2)").arg(m_pos.x()).arg(m_pos.y()));
}

