#include "ExQProgressBar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQProgressBar w;
    w.show();

    return a.exec();
}
