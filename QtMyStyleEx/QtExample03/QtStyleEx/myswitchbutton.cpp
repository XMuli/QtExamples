#include "myswitchbutton.h"
#include "myswitchbutton_p.h"
#include "mystyle.h"

#include <QStylePainter>
#include <QStyleOptionButton>

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
    return QSize(100, 40);
}

void MySwitchButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QStyleOptionButton opt;
    initStyleOption(&opt);

    QStylePainter pa(this);
//    pa.drawControl(MyStyle::CE_SwitchButton, opt);
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

    checked = false;
    animationStart = 0;
    animationEnd = 1;
    q->setObjectName("MySwitchButton");
//    q->connect(q, &MySwitchButton::toggled, q, &MySwitchButton::checkedChanged);
}
