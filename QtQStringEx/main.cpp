#include "ExQString.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQString w;
    w.show();

    return a.exec();
}
