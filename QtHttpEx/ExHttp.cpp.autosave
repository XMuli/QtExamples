#include "ExHttp.h"
#include "ui_ExHttp.h"
#include <QMessageBox>
#include <QDir>
#include <QDesktopServices>

ExHttp::ExHttp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExHttp)
{
    ui->setupUi(this);
    setWindowTitle("QNetworkAccessManager 网络管理使用 Http 协议下载");

    m_networkManager = new QNetworkAccessManager(this);
    m_reply = nullptr;
    m_file = nullptr;
}

ExHttp::~ExHttp()
{
    delete ui;
}

//下载文件
void ExHttp::on_btnDown_clicked()
{
    QString urlSpec = ui->lineEditUrl->text().trimmed();  //去掉字符串的首尾的空格
    if (urlSpec.isEmpty()) {
        QMessageBox::information(this, "提示", "下载地址URL为NULL");
        return;
    }

    QUrl url = QUrl::fromUserInput(urlSpec);
    if (!url.isValid()) {
        QMessageBox::information(this, "提示", QString("无效URL: %1 \n 错误信息: %2").arg(urlSpec, url.errorString()));
        return;
    }

    QString dir = ui->lineEditFile->text().trimmed();
    if (dir.isEmpty()) {
        QMessageBox::information(this, "提示", "保存地址为空");
        return;
    }

    QString fileFileName = dir + url.fileName(); //文件保存地址 + 文件名
    if (QFile::exists(fileFileName))
        QFile::remove(fileFileName);

    m_file = new QFile(fileFileName);    //创建临时文件
    if (!m_file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, "提示", "打开临时文件错误");
        return;
    }

    ui->btnDown->setEnabled(false);

    m_reply = m_networkManager->get(QNetworkRequest(url));  //发送get网络请求，创建网络响应
    connect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
    connect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(m_reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(onDownloadProgress(qint64,qint64)));
}

//默认的保存路径
void ExHttp::on_btnFile_clicked()
{
    QString currPath = QDir::currentPath();
    QDir dir(currPath);
    dir.mkdir("temp");

    ui->lineEditFile->setText(currPath + "/temp/");
}

//网络响应结束
void ExHttp::onFinished()
{
    QFileInfo fileInfo;
    fileInfo.setFile(m_file->fileName());

    m_file->close();
    delete m_file;
    m_file = nullptr;

    m_reply->deleteLater();
    m_reply = nullptr;

    if (ui->checkBox->isChecked())   //勾选了，下载完成之后，打开下载的文件               //absoluteFilePath() 返回包含文件名的绝对路径。
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));  //使用默认软件的打开下载的文件

    ui->btnDown->setEnabled(true);
}

//读取下载的数据
void ExHttp::onReadyRead()
{
    m_file->write(m_reply->readAll());   //将返回的数据进行读取，写入到临时文件中
}

//下载进程
void ExHttp::onDownloadProgress(qint64 bytesRea, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRea);
}

void ExHttp::on_lineEditUrl_textChanged(const QString &arg1)
{
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
}
