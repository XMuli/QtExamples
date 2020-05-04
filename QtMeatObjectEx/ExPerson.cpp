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
#include "ExPerson.h"

//加一个参后的构造函数
ExPerson::ExPerson(QString name, QObject *parent) : QObject(parent)
{
    m_name = name;
}

int ExPerson::getAge()
{
    return m_age;
}

void ExPerson::setAge(int value)
{
    m_age = value;
    emit ageChanged(m_age);  //发射信号
}

void ExPerson::incAge()
{
    m_age++;
    emit ageChanged(m_age);  //发射信号
}





