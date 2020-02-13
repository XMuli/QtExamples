#include "widget.h"

#include <QDebug>
#include <QTableWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QApplication>
#include <QSlider>
#include <QScrollBar>
#include <QStyleFactory>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    init();
}

Widget::~Widget()
{

}

void Widget::init()
{
    QTableWidget *table = new QTableWidget(10, 10, this);
    table->move(10, 10);

    QScrollBar *scrollBarH = new QScrollBar(this);
    scrollBarH->move(300, 50);
    scrollBarH->setRange(0, 100);
    scrollBarH->setValue(34);
    scrollBarH->resize(380, 20);
    scrollBarH->setOrientation(Qt::Horizontal);

    QScrollBar *scrollBarV = new QScrollBar(this);
    scrollBarV->move(50, 250);
    scrollBarV->setRange(0, 100);
    scrollBarV->setValue(67);
    scrollBarV->resize(20, 380);
    scrollBarV->setOrientation(Qt::Vertical);

    QProgressBar* progreH = new QProgressBar(this);
    progreH->move(300, 100);
    progreH->resize(250, 40);
    progreH->setValue(37);
    progreH->setOrientation(Qt::Horizontal);

    QProgressBar* progreV = new QProgressBar(this);
    progreV->move(100, 300);
    progreV->resize(40, 250);
    progreV->setValue(67);
    progreV->setOrientation(Qt::Vertical);

    int i = 0;
    QStringList listStyle = QStyleFactory::keys();
    foreach(QString val, listStyle) {   //打印当前系统支持的系统风格
        qDebug()<<val<<"  ";
        QPushButton *btn = new QPushButton(val, this);
        btn->move(this->rect().right() - 100, this->rect().top() + i++ * 40);
        connect(btn, &QPushButton::clicked, this, [=](){
            qApp->setStyle(val);
        });
    }

}
