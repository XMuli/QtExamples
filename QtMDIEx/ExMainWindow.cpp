/*
 * Copyright (C)  2019 ~ 2019 touwoyimuli.  All rights reserved.
 *
 * Author:  touwoyimuli <touwoyimuli@gmai.com>
 *
 * github:  https://github.com/touwoyimuli
 * blogs:   https://touwoyimuli.github.io/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://touwoyimuli.github.io/>.
 */
#include "ExMainWindow.h"
#include "ui_ExMainWindow.h"

ExMainWindow::ExMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExMainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
    setWindowState(Qt::WindowMaximized);
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

ExMainWindow::~ExMainWindow()
{
    delete ui;
}

void ExMainWindow::closeEvent(QCloseEvent *e)
{
    ui->mdiArea->closeAllSubWindows();  //关闭所有子窗口
    e->accept();
}

void ExMainWindow::on_actOpen_triggered()
{
    bool needNew = false;

    ExMDI *mdi = nullptr;

    if (ui->mdiArea->subWindowList().count() > 0) {  //如果有打开的主窗口，获取活动窗口
        mdi =  (ExMDI *)ui->mdiArea->activeSubWindow()->widget();
        needNew = mdi->isFileOpended();   //文件已经打开，需要新建窗口
    } else {
        needNew = true;
    }

    QString curPath = QDir::currentPath();
    QString fileName = QFileDialog::getOpenFileName(this, "打开一个文件", curPath, "C程序文件(*.h *cpp);;文本文件(*.txt);;所有文件(*.*)");

    if (fileName.isEmpty())
        return;

    if (needNew) {
        mdi = new ExMDI(this);
        ui->mdiArea->addSubWindow(mdi);
    }

    mdi->loadFromFile(fileName);
    mdi->show();

    ui->actCopy->setEnabled(true);
    ui->actCut->setEnabled(true);
    ui->actPaste->setEnabled(true);
    ui->actFont->setEnabled(true);
}

void ExMainWindow::on_actQuit_triggered()
{
    close();
}

void ExMainWindow::on_actNew_triggered()
{
    ExMDI *mdi = new ExMDI(this);
    ui->mdiArea->addSubWindow(mdi);   //添加一个子窗口MDI
    mdi->show();

    ui->actCopy->setEnabled(true);
    ui->actCut->setEnabled(true);
    ui->actPaste->setEnabled(true);
    ui->actFont->setEnabled(true);
}

void ExMainWindow::on_actFont_triggered()
{
     ExMDI* mdi = (ExMDI *)ui->mdiArea->activeSubWindow()->widget();
     mdi->setEditFont();  //设置编写的字体文档
}

void ExMainWindow::on_actCut_triggered()
{
    ExMDI* mdi = (ExMDI *)ui->mdiArea->activeSubWindow()->widget();
    mdi->textCut();
}

void ExMainWindow::on_actCopy_triggered()
{
    ExMDI* mdi = (ExMDI *)ui->mdiArea->activeSubWindow()->widget();
    mdi->textCopy();
}

void ExMainWindow::on_actPaste_triggered()
{
    ExMDI* mdi = (ExMDI *)ui->mdiArea->activeSubWindow()->widget();
    mdi->textPaste();
}

void ExMainWindow::on_actView_triggered(bool checked)   //MDI 模式设置
{
    if (checked) {  //Tab多页显示模式
        ui->mdiArea->setViewMode(QMdiArea::TabbedView);
        ui->mdiArea->setTabsClosable(true);  //页面可以关闭
        ui->actCascade->setEnabled(false);
        ui->actTile->setEnabled(false);
    } else {
        ui->mdiArea->setViewMode(QMdiArea::SubWindowView);  //子窗口模式
        ui->actCascade->setEnabled(true);
        ui->actTile->setEnabled(true);
    }

}

void ExMainWindow::on_actCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows();   //窗口级联展开
}

void ExMainWindow::on_actTile_triggered()
{
    ui->mdiArea->tileSubWindows();  //平铺展开
}

void ExMainWindow::on_actClose_triggered()
{
    ui->mdiArea->closeAllSubWindows();  //关闭全部子窗口
}
