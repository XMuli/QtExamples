#include "widget.h"
#include <QMetaMethod>
#include <QPushButton>


////Qt4: 宏
///*式1*/  static QMetaObject::Connection connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
///*式2*/         QMetaObject::Connection connect(const QObject *sender, const char *signal, const char *method, Qt::ConnectionType type = Qt::AutoConnection) const
//// Qt5: 函数指针
///*式3*/  static QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction method, Qt::ConnectionType type = Qt::AutoConnection)
///*式4*/  static QMetaObject::Connection connect(const QObject *sender, PointerToMemberFunction signal, Functor functor)
///*式5*/  static QMetaObject :: Connection QObject :: connect(const QObject * sender， const QMetaMethod＆signal，const QObject * receiver， const QMetaMethod＆ method，Qt :: ConnectionType type = Qt :: AutoConnection）


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("信号和槽：Qt4 与 Qt5 的 Connect 用法"));
    QPushButton *btn = new QPushButton(tr("关闭"), this);
    btn->move(width() / 2, height() / 2);
    setFixedSize(800, 600);

    // Qt4: 宏
//    connect(btn, SIGNAL(clicked()), this, SLOT(close()));  // 式 1
//    connect(btn, SIGNAL(clicked()), SLOT(close()));  // 式 2


    // Qt5: 函数指针
//    connect(btn, &QPushButton::clicked, this, &Widget::close);  // 式 3

//    connect(btn, &QPushButton::clicked, [=](){  // 式 4
//        close();
//    });

    int indexSig = btn->metaObject()->indexOfSignal("clicked(bool)");
    int indexSlot = metaObject()->indexOfSlot("close()");
    connect(btn, btn->metaObject()->method(indexSig), this, metaObject()->method(indexSlot)); // 式 5
}

Widget::~Widget()
{
}

