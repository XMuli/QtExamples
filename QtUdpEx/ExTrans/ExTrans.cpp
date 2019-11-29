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
#include "ExTrans.h"
#include "ui_ExTrans.h"

ExTrans::ExTrans(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExTrans)
{
    ui->setupUi(this);
    setWindowTitle("Tcp通信：unicast(单播) + broadcast(广播)的使用");
}

ExTrans::~ExTrans()
{
    delete ui;
}

void ExTrans::on_actBind_triggered()
{

}

void ExTrans::on_actDisbind_triggered()
{

}

void ExTrans::on_actClean_triggered()
{

}

void ExTrans::on_actQuit_triggered()
{
    close();
}
