#include "ExDlgLocate.h"
#include "ui_ExDlgLocate.h"

#include "ExCustomMainWin.h"
#include <QMessageBox>

ExDlgLocate::ExDlgLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExDlgLocate)
{
    ui->setupUi(this);
}

ExDlgLocate::~ExDlgLocate()
{
    QMessageBox::information(this,"提示","单元格定位对话框被删除");
    delete ui;
}

//设置spin的设定(最大)值
void ExDlgLocate::setSpinRange(int rowCount, int colCount)
{
    ui->spinBoxRow->setMaximum(rowCount - 1);
    ui->spinBoxCol->setMaximum(colCount - 1);
}

//设置spin的初始值
void ExDlgLocate::setSpinValue(int rowNo, int colNo)
{
    ui->spinBoxRow->setValue(rowNo);
    ui->spinBoxCol->setValue(colNo);
}

//设置文字
void ExDlgLocate::on_btnSetText_clicked()
{
    int row = ui->spinBoxRow->value();                                     //定位到单元格，并且设置字符串
    int col = ui->spinBoxCol->value();

    ExCustomMainWin* parWind = (ExCustomMainWin*)parentWidget();           //向具体的item中填写字符串
    parWind->setACellText(row, col, ui->lineEdit->text());

    if (ui->checkBoxRow->isChecked())
        ui->spinBoxRow->setValue(1 + ui->spinBoxRow->value());
    if (ui->checkBoxCol->isChecked())
        ui->spinBoxCol->setValue(1 + ui->spinBoxCol->value());
}

//窗口关闭事件，关闭时释放本窗口
void ExDlgLocate::closeEvent(QCloseEvent *event)
{
    ExCustomMainWin* parWind = (ExCustomMainWin*)parentWidget();           //获取父窗口指针
    parWind->setActLocateEnable(true);                                     //设置 actLocatee 为true
    parWind->setDlgLocateNull();                                           //将窗口指针设置为NULL
}

//窗口显示事件
void ExDlgLocate::showEvent(QShowEvent *event)
{
    ExCustomMainWin* parWind = (ExCustomMainWin*)parentWidget();
    parWind->setActLocateEnable(false);
}

void ExDlgLocate::on_btnClose_clicked()
{

}
