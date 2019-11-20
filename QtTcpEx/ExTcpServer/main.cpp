#include "ExTcpServer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExTcpServer w;
    w.show();

    return a.exec();
}
