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
#ifndef EXMULTICAST_H
#define EXMULTICAST_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QLabel>
#include <QHostInfo>
#include <QHostAddress>

namespace Ui {
class ExMulticast;
}

class ExMulticast : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExMulticast(QWidget *parent = nullptr);
    ~ExMulticast();

private slots:
    void on_actStart_triggered();
    void on_actStop_triggered();
    void on_actClear_triggered();
    void on_actQuit_triggered();

    void onSocketStateChange(QAbstractSocket::SocketState socketState);  //socket 状态发生变化
    void onSocketReadyRead();        //读取 socket 传入的数据
    void on_btnSend_clicked();

private:
    QString getLocalIp();            //获取本机IP

private:
    Ui::ExMulticast *ui;

    QUdpSocket* m_udpSocket;      //用于通讯的 socket
    QLabel* m_labSocketState;
    QHostAddress m_groupAddress;  //组播地址
};

#endif // EXMULTICAST_H
