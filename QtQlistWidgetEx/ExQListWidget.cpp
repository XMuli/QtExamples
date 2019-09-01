#include "ExQListWidget.h"
#include "ui_ExQListWidget.h"

ExQListWidget::ExQListWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQListWidget)
{
    ui->setupUi(this);
}

ExQListWidget::~ExQListWidget()
{
    delete ui;
}
