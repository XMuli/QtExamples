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
#include "Example.h"
#include <QApplication>
#include <QStyleFactory>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //若为系统自带的QStyle，则qApp->setStyle("系统自带风格");
    //若为自定义新的QStyle，则qApp->setStyle(QStyleFactory::create("自定义风格"）)
    QStringList listStyle = QStyleFactory::keys();
    foreach(QString val, listStyle)     //打印当前系统支持的系统风格
        qDebug()<<val<<"  ";

    qApp->setStyle("chameleon");  //Windows/Fusion/...
    Example *w = new Example();
    w->resize(1000, 700);
    w->init();
    w->show();

    return a.exec();
}
