#include "widget.h"

#include <QApplication>
#include <QMap>
#include <QString>
#include <QVector>
#include <QDebug>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();


//    QVector<QMap<QString, QString>> vLab;
//    vLab.append(QMap<QString, QString>({"labRed", "#DB000F"}));
//    vLab.append(QMap<QString, QString>({"labYellow", "#FFCF53"}));
//    vLab.append(QMap<QString, QString>({"labGreen", "#12F63B"}));
//    vLab.append(QMap<QString, QString>({"labBlue", "#0E70FF"}));
//    vLab.append(QMap<QString, QString>({"labPink", "#FB4288"}));
//    vLab.append(QMap<QString, QString>({"labBlack", "#323232"}));
//    vLab.append(QMap<QString, QString>({"labWhite", "#FBFBFB"}));
//    vLab.append(QMap<QString, QString>({"labPick", "#FFDB34"}));  //

//    qDebug() << vLab[2].first() << "  ";


//    QPushButton* btn = new QPushButton("btn123");
//    QIcon icon("D:/projects/PicShot/src/resourcesicons/normal/gif.svg");
//    btn->setIcon(icon);
//    btn->show();
    return a.exec();
}
