/*
 * Copyright (C)  2019~2022  偕臧  All rights reserved.
 *
 * Author:  XMuli  xmulitech@gmail.com
 *
 * GitHub:  https://github.com/XMuli
 * Blogs:   https://ifmet.cn
 * CSDN:    https://blog.csdn.net/qq_33154343
 */
#include "widget.h"

#include <QApplication>
#include "tray.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Tray* tary = new Tray();
    QApplication::setQuitOnLastWindowClosed(false);

    return a.exec();
}
