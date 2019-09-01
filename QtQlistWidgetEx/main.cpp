#include "ExQListWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQListWidget w;
    w.show();

    return a.exec();
}
