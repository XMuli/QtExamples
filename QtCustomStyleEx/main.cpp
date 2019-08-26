#include "Examples.h"
#include <QApplication>

#include <QStyleFactory>
#include <QDebug>
#include "ExCustomStyle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //使用系统或者自定义的风格
//    QStringList listStyle = QStyleFactory::keys();
//    foreach(QString val, listStyle)
//        qDebug()<<val<<"  ";
//    QStyleFactory::create("Fusion");
//    ExCustomStyle* customStyle = new ExCustomStyle;
//    qApp->setStyle(customStyle);

    Examples w;
    w.show();

    return a.exec();
}
