#include "ifmetwindow.h"
#include "ui_ifmetwindow.h"

IfmetWindow::IfmetWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IfmetWindow)
{
    ui->setupUi(this);
}

IfmetWindow::~IfmetWindow()
{
    delete ui;
}
