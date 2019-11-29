#include "ExTrans.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExTrans w;
    w.show();

    return a.exec();
}
