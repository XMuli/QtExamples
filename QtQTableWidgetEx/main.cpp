#include "ExQTableWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQTableWidget w;
    w.show();

    return a.exec();
}
