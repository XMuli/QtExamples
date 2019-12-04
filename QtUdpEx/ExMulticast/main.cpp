#include "ExMulticast.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExMulticast w;
    w.show();

    return a.exec();
}
