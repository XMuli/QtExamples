/*
 * Copyright (C)  2019~2022  偕臧  All rights reserved.
 *
 * Author:  XMuli  xmulitech@gmail.com
 *
 * GitHub:  https://github.com/XMuli
 * Blogs:   https://ifmet.cn
 * CSDN:    https://blog.csdn.net/qq_33154343
 */
#include "tray.h"

#include <QCoreApplication>
#include <QIcon>
#include <QKeySequence>
#include "widget.h"

Tray::Tray(QObject *parent)
    : QObject(parent)
    , m_screenShot(nullptr)
    , m_quit(nullptr)
    , m_menuTary(nullptr)
    , m_sysTary(nullptr)
    , m_hkScrnShot(new QHotkey(QKeySequence("f6"), true, qApp))
{
    m_screenShot = new QAction(tr("ScreenShot"), this);
    m_quit = new QAction(tr("Quit"), this);

    m_menuTary = new QMenu();
    m_menuTary->addAction(m_screenShot);
    m_menuTary->addSeparator();
    m_menuTary->addAction(m_quit);

    m_sysTary = new QSystemTrayIcon(this);
    m_sysTary->setIcon(QIcon(":/resources/PicShot_32.svg"));
    m_sysTary->setToolTip(tr("PicShot Test"));
    m_sysTary->setContextMenu(m_menuTary);
    m_sysTary->setVisible(true);

    connect(m_hkScrnShot, &QHotkey::activated, this, &Tray::onScreenShot);

    connect(m_screenShot, &QAction::triggered, this, &Tray::onScreenShot);
    connect(m_quit, &QAction::triggered, []() {
        qApp->quit();
        });
}

void Tray::onScreenShot()
{
    auto& ins = Widget::instance();
    ins.show();

    // 解决方案: show() 之后，设置为激活窗口即可
    if(!ins.isActiveWindow())
        ins.activateWindow();
}
