#include "ifmetwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IfmetWindow w;
    w.show();

    return a.exec();
}
