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
