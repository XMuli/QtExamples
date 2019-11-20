#ifndef EXTCPSERVER_H
#define EXTCPSERVER_H

#include <QMainWindow>

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
    Ui::ExTcpServer *ui;
};

#endif // EXTCPSERVER_H
