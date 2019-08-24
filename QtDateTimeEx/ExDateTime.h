#ifndef EXDATETIME_H
#define EXDATETIME_H

#include <QWidget>
#include <QTimer>
#include <QTime>

namespace Ui {
class ExDateTime;
}

class ExDateTime : public QWidget
{
    Q_OBJECT

public:
    explicit ExDateTime(QWidget *parent = nullptr);
    ~ExDateTime();

private slots:
    void on_btnGetDateTime_clicked();
    void on_btnStatrt_clicked();
    void on_btnStop_clicked();
    void onTimerOut();   //处理计时器的信号的槽函数

    void on_calendarWidget_selectionChanged();

    void on_btnPeriod_clicked();

private:
    Ui::ExDateTime *ui;

    QTimer* m_timer;     //定时器（不可见控件）
    QTime   m_time;      //计时器（此处用作）



};

#endif // EXDATETIME_H
