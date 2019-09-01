#include "Examples.h"
#include "ui_Examples.h"

Examples::Examples(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Examples)
{
    ui->setupUi(this);
}

Examples::~Examples()
{
    delete ui;
}
