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
#include "ExTcpServer.h"
#include "ui_ExTcpServer.h"

ExTcpServer::ExTcpServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExTcpServer)
{
    ui->setupUi(this);

    m_labListen = new QLabel("监听状态：");
    m_labSocket = new QLabel("socket状态：");
    m_labListen->setMidLineWidth(200);
    m_labSocket->setMinimumWidth(200);
    ui->statusBar->addWidget(m_labListen);
    ui->statusBar->addWidget(m_labSocket);

    QString localeIp = getLocalIp();
    setWindowTitle(windowTitle() + "---IP地址：" + localeIp);
    ui->comboBox->addItem(localeIp);

    m_tcpServer = new QTcpServer(this);
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

ExTcpServer::~ExTcpServer()
{
    delete ui;
}

QString ExTcpServer::getLocalIp()
{
    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    ui->plainTextEdit->appendPlainText("本机名称：" + hostName);
    QString locaIp;

    QList<QHostAddress> list = hostInfo.addresses();

    if (list.empty())
        return "null QString";

    foreach (QHostAddress addr, list) {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol) {
            locaIp = addr.toString();
            break;
        }
    }

    return locaIp;
}

void ExTcpServer::closeEvent(QCloseEvent *event)   //关闭窗口时候停止监听
{
    if (m_tcpServer->isListening())
        m_tcpServer->close();

    event->accept();
}

void ExTcpServer::on_actStart_triggered()
{
    QString Ip = ui->comboBox->currentText();
    quint16 port = ui->spinBox->value();

    QHostAddress addr(Ip);
    m_tcpServer->listen(addr, port);  //监听指定的 IP 和指定的 port
    ui->plainTextEdit->appendPlainText("服务器地址为:" + m_tcpServer->serverAddress().toString() + "   服务器端口：" + QString::number(m_tcpServer->serverPort()));
    ui->plainTextEdit->appendPlainText("开始监听...");

    ui->actStart->setEnabled(false);
    ui->actStop->setEnabled(true);
    m_labListen->setText("监听状态：正在监听...");
}

void ExTcpServer::on_actStop_triggered()
{
    if (!m_tcpServer->isListening())
        return;

    m_tcpServer->close();  //停止监听

    ui->actStart->setEnabled(true);
    ui->actStop->setEnabled(false);
    m_labListen->setText("监听状态：监听已经停止");
}

void ExTcpServer::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

void ExTcpServer::on_actQuit_triggered()
{
    close();
}

void ExTcpServer::on_btnSend_clicked()
{
    QString msg = ui->lineEdit->text();
    ui->plainTextEdit->appendPlainText("[服务器:]" + msg);
    ui->lineEdit->clear();
    ui->plainTextEdit->hasFocus();

    QByteArray str = msg.toUtf8();
    str.append('\n');
    m_tcpSocket->write(str);
}

void ExTcpServer::onSocketReadyRead()     //读取缓冲区行文本
{
    while (m_tcpSocket->canReadLine()) {
        ui->plainTextEdit->appendPlainText("[客户端:]" + m_tcpSocket->readLine());
    }
}

void ExTcpServer::onClientConnected()    //客户端连接时
{
    ui->plainTextEdit->appendPlainText("客户端套接字连接\n对等(peer)地址：" + m_tcpSocket->peerAddress().toString()
                                       + "    对等(peer)端口：" +  QString::number(m_tcpSocket->peerPort()));

}

void ExTcpServer::onClientDisonnected()  //客户端断开连接时
{
    ui->plainTextEdit->appendPlainText("客户端套接字断开");
    m_tcpSocket->deleteLater();
}

void ExTcpServer::onNewConnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();   //创建 socket

    connect(m_tcpSocket, SIGNAL(connected()), this, SLOT(onClientConnected()));
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(onClientDisonnected()));
    connect(m_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    onSocketStateChange(m_tcpSocket->state());
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}

void ExTcpServer::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
    case QAbstractSocket::UnconnectedState:
        m_labSocket->setText("socket状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        m_labSocket->setText("socket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        m_labSocket->setText("socket状态：ConnectingState");
        break;
    case QAbstractSocket::ConnectedState:
        m_labSocket->setText("socket状态：ConnectedState");
        break;
    case QAbstractSocket::BoundState:
        m_labSocket->setText("socket状态：BoundState");
        break;
    case QAbstractSocket::ClosingState:
        m_labSocket->setText("socket状态：ClosingState");
        break;
    case QAbstractSocket::ListeningState:
        m_labSocket->setText("socket状态：ListeningState");
        break;
    default:
        m_labSocket->setText("socket状态：其他未知状态...");
        break;
    }
}

