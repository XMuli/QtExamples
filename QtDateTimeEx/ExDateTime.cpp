#include "ExDateTime.h"
#include "ui_ExDateTime.h"
#include <QDateTime>

ExDateTime::ExDateTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExDateTime)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("时间日期(QTime/QDate/QDateTime)和定时器(QTimer)"));

    //editDate控件在UI设计师里面，选中了calendarPopup （日历弹出的属性）和displayFormat显示格式

    m_timer = new QTimer(this);
    m_timer->stop();                       //关闭定时器
    m_timer->setInterval(1000);            //设定定时周期， 单位 毫秒
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));
}

ExDateTime::~ExDateTime()
{
    delete ui;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//获取当前日期和时间，该日期时间栏里面显示
void ExDateTime::on_btnGetDateTime_clicked()
{
    QDateTime currDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(currDateTime.time());
    ui->editTime->setText(currDateTime.toString("hh:mm:ss:zzz"));
    ui->dateEdit->setDate(currDateTime.date());
    ui->editDate->setText(currDateTime.toString("yyyy-MM-dd"));
    ui->dateTimeEdit->setDateTime(currDateTime);
    ui->editDateTime->setText(currDateTime.toString("yyyy-MM-dd hh:mm:ss:zzz"));
    ui->labCurrDataTime->setText(currDateTime.toString("yyyy-MM-dd hh:mm:ss:zzz"));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//计时器开始
void ExDateTime::on_btnStatrt_clicked()
{
    m_time.start();                                 //计时器开始
    m_timer->start();                               //定时器开始
    ui->btnStatrt->setEnabled(false);               //开始按下之后，开始按钮禁用
    ui->btnStop->setEnabled(true);                  //同时结束按钮可用
    ui->btnPeriod->setEnabled(false);               //设定周期的按钮为禁用
    ui->labGo->setText(QString("时间流逝在后台计算中..."));
}

//计时器结束
void ExDateTime::on_btnStop_clicked()
{
    m_timer->stop();                                 //定时器停止
    ui->btnStop->setEnabled(false);                  //结束按下之后，结束按钮禁用
    ui->btnStatrt->setEnabled(true);                 //同时开始按钮可用

    int tmMsec = m_time.elapsed();                   //计时器Time没有对应的stop(), elapsed获取它的毫秒数
    int ms = tmMsec % 1000;                          //经过的毫秒
    int sec = tmMsec / 1000;                         //经过的秒
    ui->btnPeriod->setEnabled(true);                 //设定周期的按钮为可用
    ui->labGo->setText(QString("时间已经流逝：%1 秒 %2 毫秒").arg(sec).arg(ms));
}

//处理定时器的槽函数
void ExDateTime::onTimerOut()
{
    QTime currTime = QTime::currentTime();
    ui->lcdHH->display(currTime.hour());             //多种显示时间方法
    ui->lcdmm->display(currTime.toString("mm"));
    ui->lcdSS->display(currTime.toString("ss"));

    int val = ui->progressBar->value();              //设置进度条同时增加
    val++;
    if (val > 100)
        val = 0;
    ui->progressBar->setValue(val);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//选择日历时间
void ExDateTime::on_calendarWidget_selectionChanged()
{
    QDate date =ui->calendarWidget->selectedDate();
    ui->editChoose->setText(date.toString("yyyy年MM月dd日"));
}

//设定定时器QTimer周期
void ExDateTime::on_btnPeriod_clicked()
{
    m_timer->setInterval(ui->spinBox->value());
}
