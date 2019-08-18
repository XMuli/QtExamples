#include "ExQStringFun.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQStringFun w;
    w.show();

    return a.exec();
}
