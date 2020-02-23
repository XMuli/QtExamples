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

#ifndef MYSWITCHBUTTON_H
#define MYSWITCHBUTTON_H

#include <QAbstractButton>
#include <QStyleOption>
class QStyleOptionButton;

class MySwitchButtonPrivate;
class MySwitchButton : public QAbstractButton//bianxinagjicengle QObject
{
    Q_OBJECT
public:
    explicit MySwitchButton(QWidget* parent = nullptr);
    ~MySwitchButton();

    // QWidget interface
public:
    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    void initStyleOption(QStyleOptionButton *opt) const;

    Q_DECLARE_PRIVATE(MySwitchButton)
};

#endif // MYSWITCHBUTTON_H
