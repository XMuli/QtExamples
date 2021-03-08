#include "ifmetwindow.h"
#include "ui_ifmetwindow.h"

/*!
 * \brief IfmetWindow::IfmetWindow 我的构造函数
 * \param parent
 */
IfmetWindow::IfmetWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IfmetWindow)
{
    ui->setupUi(this);
}

/*!
 * \brief IfmetWindow::~IfmetWindow 我的析构函数
 */
IfmetWindow::~IfmetWindow()
{
    delete ui;
}
