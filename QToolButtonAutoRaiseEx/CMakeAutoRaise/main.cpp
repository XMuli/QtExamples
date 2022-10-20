#include "testbtstyle.h"
#include "widget.h"

#include <QApplication>
#include <QStyleFactory>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    qApp->setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    QStringList listStyle = QStyleFactory::keys();
    foreach(QString val, listStyle)
      qDebug()<<val<<"  ";
    QApplication::setStyle("Windows");  // macintosh Windows   Fusion

    auto t = new TestBTStyle();
    t->setWindowTitle("MacOS 12.6 + Qt 5.15.2 + Style: Windows");
    t->show();

    return a.exec();
}


