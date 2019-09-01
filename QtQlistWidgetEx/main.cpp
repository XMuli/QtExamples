#include "Examples.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Examples w;
    w.show();

    return a.exec();
}
