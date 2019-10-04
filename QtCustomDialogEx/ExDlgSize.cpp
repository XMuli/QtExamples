#include "ExDlgSize.h"
#include "ui_ExDlgSize.h"
#include <QMessageBox>

ExDlgSize::ExDlgSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExDlgSize)
{
    ui->setupUi(this);
}

ExDlgSize::~ExDlgSize()
{
    QMessageBox::information(this,"提示","设置表格行列数对话框被删除");
    delete ui;
}

int ExDlgSize::getRowCount()
{
    return ui->spinBoxRow->value();
}

int ExDlgSize::getColCount()
{
    return ui->spinBoxCol->value();
}

void ExDlgSize::setRowCol(int row, int col)
{
    ui->spinBoxRow->setValue(row);
    ui->spinBoxCol->setValue(col);
}
