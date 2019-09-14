#include "ExQStringListModel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQStringListModel w;
    w.show();

    return a.exec();
}
