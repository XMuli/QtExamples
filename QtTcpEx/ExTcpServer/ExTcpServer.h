#ifndef EXTCPSERVER_H
#define EXTCPSERVER_H

#include <QMainWindow>
#include <QLabel>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>

namespace Ui {
class ExTcpServer;
}

class ExTcpServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExTcpServer(QWidget *parent = nullptr);
    ~ExTcpServer();

private:
    QString getLocalIp();      //获取本机 IP

protected:
    void closeEvent(QCloseEvent* event);



private slots:
//UI的槽函数
    void on_actStart_triggered();      //开始监听
    void on_actStop_triggered();       //停止监听
    void on_actClear_triggered();      //清除文本框内容
    void on_actQuit_triggered();       //退出程序
    void on_btnSend_clicked();         //发送消息
    void on_actHostInfo_triggered();   //获取本机的 name 和 IP

//自定义的槽函数
    void onSocketReadyRead();          //读取 socket 传入时候的数据
    void onClientConnected();          //client socket conneted
    void onClientDisonnected();        //client socket disconneted


private:
    Ui::ExTcpServer *ui;

    QLabel* m_labListen;
    QLabel* m_labSocket;
    QTcpServer* m_tcpServer;
    QTcpSocket* m_tcpSocket;


};

#endif // EXTCPSERVER_H
