#ifndef M_H //要使用元对象系统，需在头文件中定义类。
#define M_H

#include<QObject>
#include <iostream>
using namespace std;

class Z:public QObject{
    Q_OBJECT
public:
    Q_PROPERTY(int b READ gb WRITE sb)
    int gb(){return m_mb;}
    void sb(int x){m_mb=x;}
    int m_mb;
};
#endif // M_H
