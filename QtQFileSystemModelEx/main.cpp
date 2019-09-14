#include "ExQFileSystemModel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQFileSystemModel w;
    w.show();

    return a.exec();
}
