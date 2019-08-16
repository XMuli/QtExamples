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





