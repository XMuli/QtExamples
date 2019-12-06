#include "ExHttp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExHttp w;
    w.show();

    return a.exec();
}
