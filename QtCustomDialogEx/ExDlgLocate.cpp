#include "ExDlgLocate.h"
#include "ui_ExDlgLocate.h"

#include "ExCustomMainWin.h"

ExDlgLocate::ExDlgLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExDlgLocate)
{
    ui->setupUi(this);
}

ExDlgLocate::~ExDlgLocate()
{
    delete ui;
}

void ExDlgLocate::setSpinRange(int rowCount, int colCount)
{

}

void ExDlgLocate::setSpinValue(int rowNo, int colNo)
{

}

void ExDlgLocate::closeEvent(QCloseEvent *e)
{

}

void ExDlgLocate::on_btnSetText_clicked()
{
    int row = ui->spinBoxRow->value();                                     //定位到单元格，并且设置字符串
    int col = ui->spinBoxCol->value();

    ExCustomMainWin *parWind = new ExCustomMainWin(nullptr);               //向具体的item中填写字符串
    parWind->setACellText(row, col, ui->lineEdit->text());

    if (ui->checkBoxRow->isChecked())
        ui->spinBoxRow->setValue(1 + ui->spinBoxRow->value());
    if (ui->checkBoxCol->isChecked())
        ui->spinBoxCol->setValue(1 + ui->spinBoxCol->value());
}
