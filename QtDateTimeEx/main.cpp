#include "ExDateTime.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExDateTime w;
    w.show();

    return a.exec();
}
