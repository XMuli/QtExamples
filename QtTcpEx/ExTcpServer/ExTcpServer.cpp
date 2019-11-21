#include "ExTcpServer.h"
#include "ui_ExTcpServer.h"

ExTcpServer::ExTcpServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExTcpServer)
{
    ui->setupUi(this);
}

ExTcpServer::~ExTcpServer()
{
    delete ui;
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

}



void ExTcpServer::on_actHostInfo_triggered()
{
    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    ui->plainTextEdit->appendPlainText("本机主机名：" + hostName);

    QList<QHostAddress> list = hostInfo.addresses();

    if (list.empty())
        return;

    foreach (QHostAddress addr, list) {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol) {
            ui->plainTextEdit->appendPlainText("本机 IP 地址：" + addr.toString());

            if (ui->comboBox->findText(addr.toString()) < 0)  //下拉列表没有的就添加进去
                ui->comboBox->addItem(addr.toString());
        }
    }
}

void ExTcpServer::onSocketReadyRead()
{

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
