#include "ExMDI.h"
#include "ExMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExMainWindow w;
    w.show();

    return a.exec();
}
