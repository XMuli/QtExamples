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
#ifndef EXTCPSERVER_H
#define EXTCPSERVER_H

#include <QMainWindow>
#include <QLabel>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>

namespace Ui {
class ExTcpServer;
}

class ExTcpServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExTcpServer(QWidget *parent = nullptr);
    ~ExTcpServer();

private:
    QString getLocalIp();      //获取本机 IP

protected:
    void closeEvent(QCloseEvent* event);

private slots:
//UI的槽函数
    void on_actStart_triggered();      //开始监听
    void on_actStop_triggered();       //停止监听
    void on_actClear_triggered();      //清除文本框内容
    void on_actQuit_triggered();       //退出程序
    void on_btnSend_clicked();         //发送消息

//自定义的槽函数
    void onSocketReadyRead();          //读取 socket 传入时候的数据
    void onClientConnected();          //client socket conneted
    void onClientDisonnected();        //client socket disconneted
    void onNewConnection();            //QTcpServer 的 newConnect() 信号
    void onSocketStateChange(QAbstractSocket::SocketState socketState);

private:
    Ui::ExTcpServer *ui;

    QLabel* m_labListen;
    QLabel* m_labSocket;
    QTcpServer* m_tcpServer;
    QTcpSocket* m_tcpSocket;


};

#endif // EXTCPSERVER_H
