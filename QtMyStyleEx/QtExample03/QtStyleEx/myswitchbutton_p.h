#ifndef MYSWITCHBUTTON_P_H
#define MYSWITCHBUTTON_P_H

#include <private/qobject_p.h>
/*!
 * \~chinese \class MySwitchButtonPrivate
 * \~chinese \brief MySwitchButton 类的数据类， 便于实现源码/二进制兼容, 通常继承于 “自定义_Private” 的类
 *                  若是自定义控件,没有继承于 QObjectPrivate 之类的, 使用 Q_Q Q_D 时候，会报错，需要自己定义 q_fun() 函数
 * \~chinese \sa Qt 自带的 QPushButtonPrivate， QPushButton 实现
 */

class MySwitchButtonPrivate : public QObjectPrivate
{
public:
    explicit MySwitchButtonPrivate();
    ~MySwitchButtonPrivate();

    void init();

public:
    bool checked;
    double animationStart;
    double animationEnd;

public:
    Q_DECLARE_PUBLIC(MySwitchButton)  //要加上宏
};

#endif // MYSWITCHBUTTON_P_H
