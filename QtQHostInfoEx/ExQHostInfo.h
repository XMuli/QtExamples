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
    void on_btnGetHostInfo_clicked();
    void on_btnAllAddresses_clicked();
    void on_btnAllInterfaces_clicked();
    void on_btnFindIP_clicked();
    void on_btnClean_clicked();

    void onLookedUpHostInfo(const QHostInfo& host);




private:
    Ui::ExQHostInfo *ui;

};

#endif // EXQHOSTINFO_H
