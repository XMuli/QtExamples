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
#ifndef EXTRANS_H
#define EXTRANS_H

#include <QMainWindow>
#include <QLabel>
#include <QUdpSocket>
#include <QString>

namespace Ui {
class ExTrans;
}

/*!
 * \class ExTrans 一个UDP的Deam测试，同时测试单播和广播
 * \brief 因为是在同一台电脑测试，所以IP相同，需要绑定两个不同端口的，这样不会冲突；
 * 若是两台电脑进行测试，那么可以约定使用相同的端口号，使用不同的IP；来进行通讯
 */

class ExTrans : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExTrans(QWidget *parent = nullptr);
    ~ExTrans();

private slots:
    void on_actBind_triggered();     //绑定端口
    void on_actDisbind_triggered();  //解除绑定
    void on_actClean_triggered();    //清除文本信息
    void on_actQuit_triggered();     //关闭程序
    void on_btnUnicast_clicked();    //单播消息
    void on_btnBroadcast_clicked();  //广播消息

    void onSocketStateChange(QAbstractSocket::SocketState socketState);  //socket 状态发生变化
    void onSocketReadyRead();        //读取 socket 传入的数据

private:
    QString getLocalIp();            //获取本机IP

private:
    Ui::ExTrans *ui;

    QLabel* m_labSocketState;
    QUdpSocket* m_udpSocket;
};

#endif // EXTRANS_H
