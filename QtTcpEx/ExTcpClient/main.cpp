#include "ExTcpClient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExTcpClient w;
    w.show();

    return a.exec();
}
