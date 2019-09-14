#include "ExQStringListModel.h"
#include "ui_ExQStringListModel.h"

ExQStringListModel::ExQStringListModel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQStringListModel)
{
    ui->setupUi(this);
}

ExQStringListModel::~ExQStringListModel()
{
    delete ui;
}
