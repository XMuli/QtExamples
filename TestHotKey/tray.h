/*
 * Copyright (C)  2019~2022  偕臧  All rights reserved.
 *
 * Author:  XMuli  xmulitech@gmail.com
 *
 * GitHub:  https://github.com/XMuli
 * Blog:    https://ifmet.cn
 * CSDN:    https://blog.csdn.net/qq_33154343
 */
#ifndef TRAY_H
#define TRAY_H

#include <QAction>
#include <QMenu>
#include <QObject>
#include <QSystemTrayIcon>
#include <QHotkey>

class Tray : public QObject
{
    Q_OBJECT
public:
    explicit Tray(QObject *parent = nullptr);

public slots:
    void onScreenShot();

private:
    QAction* m_screenShot;
    QAction* m_quit;
    QMenu* m_menuTary;
    QSystemTrayIcon* m_sysTary;

    QHotkey* m_hkScrnShot;  // 热键
};

#endif // TRAY_H
