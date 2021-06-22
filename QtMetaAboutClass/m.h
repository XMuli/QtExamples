#ifndef M_H
#define M_H

#include<QObject>
class A:public QObject{ Q_OBJECT};
class B:public A{ Q_OBJECT};
class C:public QObject{Q_OBJECT};
class D:public C{};

#endif // M_H
