/*
 *
 * Gmail:   touwoyimuli@gmai.com
 * blogs:   https://blog.csdn.net/qq_33154343
 *
 * -------------------------------------------------
 * Copyright 2019~2020 touwoyimuli
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
    bool setSwitchCheck(bool check);
    bool switchCheck();

private:
    bool check;

public:
    Q_DECLARE_PUBLIC(MySwitchButton)  //要加上宏
};

#endif // MYSWITCHBUTTON_P_H
