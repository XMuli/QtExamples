#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMetaMethod>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("信号和槽：Qt4 与 Qt5 用法"));
    ui->pushButton->setText(tr("关闭窗口"));

    // Qt4 方式
//    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(closeWindow()));  // 式1
//    connect(ui->pushButton, SIGNAL(clicked()), SLOT(closeWindow()));  // 式2

    // Qt5 方式
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::closeWindow);  // 式3
//    connect(ui->pushButton, &QPushButton::clicked, [=](){  // 式4
//        close();
//    });
//    connect(ui->pushButton, ui->pushButton->metaObject()->method(34), this, this->metaObject()->method(25));  // 式5



//    for (int var = 0; var < metaObject()->methodCount(); ++var) {
//        QMetaMethod qm1 = ui->pushButton->metaObject()->method(var);
//        QMetaMethod qm2 = this->metaObject()->method(var);
//        qDebug()<<qm1.name() << qm2.name() << var <<"\n";
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeWindow()
{
    close();
}

