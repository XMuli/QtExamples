#ifndef EXHTTP_H
#define EXHTTP_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDir>

namespace Ui {
class ExHttp;
}

class ExHttp : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExHttp(QWidget *parent = nullptr);
    ~ExHttp();

private slots:
    void on_btnDown_clicked();  //下载文件
    void on_btnFile_clicked();  //默认的保存路径
    void on_lineEditUrl_textChanged(const QString &arg1);

    void onFinished();          //网络响应结束
    void onReadyRead();         //读取下载的数据
    void onDownloadProgress(qint64 bytesRea, qint64 totalBytes);  //下载进程

private:
    Ui::ExHttp *ui;

    QNetworkAccessManager* m_networkManager;   //网络管理
    QNetworkReply* m_reply;                    //网络响应
    QFile* m_file;                             //下载保存的临时文件
};

#endif // EXHTTP_H
