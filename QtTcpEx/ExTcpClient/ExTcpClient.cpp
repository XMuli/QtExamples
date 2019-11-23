#include "ExTcpClient.h"
#include "ui_ExTcpClient.h"

ExTcpClient::ExTcpClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExTcpClient)
{
    ui->setupUi(this);

    m_labSocket = new QLabel("socket状态：");
    m_labSocket->setMidLineWidth(150);
    ui->statusBar->addWidget(m_labSocket);

    m_tcpSocket = new QTcpSocket(this);

    QString localIp = getLocalIp();
    this->setWindowTitle(windowTitle() + "----本机IP:" + localIp);
    ui->comboBox->addItem(localIp);

    connect(m_tcpSocket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(m_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}

ExTcpClient::~ExTcpClient()
{
    delete ui;
}

QString ExTcpClient::getLocalIp()
{
    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    ui->plainTextEdit->appendPlainText("本机名称：" + hostName);
    QString localIp;

    foreach (QHostAddress addr, hostInfo.addresses()) {
        if (QAbstractSocket::IPv4Protocol == addr.protocol()) {
            localIp = addr.toString();
            break;
        }
    }
    return localIp;
}

void ExTcpClient::closeEvent(QCloseEvent *event)
{
    if (m_tcpSocket->state() == QAbstractSocket::ConnectedState)
        m_tcpSocket->disconnectFromHost();

    event->accept();
}

void ExTcpClient::onConnected()
{
    ui->plainTextEdit->appendPlainText("已经连接到服务器\n客户端套接字连接\n对等(peer)地址：" + m_tcpSocket->peerAddress().toString()
                                       + "    对等(peer)端口：" +  QString::number(m_tcpSocket->peerPort()));
    ui->actConnect->setEnabled(false);
    ui->actDisconnect->setEnabled(true);
}

void ExTcpClient::onDisconnected()
{
    ui->plainTextEdit->appendPlainText("已经断开与服务器的连接\n");
    ui->actConnect->setEnabled(true);
    ui->actDisconnect->setEnabled(false);
}

void ExTcpClient::onSocketReadyRead()
{
    while (m_tcpSocket->canReadLine()) {
        ui->plainTextEdit->appendPlainText("[服务器:]" + m_tcpSocket->readLine());
    }
}

void ExTcpClient::onSocketStateChange(QAbstractSocket::SocketState socketState)
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

void ExTcpClient::on_actConnect_triggered()
{
    QString addr = ui->comboBox->currentText();
    quint16 port = ui->spinBox->value();
    m_tcpSocket->connectToHost(addr, port);
}

void ExTcpClient::on_actDisconnect_triggered()
{
    if(m_tcpSocket->state() == QAbstractSocket::ConnectedState)
        m_tcpSocket->disconnectFromHost();
}

void ExTcpClient::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

void ExTcpClient::on_actQuit_triggered()
{
    close();
}

void ExTcpClient::on_btnSend_clicked()
{
    QString msg = ui->lineEdit->text();
    ui->plainTextEdit->appendPlainText("[客户端:]" + msg);
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();

    QByteArray str = msg.toUtf8();
    str.append('\n');
    m_tcpSocket->write(str);
}
