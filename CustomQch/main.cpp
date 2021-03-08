#include "ifmetwindow.h"
#include <QApplication>

/*
 * Copyright (C)  2021  偕臧  All rights reserved.
 *
 * Author:  偕臧
 * github:  https://github.com/xmuli
 * blogs:   https://ifmet.cn
 *
 * 一个自定义 Qt Assistants 的文档例子，写于 2021-03-08
 */

/*!
 * \brief main 所有函数的入口
 * \param argc 参数个数
 * \param argv 参数地址（二维）
 * \return 程序运行状态
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IfmetWindow w;
    w.show();

    return a.exec();
}
