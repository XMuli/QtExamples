#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>

class QDomElement;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;


private:
    QToolButton* m_btn;
    QToolButton* m_btn2;
};


void SetAttrRecur(QDomElement &elem, QString strtagname, QString strattr, QString strattrval);
#endif // WIDGET_H
