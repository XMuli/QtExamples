#include "ExQStandardItemModel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQStandardItemModel w;
    w.show();

    return a.exec();
}
