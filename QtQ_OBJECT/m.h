#ifndef M_H //要使用元对象系统，需在头文件中定义类。
#define M_H

#include<QObject> //因为要使用 QObject 类，为此需要包含此头文件
class A:public QObject{
 Q_OBJECT //启动元对象系统，必须声明此宏
public:
 //定义 2 个构造函数、1 个信号、3 个函数。
 Q_INVOKABLE A(){} //要想函数被反射，需要指定 Q_INVOKABLE 宏。
 Q_INVOKABLE A(int){}
 Q_INVOKABLE void f(){}
 Q_INVOKABLE void g(int i,float j){}
 void g1(){} //注意：此函数不会被反射。
 signals: void gb3();
};

class B:public A{
 Q_OBJECT //要使用元对象系统，应在每个类之中都声明此宏
 public:
 //定义 1 个函数、2 个信号
Q_INVOKABLE void f(){}
signals: void gb4();
    void gb5();
};

#endif // M_H

