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
#ifndef EXTCPCLIENT_H
#define EXTCPCLIENT_H

#include <QMainWindow>
#include <QLabel>
#include <QTcpSocket>
#include <QHostInfo>

namespace Ui {
class ExTcpClient;
}

class ExTcpClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExTcpClient(QWidget *parent = nullptr);
    ~ExTcpClient();

private:
    QString getLocalIp();                  //获取本本机 IP

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    //UI 定义的槽函数
    void on_actConnect_triggered();     //请求连接到服务器
    void on_actDisconnect_triggered();  //断开与服务器的连接
    void on_actClear_triggered();       //清除内容
    void on_actQuit_triggered();        //退出程序
    void on_btnSend_clicked();          //发送文本消息

    //自定义的槽函数
    void onConnected();
    void onDisconnected();
    void onSocketReadyRead();           //从socket读取传入的数据
    void onSocketStateChange(QAbstractSocket::SocketState socketState);

private:
    Ui::ExTcpClient *ui;

    QLabel* m_labSocket;
    QTcpSocket* m_tcpSocket;
};

#endif // EXTCPCLIENT_H
