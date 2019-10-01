#include "ExDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExDialog w;
    w.show();

    return a.exec();
}
