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
#ifndef EXMAINWINDOW_H
#define EXMAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QDir>
#include <QFileDialog>
#include <QMdiSubWindow>

#include "ExMDI.h"

namespace Ui {
class ExMainWindow;
}

class ExMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExMainWindow(QWidget *parent = nullptr);
    ~ExMainWindow();

private slots:
    void on_actOpen_triggered();   //打开文档
    void on_actQuit_triggered();   //退出程序
    void on_actNew_triggered();    //新建MDI的子窗口
    void on_actFont_triggered();   //设置字体
    void on_actCut_triggered();    //剪切文本
    void on_actCopy_triggered();   //复制文本
    void on_actPaste_triggered();  //粘贴文本
    void on_actView_triggered(bool checked);  //MDI显示： Table 和 子窗口页面显示
    void on_actCascade_triggered();//级联显示
    void on_actTile_triggered();   //平铺显示
    void on_actClose_triggered();  //关闭所有子窗口

private:
    void closeEvent(QCloseEvent *e);   //主窗口关闭时关闭所有子窗口

private:
    Ui::ExMainWindow *ui;
};

#endif // EXMAINWINDOW_H
