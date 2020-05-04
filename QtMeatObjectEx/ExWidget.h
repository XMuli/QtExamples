/*
  * Copyright 2019 xmulitech@gmail.com
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
#ifndef EXWIDGET_H
#define EXWIDGET_H

#include <QWidget>
#include "ExPerson.h"

namespace Ui {
class ExWidget;
}

class ExWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExWidget(QWidget *parent = nullptr);
    ~ExWidget();

private slots:
    void onAgeChange(int val);       //自定义的槽函数
    void onSpinValChange(int val);

    void onBtnClear();               //UI界面的槽函数
    void onBtnBoyInc();
    void onBtnGrilInc();
    void onClassInfo();

private:
    Ui::ExWidget *ui;

    ExPerson* m_boy;
    ExPerson* m_girl;
};

#endif // EXWIDGET_H
