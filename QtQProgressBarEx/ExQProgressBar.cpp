#include "ExQProgressBar.h"
#include "ui_ExQProgressBaressBarressbar.h"

ExQProgressBar::ExQProgressBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQProgressBar)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("QSlider、QScrollBar、QProgressBar控件的联动"));

    //ui->progressBarHor->setOrient1ation(Qt::Horizontal /*(the default)  Qt::Vertical*/);  设置进度条水平或竖直

    connect(ui->sliderHor, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->scrollBarHor, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->scrollBarHor, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->sliderVer, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->scrollBarVer, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
    connect(ui->progressBarVer, SIGNAL(valueChanged(int)), this, SLOT(onValChange(int)));
}

ExQProgressBar::~ExQProgressBar()
{
    delete ui;
}

//对应的槽函数
void ExQProgressBar::onValChange(int val)
{
    ui->sliderHor->setValue(val);
    ui->scrollBarHor->setValue(val);
    ui->progressBarHor->setValue(val);
    ui->sliderVer->setValue(val);
    ui->scrollBarVer->setValue(val);
    ui->progressBarVer->setValue(val);

}
