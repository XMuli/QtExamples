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
#include "ExMDI.h"
#include "ui_ExMDI.h"

ExMDI::ExMDI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExMDI)
{
    ui->setupUi(this);

    setWindowTitle("多文档界面MDI (Multi-dociment Interface) 的介绍和使用");
    setAttribute(Qt::WA_DeleteOnClose);  //无论是否设置关闭时候删除；在MDI中关闭一个MDI子窗口都会删除子窗口对象
    this->setWindowIcon(QIcon("/Users/yuanyi/picture/发布、头像、测试图片/icon.png"));
}

ExMDI::~ExMDI()
{
    delete ui;
}

//打开文件
void ExMDI::loadFromFile(QString &fileName)
{
    QFile file(fileName);  //文件以读的方式读出

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);  //以文本流方式读取文件
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(stream.readAll());
        file.close();

        m_currentFile = fileName;
        QFileInfo fileInfo(fileName);    //文件信息
        setWindowTitle(fileInfo.fileName());
        m_fileOpened = true;
    }
}

QString ExMDI::currentFileName()
{
    return m_currentFile;
}

bool ExMDI::isFileOpended()
{
    return m_fileOpened;
}

void ExMDI::setEditFont()
{
    QFont font = ui->plainTextEdit->font();
    bool ok;
    font = QFontDialog::getFont(&ok, font);
    ui->plainTextEdit->setFont(font);

}

void ExMDI::textCut()
{
    ui->plainTextEdit->cut();
}

void ExMDI::textCopy()
{
    ui->plainTextEdit->copy();
}

void ExMDI::textPaste()
{
    ui->plainTextEdit->paste();
}
