/*
 * Copyright (C)  2019~2022  偕臧  All rights reserved.
 *
 * Author:  XMuli  xmulitech@gmail.com
 *
 * GitHub:  https://github.com/XMuli
 * Blog:    https://ifmet.cn
 * CSDN:    https://blog.csdn.net/qq_33154343
 */
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    static Widget& instance();
    void getScrnShots();
    ~Widget();

private:
    Widget(QWidget *parent = nullptr);

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

private:
    QPoint m_pos;
};
#endif // WIDGET_H
