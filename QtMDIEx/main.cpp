#include "ExMDI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExMDI w;
    w.show();

    return a.exec();
}
