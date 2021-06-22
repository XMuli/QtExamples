#include "m.h"
#include <QMetaMethod>
#include <iostream>
using namespace std;

//使用反射机制获取与类相关的信息
//   1、QMetaObject 类中获取与类相关的信息的成员函数有
// const char* className() const;
//   获取类的名称，注意，若某个 QObject 的子类未启动元对象系统(即未使用 Q_OBJECT
//   宏)，则该函数将获取与该类最接近的启动了元对象系统的父类的名称，而不再返回
//   该类的名称，因此建议所有的 QObject 子类都使用 Q_OBJECT 宏。

// const QMetaObject* superClass() const;
//   //返回父类的元对象，若没有这样的对象则返回 0。  bool inherits(const QMetaObject* mo) const; (Qt5.7)
//   //若该类继承自 mo 描述的类型，则返回 true，否则返回 false。类被认为继承自身。

//   2、QObject 类中获取与类相关的信息的成员函数有
// bool inherits(const char* className) const;
//   //若该类是className 指定的类的子类则返回true，否则返回false。类被认为继承自身。

int main(){
    A ma;
    B mb;
    C mc;
    D md;

    const QMetaObject *pa=ma.metaObject();
    const QMetaObject *pb=mb.metaObject();

    cout<<pa->className()<<endl; //输出类名 A
    //使用 QMetaObject::inherits()函数判断继承关系。
    cout<<pa->inherits(pa)<<endl; //输出 1，类被认为是自身的子类
    cout<<pa->inherits(pb)<<endl; //输出 0，由 pb 所描述的类 B 不是类 A 的子类。
    cout<<pb->inherits(pa)<<endl; //输出 1，由 pa 所描述的类 A 是类 B 的子类。

    //使用 QObject::inherits()函数判断继承关系。
    cout<<ma.inherits("B")<<endl; //输出 0，类 A 不是类 B 的子类。
    cout<<ma.inherits("A")<<endl; //输出 1，类被认为是自身的子类
    cout<<md.inherits("D")<<endl; //输出 0，因为类 D 未启动元对象系统。
    cout<<md.inherits("C")<<endl; //输出 1，虽然类 D 未启动元对象系统，但类 C 已启动，此种情形下能正确判断继承关系.


    //输出 C，此处未输出 D，因为类 D 未启动元对象系统，与类 D 最接近的启动了元对象系统的父类是 C，因此返回 C。
    cout<<md.metaObject()->className()<<endl;

    return 0;
}
