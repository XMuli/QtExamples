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

//QHostInfo 获取主机信息
void ExQHostInfo::on_btnGetHostInfo_clicked()
{
    QString hostName = QHostInfo::localHostName();
    ui->plainTextEdit->appendPlainText("本地主机名称:" + hostName + "\n");

    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QList<QHostAddress> list = hostInfo.addresses();

    if (list.isEmpty())
        return;

    foreach (QHostAddress var, list) {
        bool bIPv4 = ui->checkBox->isChecked();

        if (bIPv4) {   //只显示 IPv4
            bIPv4 = QAbstractSocket::IPv4Protocol == var.protocol();
        } else {
            bIPv4 = true;   //显示 IPv4 和 IPv6
        }

        if (bIPv4) {
            ui->plainTextEdit->appendPlainText("协议：" + protocolName(var.protocol()));
            ui->plainTextEdit->appendPlainText("本机IP地址" + var.toString() + "\n");
        }
    }
}

void ExQHostInfo::on_btnAllAddresses_clicked()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    if (list.isEmpty())
        return;

    foreach (QHostAddress var, list) {
        bool bIPv4 = ui->checkBox->isChecked();

        if (bIPv4) {   //只显示 IPv4
            bIPv4 = QAbstractSocket::IPv4Protocol == var.protocol();
        } else {
            bIPv4 = true;   //显示 IPv4 和 IPv6
        }

        if (bIPv4) {
            ui->plainTextEdit->appendPlainText("协议：" + protocolName(var.protocol()));
            ui->plainTextEdit->appendPlainText("本机IP地址" + var.toString() + "\n");
        }
    }
}

void ExQHostInfo::on_btnAllInterfaces_clicked()
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

    if (list.isEmpty())
        return;

    foreach (QNetworkInterface var, list) {
        if (!var.isValid())
            continue;

        ui->plainTextEdit->appendPlainText("设备名称：" + var.humanReadableName());
        ui->plainTextEdit->appendPlainText("硬件地址：" + var.hardwareAddress());

        QList<QNetworkAddressEntry> entry = var.addressEntries();
        foreach (QNetworkAddressEntry ent, entry) {
            ui->plainTextEdit->appendPlainText("  IP 地址：" + ent.ip().toString());
            ui->plainTextEdit->appendPlainText("  子网掩码：" + ent.netmask().toString());
            ui->plainTextEdit->appendPlainText("  子网广播：" + ent.broadcast().toString() + "\n");
        }
    }
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

        if (bIpv4) {   //只显示 IPv4
            bIpv4 = QAbstractSocket::IPv4Protocol == host.protocol();
        } else {
            bIpv4 = true;   //显示 IPv4 和 IPv6
        }

        if (bIpv4) {
            ui->plainTextEdit->appendPlainText("协议：" + protocolName(host.protocol()));
            ui->plainTextEdit->appendPlainText(host.toString());
        }
    }
}

