#ifndef MYSWITCHBUTTON_H
#define MYSWITCHBUTTON_H

#include <QAbstractButton>
#include <QStyleOption>
class QStyleOptionButton;

class MySwitchButtonPrivate;
class MySwitchButton : public QAbstractButton//bianxinagjicengle QObject
{
    Q_OBJECT
public:
    explicit MySwitchButton(QWidget* parent = nullptr);
    ~MySwitchButton();

    // QWidget interface
public:
    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    void initStyleOption(QStyleOptionButton *opt) const;

private:
    Q_DECLARE_PRIVATE(MySwitchButton)
};

#endif // MYSWITCHBUTTON_H
