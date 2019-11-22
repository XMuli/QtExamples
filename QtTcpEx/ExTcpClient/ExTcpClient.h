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


private slots:
    //UI 定义的槽函数
    void on_actConnect_triggered();     //请求连接到服务器
    void on_actDisconnect_triggered();  //断开与服务器的连接
    void on_actClear_triggered();       //清除内容
    void on_actQuit_triggered();        //退出程序

private:
    Ui::ExTcpClient *ui;

    QLabel* m_labSocket;
    QTcpSocket* m_tcpSocket;
};

#endif // EXTCPCLIENT_H
