#ifndef M_H //要使用元对象系统，需在头文件中定义类。
#define M_H

#include<QObject>

class B{public:int i;};
class C{public:int i;};
class D{public:int i;};
Q_DECLARE_METATYPE(B)
Q_DECLARE_METATYPE(C)
//Q_DECLARE_METATYPE(D)

class Z:public QObject{ Q_OBJECT
public: Z(){}
    Q_PROPERTY(B b READ fb WRITE gb)
    Q_PROPERTY(C c READ fc WRITE gc)
    Q_PROPERTY(D d READ fd WRITE gd)
    B fb(){return m_mb;} void gb(B x){m_mb=x;}
    C fc(){return m_mc;} void gc(C x){m_mc=x;}
    D fd(){return m_md;} void gd(D x){m_md=x;}
    B m_mb; C m_mc; D m_md;
};

#endif // M_H
