#include "widget.h"

#include <QPainter>
#include <QDebug>

// test
#include <QFile>
#include <QByteArray>
#include <QPainter>
#include <QPixmap>
#include <QIcon>
#include <QSvgRenderer>
#include <QDomElement>
#include <QDomElement>
#include <QIcon>
#include <QSize>


QIcon ChangeSVGColor(QString path, QString color, QSize size)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray baData = file.readAll();

    QDomDocument doc;
    doc.setContent(baData);
    QDomElement elem = doc.documentElement(); // const 和 值传递
    SetAttrRecur(elem, "path", "fill", color);

    QSvgRenderer svgRenderer(doc.toByteArray());
    // create pixmap target (could be a QImage)
//    QPixmap pix(svgRenderer.defaultSize());
    QPixmap pix(svgRenderer.defaultSize().scaled(size.width(), size.height(), Qt::KeepAspectRatio));  // fix: 修改 svg 颜色后略有模糊
    pix.fill(Qt::transparent);
    // create painter to act over pixmap
    QPainter pixPainter(&pix);
    // use renderer to render over painter which paints on pixmap
    svgRenderer.render(&pixPainter);
    QIcon myicon(pix);
    return myicon;
}


void SetAttrRecur(QDomElement &elem, QString strtagname, QString strattr, QString strattrval)
{
    // if it has the tagname then overwritte desired attribute
    if (elem.tagName().compare(strtagname) == 0)
    {
        elem.setAttribute(strattr, strattrval);
    }
    // loop all children
    for (int i = 0; i < elem.childNodes().count(); i++)
    {
        if (!elem.childNodes().at(i).isElement())
        {
            continue;
        }
        QDomElement t = elem.childNodes().at(i).toElement();
        SetAttrRecur(t, strtagname, strattr, strattrval);
    }
}




Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_btn()
{
    setWindowTitle("change .svg color");
    resize(1600, 1000);
    const int width = 80;

    QIcon icon(ChangeSVGColor(":/mosaic.svg", QColor(Qt::green).name(), QSize(width, width)));
    m_btn = new QToolButton(this);
    m_btn->setCheckable(true);
    m_btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    m_btn->setAutoRaise(true);   // 自动浮动模式
    m_btn->setIcon(icon);
    m_btn->setIconSize(QSize(width, width));
//    m_btn->resize(200, 200);
    m_btn->move(0, 0);


    QIcon icon2(":/mosaic.svg");
    m_btn2 = new QToolButton(this);
    m_btn2->setCheckable(true);
    m_btn2->setToolButtonStyle(Qt::ToolButtonIconOnly);
    m_btn2->setAutoRaise(true);   // 自动浮动模式
    m_btn2->setIcon(icon);
    m_btn2->setIconSize(QSize(width, width));
//    m_btn->resize(200, 200);
    m_btn2->move(100, 100);


    m_btn->show();
    m_btn2->show();

    connect(m_btn, &QToolButton::clicked, this, [&](bool checked){
        QString path(":/mosaic.svg");

        QIcon ico;
        if (checked)
            ico.addFile(path);
        else
            ico = ChangeSVGColor(":/mosaic.svg", QColor(Qt::green).name(), QSize(width, width));

        m_btn->setIcon(ico);
    });



}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter pa(this);
    pa.setBrush(Qt::NoBrush);
    pa.setPen(QPen(Qt::black, 1));

    pa.setPen(Qt::blue);
    QRect rt(200, 200, 200, 200);
    pa.drawRect(rt);

    QPoint pos(500, 200);
    int off = 30;
    pa.drawText(pos + QPoint(0, off * 0), QString("rt.x():%1 rt.y():%2 rt.width():%3 rt.height():%4")
                .arg(rt.x()).arg(rt.y()).arg(rt.width()).arg(rt.height()));
    pa.drawText(pos + QPoint(0, off * 1), QString("rt.left():%1 rt.top():%2 rt.right():%3 rt.bottom():%4")
                .arg(rt.left()).arg(rt.top()).arg(rt.right()).arg(rt.bottom()));
    pa.drawText(pos + QPoint(0, off * 2), QString("rt.topLeft().x():%1 rt.topLeft().y():%2 rt.bottomRight().x():%3 rt.bottomRight().y():%4")
                .arg(rt.topLeft().x()).arg(rt.topLeft().y()).arg(rt.bottomRight().x()).arg(rt.bottomRight().y()));

    update();
}




