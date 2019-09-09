#include "ExQTreeWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQTreeWidget w;
    w.show();

    return a.exec();
}
