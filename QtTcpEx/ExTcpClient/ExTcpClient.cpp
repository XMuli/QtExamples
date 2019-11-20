#include "ExTcpClient.h"
#include "ui_ExTcpClient.h"

ExTcpClient::ExTcpClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExTcpClient)
{
    ui->setupUi(this);
}

ExTcpClient::~ExTcpClient()
{
    delete ui;
}
