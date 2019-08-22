#include "ExQdialQLCD.h"
#include "ui_ExQdialQLCD.h"

ExQdialQLCD::ExQdialQLCD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQdialQLCD)
{
    ui->setupUi(this);

    //notchesVisible:表盘的小刻度是否可见
    //notchTarget：表盘刻度间间隔的像素值
    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(onDisplayLCD(int)));
	setWindowTitle(QObject::tr("QDial表盘输入，在LCD以多种进制显示"));
}

ExQdialQLCD::~ExQdialQLCD()
{
    delete ui;
}

void ExQdialQLCD::onDisplayLCD(int val)
{
    ui->lcdNumber->display(val);
}

void ExQdialQLCD::on_raidBtn2_clicked()   //设置LCD显示二进制数
{
    ui->lcdNumber->setBinMode();
}

void ExQdialQLCD::on_raidBtn8_clicked()   //设置LCD显示八进制数
{
    ui->lcdNumber->setOctMode();
}

void ExQdialQLCD::on_raidBtn10_clicked()  //设置LCD显示十进制数
{
    ui->lcdNumber->setDecMode();
}

void ExQdialQLCD::on_raidBtn16_clicked()  //设置LCD显示十六进制数
{
    ui->lcdNumber->setHexMode();
}
