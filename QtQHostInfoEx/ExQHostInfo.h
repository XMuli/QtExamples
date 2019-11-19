#ifndef EXQHOSTINFO_H
#define EXQHOSTINFO_H

#include <QWidget>
#include <QAbstractSocket>
class QHostInfo;


namespace Ui {
class ExQHostInfo;
}

class ExQHostInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ExQHostInfo(QWidget *parent = nullptr);
    ~ExQHostInfo();

private:
    QString protocolName(QAbstractSocket::NetworkLayerProtocol protocol);  //通过协议类型返回协议名称

private slots:
    void on_btnGetHostInfo_clicked();    //QHostInfo查询主机名和IP
    void on_btnAllAddresses_clicked();   //QNetworkInterface::allAddresses()
    void on_btnAllInterfaces_clicked();  //QNetworkInterface::allInterfaces()
    void on_btnFindIP_clicked();         //QHostInfo查询左侧域名IP地址
    void on_btnClean_clicked();          //清空文本框信息

    void onLookedUpHostInfo(const QHostInfo& host);  //查询主机信息的槽函数

private:
    Ui::ExQHostInfo *ui;

};

#endif // EXQHOSTINFO_H
