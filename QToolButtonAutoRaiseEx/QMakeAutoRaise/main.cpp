#include "testbtstyle.h"
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    auto t = new TestBTStyle();
    t->show();

    return a.exec();
}
