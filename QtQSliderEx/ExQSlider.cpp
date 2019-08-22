#include "ExQSlider.h"
#include "ui_ExQSlider.h"
#include <QPalette>

ExQSlider::ExQSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQSlider)
{
    ui->setupUi(this);
	setWindowTitle(QObject::tr("QSlider的用法"));

    //设置QSlider的最大值为255  (默认范围为0~100)
    ui->sliderRed->setMaximum(255);
    ui->sliderGreen->setMaximum(255);
    ui->sliderBlue->setMaximum(255);
    ui->sliderAlpha->setMaximum(255);

    //初始化QTextEdit的颜色 (否则默认就是白灰色)
    QColor color;
    color.setRgb(145, 190, 251, 255);
    QPalette palette = ui->textColour->palette();
    palette.setColor(QPalette::Base, color);
    ui->textColour->setPalette(palette);

    //连接信号与槽，多个信号，对应一个槽函数
    connect(ui->sliderRed, SIGNAL(valueChanged(int)), this, SLOT(onSetClolor(int)));
    connect(ui->sliderGreen, SIGNAL(valueChanged(int)), this, SLOT(onSetClolor(int)));
    connect(ui->sliderBlue, SIGNAL(valueChanged(int)), this, SLOT(onSetClolor(int)));
    connect(ui->sliderAlpha, SIGNAL(valueChanged(int)), this, SLOT(onSetClolor(int)));
}

ExQSlider::~ExQSlider()
{
    delete ui;
}

void ExQSlider::onSetClolor(int val)
{
    Q_UNUSED(val)

    int nRed = ui->sliderRed->value();             //获取红绿蓝(RGB)的Slider的数值
    int nGreen = ui->sliderGreen->value();
    int nBlue = ui->sliderBlue->value();
    int nAlpha = ui->sliderAlpha->value();

    QColor color;
    color.setRgb(nRed, nGreen, nBlue, nAlpha);
    QPalette palette = ui->textColour->palette();   //获取textColour控件的所有颜色值(调色板)
    palette.setColor(QPalette::Base, color);        //设置textColou的某一角色(即控件)的颜色
    ui->textColour->setPalette(palette);

    ui->labRgbVal->setText(QString("RGB(%1, %2, %3, %4)").arg(nRed).arg(nGreen).arg(nBlue).arg(nAlpha));   //时刻显示RGBa的具体值
}
