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
#include "ExMulticast.h"
#include "ui_ExMulticast.h"

ExMulticast::ExMulticast(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExMulticast)
{
    ui->setupUi(this);
    setWindowTitle("Udp通信：multicate(组播)的使用");

    QString hostName = QHostInfo::localHostName();
    QString ip = getLocalIp();
    ui->plainTextEdit->appendPlainText("主机名称：" + hostName + "\n主机IP：" + ip + "\n");

    m_labSocketState = new QLabel("Socket状态：");
    m_labSocketState->setMinimumWidth(200);
    ui->statusBar->addWidget(m_labSocketState);

    ui->comboBoxIp->addItem(getLocalIp());
    m_udpSocket = new QUdpSocket(this);     //用于通讯使用的 Socket
    //Multicast路由层次，1表示只在同一局域网内
    //组播TTL: 生存时间，每跨1个路由会减1，多播无法跨过大多数路由所以为1
    //默认值是1，表示数据包只能在本地的子网中传送。
    m_udpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption, 1);



    connect(m_udpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    onSocketStateChange(m_udpSocket->state());
    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}

ExMulticast::~ExMulticast()
{
    delete ui;
}

void ExMulticast::on_actStart_triggered()
{
    QString ip = ui->comboBoxIp->currentText();
    m_groupAddress = QHostAddress(ip);
    quint16 port = ui->spinBoxBind->value();

    if (m_udpSocket->bind(QHostAddress::AnyIPv4, port, QUdpSocket::ShareAddress)) {  //绑定端口
        m_udpSocket->joinMulticastGroup(m_groupAddress);  //加入多播组

        ui->plainTextEdit->appendPlainText("[用户：" + getLocalIp() +"]  加入组播(组播地址：" + ip + " 端口：" + QString::number(port) + ")成功");
        ui->actStart->setEnabled(false);
        ui->actStop->setEnabled(true);
    } else {
        ui->plainTextEdit->appendPlainText("[用户：" + getLocalIp() +"]  加入组播(组播地址：" + ip + " 端口：" + QString::number(port) + ")失败");
    }
}

void ExMulticast::on_actStop_triggered()
{
    m_udpSocket->leaveMulticastGroup(m_groupAddress);  //退出组播
    m_udpSocket->abort();       //解除绑定
    ui->plainTextEdit->appendPlainText("[用户：" + getLocalIp() +"]  退出组播成功");
    ui->actStart->setEnabled(true);
    ui->actStop->setEnabled(false);
}

void ExMulticast::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

void ExMulticast::on_actQuit_triggered()
{
    close();
}

void ExMulticast::onSocketStateChange(QAbstractSocket::SocketState socketState)
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

void ExMulticast::onSocketReadyRead()
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

QString ExMulticast::getLocalIp()
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

void ExMulticast::on_btnSend_clicked()
{
    quint16 port = ui->spinBoxBind->value();
    QString  msg = ui->lineEdit->text();
    QByteArray  datagram = msg.toUtf8();

    m_udpSocket->writeDatagram(datagram, m_groupAddress, port);
//    m_udpSocket->writeDatagram(datagram.data(), datagram.size(), m_groupAddress, port);
    ui->plainTextEdit->appendPlainText("[multicst] " + msg);
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
}
