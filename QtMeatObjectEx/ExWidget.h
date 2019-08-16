#ifndef EXWIDGET_H
#define EXWIDGET_H

#include <QWidget>
#include "ExPerson.h"

namespace Ui {
class ExWidget;
}

class ExWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExWidget(QWidget *parent = nullptr);
    ~ExWidget();

private slots:
    void onAgeChange(int val);       //自定义的槽函数
    void onSpinValChange(int val);

    void onBtnClear();               //UI界面的槽函数
    void onBtnBoyInc();
    void onBtnGrilInc();
    void onClassInfo();

private:
    Ui::ExWidget *ui;

    ExPerson* m_boy;
    ExPerson* m_girl;
};

#endif // EXWIDGET_H
