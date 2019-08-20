#include "ExQSlider.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExQSlider w;
    w.show();

    return a.exec();
}
