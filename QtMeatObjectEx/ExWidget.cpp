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
#include "ExWidget.h"
#include "ui_ExWidget.h"
#include <QMetaProperty>
#include <QDebug>

ExWidget::ExWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ExWidget)
{
    ui->setupUi(this);

    m_boy = new ExPerson("张三");
    m_boy->setProperty("score", 90);
    m_boy->setProperty("age", 20);
    m_boy->setProperty("sex", "Boy");           //动态属性
    connect(m_boy, &ExPerson::ageChanged, this, &ExWidget::onAgeChange);

    m_girl = new ExPerson("张丽");
    m_girl->setProperty("score", 80);
    m_girl->setProperty("age", 10);
    m_girl->setProperty("sex", "Gril");         //动态属性
    connect(m_girl, &ExPerson::ageChanged, this, &ExWidget::onAgeChange);

    ui->spinBoy->setProperty("isBoy", true);    //动态属性
    ui->spinGril->setProperty("isBoy", false);

    connect(ui->spinGril, SIGNAL(valueChanged(int)), this, SLOT(onSpinValChange(int)));
    connect(ui->spinBoy,  SIGNAL(valueChanged(int)), this, SLOT(onSpinValChange(int)));

    connect(ui->btnBoyAdd, SIGNAL(clicked()), this, SLOT(onBtnBoyInc()));
    connect(ui->btnGrilAdd, SIGNAL(clicked()), this, SLOT(onBtnGrilInc()));
    connect(ui->btnMetaObject, SIGNAL(clicked()), this, SLOT(onClassInfo()));
    connect(ui->btnClean, SIGNAL(clicked()), this, SLOT(onBtnClear()));

    setWindowTitle(QObject::tr("元对象MetaObject和(含动态)属性Propert的用法"));
}

ExWidget::~ExWidget()
{
    delete ui;
}

void ExWidget::onAgeChange(int val)
{
    Q_UNUSED(val)   //参数val没使用，避免警告

    ExPerson* person = qobject_cast<ExPerson *>(sender());    //类型投射
    QString name = person->property("name").toString();
    QString sex = person->property("sex").toString();
    int age  = person->getAge();                             //通过接口函数，获得年龄
                                                             //或使用 int age  = person->property("age").toInt();
    ui->textEdit->appendPlainText(name+","+sex + QString::asprintf(",年龄=%d",age));
}

void ExWidget::onSpinValChange(int val)
{
    Q_UNUSED(val)

    QSpinBox* spin = qobject_cast<QSpinBox *>(sender());     //类型投射
    if (spin->property("isBoy").toBool())
        m_boy->setAge(ui->spinBoy->value());
    else
        m_girl->setAge(ui->spinGril->value());
}

void ExWidget::onBtnClear()
{
    ui->textEdit->clear();
}

void ExWidget::onBtnBoyInc()
{
    m_boy->incAge();
}

void ExWidget::onBtnGrilInc()
{
    m_girl->incAge();
}

void ExWidget::onClassInfo()
{
    const QMetaObject* meta = m_boy->metaObject();

    ui->textEdit->clear();
    ui->textEdit->appendPlainText("==元对象信息(Meta Object)===");
    ui->textEdit->appendPlainText(QString("类名称: %1\n").arg(meta->className()));
    ui->textEdit->appendPlainText("属性(property)");

    for (int i = meta->propertyOffset(); i < meta->propertyCount(); i++)
    {
        QMetaProperty prop = meta->property(i);
        const char* propName = prop.name();
        QString propValue = m_boy->property(propName).toString();
        ui->textEdit->appendPlainText(QString("属性名称=%1， 属性值= %2").arg(propName).arg(propValue));
    }

    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("classInfo:");
    for (int i = meta->classInfoOffset(); i < meta->classInfoCount(); i++)
    {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->textEdit->appendPlainText(QString("Name=%1， Value= %2").arg(classInfo.name()).arg(classInfo.value()));
    }

}


