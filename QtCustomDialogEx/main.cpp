#include "ExCustomMainWin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExCustomMainWin w;
    w.show();

    return a.exec();
}
