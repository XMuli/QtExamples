#include "Examples.h"
#include "ui_Examples.h"

Examples::Examples(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Examples)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("创建自定义的CustomStyle风格"));
}

Examples::~Examples()
{
    delete ui;
}
