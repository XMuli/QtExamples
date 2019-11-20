#ifndef EXTCPCLIENT_H
#define EXTCPCLIENT_H

#include <QMainWindow>

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
    Ui::ExTcpClient *ui;
};

#endif // EXTCPCLIENT_H
