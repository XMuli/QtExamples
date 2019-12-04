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
#include "ExTrans.h"
#include "ui_ExTrans.h"

#include <QHostInfo>

ExTrans::ExTrans(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExTrans)
{
    ui->setupUi(this);
    setWindowTitle("Udp通信：unicast(单播) + broadcast(广播)的使用");

    QString hostName = QHostInfo::localHostName();
    QString ip = getLocalIp();
    ui->plainTextEdit->appendPlainText("主机名称：" + hostName + "\n主机IP：" + ip + "\n");

    m_labSocketState = new QLabel("Socket状态：");
    m_labSocketState->setMinimumWidth(200);
    ui->statusBar->addWidget(m_labSocketState);

    ui->comboBoxIp->addItem(getLocalIp());
    m_udpSocket = new QUdpSocket(this);

    connect(m_udpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    onSocketStateChange(m_udpSocket->state());
    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}

ExTrans::~ExTrans()
{
    delete ui;
}
//绑定端口
void ExTrans::on_actBind_triggered()
{
    quint16 port = ui->spinBoxBind->value();   //本机UDP端口
    if (m_udpSocket->bind(port)) {   //端口绑定成功
        ui->plainTextEdit->appendPlainText("端口绑定成功：" + QString::number(m_udpSocket->localPort()));

        ui->actBind->setEnabled(false);
        ui->actDisbind->setEnabled(true);
    } else {
        ui->plainTextEdit->appendPlainText("端口绑定失败");
    }
}

//解除绑定
void ExTrans::on_actDisbind_triggered()
{
    m_udpSocket->abort();  //断开，中止套接字
    ui->plainTextEdit->appendPlainText("端口解除绑定成功");

    ui->actBind->setEnabled(true);
    ui->actDisbind->setEnabled(false);
}

//清除文本信息
void ExTrans::on_actClean_triggered()
{
    ui->plainTextEdit->clear();
}

//关闭程序
void ExTrans::on_actQuit_triggered()
{
    close();
}

//单播消息
void ExTrans::on_btnUnicast_clicked()
{
    QString targetIp = ui->comboBoxIp->currentText();
    QHostAddress targetAddr(targetIp);    //目标 Ip
    quint16 targetPort = ui->spinBoxPort->value();   //目标 port
    QString msg = ui->lineEdit->text();   //发送的消息

    QByteArray str = msg.toUtf8();
    m_udpSocket->writeDatagram(str, targetAddr, targetPort);  //发送数据报

    ui->plainTextEdit->appendPlainText(QString("[Send: ] %1").arg(msg));
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
}

//广播消息
void ExTrans::on_btnBroadcast_clicked()
{
    quint16 targetPort = ui->spinBoxPort->value();   //目标 port
    QString msg = ui->lineEdit->text();   //发送的消息

    QByteArray str = msg.toUtf8();
    m_udpSocket->writeDatagram(str, QHostAddress::Broadcast, targetPort);  //发送 数据报 给所有IP

    ui->plainTextEdit->appendPlainText(QString("[广播: ] %1").arg(msg));
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
}

//socket 状态发生变化
void ExTrans::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
    case QAbstractSocket::UnconnectedState:
        m_labSocketState->setText("socket状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        m_labSocketState->setText("socket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        m_labSocketState->setText("socket状态：ConnectingState");
        break;
    case QAbstractSocket::ConnectedState:
        m_labSocketState->setText("socket状态：ConnectedState");
        break;
    case QAbstractSocket::BoundState:
        m_labSocketState->setText("socket状态：BoundState");
        break;
    case QAbstractSocket::ClosingState:
        m_labSocketState->setText("socket状态：ClosingState");
        break;
    case QAbstractSocket::ListeningState:
        m_labSocketState->setText("socket状态：ListeningState");
        break;
    default:
        m_labSocketState->setText("socket状态：其他未知状态...");
        break;
    }
}

//读取 socket 传入的数据
void ExTrans::onSocketReadyRead()
{
    while (m_udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(m_udpSocket->pendingDatagramSize());

        QHostAddress peerAddr;
        quint16 peerPort;

        m_udpSocket->readDatagram(datagram.data(), datagram.size(), &peerAddr, &peerPort);  //读取数据包，消息+来自的Ip和port
        QString str = datagram.data();
        QString peer = QString("[From: %1  %2] %3").arg(peerAddr.toString()).arg(QString::number(peerPort)).arg(str);
        ui->plainTextEdit->appendPlainText(peer);
    }
}

//获取本机IP
QString ExTrans::getLocalIp()
{
    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QString Ip = "";

    if (hostInfo.addresses().isEmpty())
        return 0;

    foreach (QHostAddress addr, hostInfo.addresses()) {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol) {
            Ip = addr.toString();
            break;
        }
    }

   return Ip;
}
