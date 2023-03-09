#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QString s1 = "(abcdefg1234hijk)";
//    QString s2 = "[FOXES]";

    QString s1 = "(abcdefg1234hijk)\r[FOXES]";
    QString s2 = "(abcdefg1234hijk)\n[FOXES]";
    QString s3 = "(abcdefg1234hijk)\r\n[FOXES]";
    QString s4 = "(abcdefg1234hijk)\n\r[FOXES]";

    qDebug()<< "---------qDebug()----------";
    qDebug()<< s1;
    qDebug().noquote()<< s1;
    qDebug()<< s2;
    qDebug().noquote()<< s2;
    qDebug()<< s3;
    qDebug().noquote()<< s3;
    qDebug()<< s4;
    qDebug().noquote()<< s4;

    qDebug()<< "---------cout----------";
    cout << "(abcdefg1234hijk)\r[FOXES]";
    cout.flush();
    cout << "(abcdefg1234hijk)\n[FOXES]";
    cout.flush();
    cout << "(abcdefg1234hijk)\r\n[FOXES]";
    cout.flush();
    cout << "(abcdefg1234hijk)\n\r[FOXES]";
    cout.flush();

    QFile file("ExCRLF.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write("(abcdefg1234hijk)\r[FOXES]");
    file.write("(abcdefg1234hijk)\n[FOXES]");
    file.write("(abcdefg1234hijk)\r\n[FOXES]");
    file.write("(abcdefg1234hijk)\n\r[FOXES]");
    file.close();

    return a.exec();
}
