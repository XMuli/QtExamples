#include "ExQHostInfo.h"
#include "ui_ExQHostInfo.h"

#include <QHostInfo>
#include <QNetworkInterface>

ExQHostInfo::ExQHostInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQHostInfo)
{
    ui->setupUi(this);

    setWindowTitle("QHostInfo/QNetworkInterface查询主机网络状态：");
}

ExQHostInfo::~ExQHostInfo()
{
    delete ui;
}

//通过协议类型返回协议名称
QString ExQHostInfo::protocolName(QAbstractSocket::NetworkLayerProtocol protocol)
{
    switch (protocol) {
    case QAbstractSocket::IPv4Protocol:
        return "IPv4 Protocol";
    case QAbstractSocket::IPv6Protocol:
        return "IPv6 Protocol";
    case QAbstractSocket::AnyIPProtocol:
        return "Any IP Protocol";
    default:
        return "Unknow Network Layer Protocol";
    }
}


void ExQHostInfo::on_btnGetHostInfo_clicked()
{

}

void ExQHostInfo::on_btnAllAddresses_clicked()
{

}

void ExQHostInfo::on_btnAllInterfaces_clicked()
{

}

void ExQHostInfo::on_btnFindIP_clicked()
{
    QString hostName = ui->lineEdit->text();  //域名
    ui->plainTextEdit->appendPlainText("正在查找域名的服务器的主机信息：" + hostName);
    QHostInfo::lookupHost(hostName, this, SLOT(onLookedUpHostInfo(QHostInfo)));
}

void ExQHostInfo::on_btnClean_clicked()
{
    ui->plainTextEdit->clear();
}

//查询主机信息的槽函数
void ExQHostInfo::onLookedUpHostInfo(const QHostInfo &host)
{
    QList<QHostAddress> list = host.addresses();

    if (list.isEmpty())
        return;

    for (int i = 0; i < list.count(); i++) {
        QHostAddress host = list.at(i);
        bool bIpv4 = ui->checkBox->isChecked();  //只显示IPv4

        if (bIpv4) {
            bIpv4 = QAbstractSocket::IPv4Protocol == host.protocol();
        } else {
            bIpv4 = false;
        }

        if (bIpv4) {
            ui->plainTextEdit->appendPlainText("协议：" + protocolName(host.protocol()));
            ui->plainTextEdit->appendPlainText(host.toString());
        }

    }
}

