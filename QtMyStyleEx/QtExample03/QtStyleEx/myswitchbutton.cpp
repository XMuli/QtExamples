#include "myswitchbutton.h"
#include "myswitchbutton_p.h"
#include "mystyle.h"

#include <QStylePainter>
#include <QStyleOption>
#include <QDebug>

class MyStylePainter;

MySwitchButton::MySwitchButton(QWidget *parent)
    : QAbstractButton(parent)
{
    Q_D(MySwitchButton);

    d->init();
}

MySwitchButton::~MySwitchButton()
{

}

QSize MySwitchButton::sizeHint() const
{
    return QSize(60, 40);
}

void MySwitchButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QStyleOptionButton opt;
    initStyleOption(&opt);

    MyStylePainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawControl(MyStyle::CE_SwitchButton, &opt);
}

void MySwitchButton::initStyleOption(QStyleOptionButton *opt) const
{
    if (!opt)
        return;

    opt->init(this);
    opt->initFrom(this);

    if (isChecked())
        opt->state |= QStyle::State_On;
    else
        opt->state |= QStyle::State_Off;
}

MySwitchButtonPrivate::MySwitchButtonPrivate()
{
}

MySwitchButtonPrivate::~MySwitchButtonPrivate()
{
}

void MySwitchButtonPrivate::init()
{
    Q_Q(MySwitchButton);

    check = false;
    q->setObjectName("MySwitchButton");
    q->setChecked(true);
    q->setCheckable(true); //clicked  toggled 都需要开启
    q->connect(q, SIGNAL(clicked(bool)), q, SLOT(setChecked(bool)));
}

bool MySwitchButtonPrivate::switchCheck()
{
    return check;
}
