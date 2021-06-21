#include "m.h"
#include <QMetaMethod>
#include <QByteArray>
#include <iostream>

using namespace std;
int main(){
    A ma;
    B mb; //创建两个对象
 const QMetaObject *pa=ma.metaObject();
 const QMetaObject *pb=mb.metaObject();

 //以下为通过 QMetaObject 的成员函数获取的信息。
 int j=pa->methodCount(); /*返回对象 ma 中的成员函数数量，包括从父类 QObject 继承而来的 5 个
 成员函数及本对象中的 2 个成员函数(注意，不包括 g1)、1 个信号，所以
 总数为 8。*/
 cout<<j<<endl; //输出 8
 int i=pa->indexOfMethod("g(int,float)"); //获取对象 ma 中的成员函数 g 的索引号。
 cout<<i<<endl; //输出 7
 i=pa->constructorCount(); //获取对象 ma 所属类中的构造函数的数量。
 cout<<i<<endl; //输出 2
 i=pb->constructorCount(); /*获取对象 mb 所属类 B 中的构造函数的数量，因类 B 无构造函数，所以
 返回值为 0，此处也可看到，构造函数数量不包含父类的构造函数*/
 cout<<i<<endl; //输出 0。
 i=pa->indexOfConstructor("A(int)"); //获取对象 ma 所属类中的构造函数 A(int)的索引号。
 cout<<i<<endl; //输出 1。
 i=pa->indexOfSignal("gb3()"); //获取对象 ma 的信号 gb3()的索引号。
 cout<<i<<endl; //输出 5。
 i=pa->indexOfSignal("f()"); /*获取对象 ma 的信号 f()的索引号。因为成员函数 f 存在，但不是信
 号，所以返回值为-1。*/
 cout<<i<<endl; //输出-1。
 i=pb->methodOffset(); /*获取父类的成员函数数量，包括父类A及QObject中的成员函数，总共为8。
 */
 cout<<i<<endl; //输出 8，此处相当于是对象 mb 自身成员函数开始处的索引号。


 //以下为通过 QMetaMethon 的成员函数获取的信息。
 //获取对象 ma 的成员函数 g 的元数据。
 QMetaMethod m=pa->method(pa->indexOfMethod("g(int,float)"));
 QByteArray s= m.name(); //获取成员函数 g 的函数名。
 cout<<s.data()<<endl; //输出 g
 s=m.methodSignature(); //获取函数 g 的签名
 cout<<s.data()<<endl; //输出 g(int,float)
 i=m.methodType(); /*获取函数 g 的类型，此处返回的是 QMetaMethod::MethodType 中定义的枚举值，
 其中 Method=0，表示类型为成员函数*/
 cout<<i<<endl; //输出 0(表示成员函数)。
 //以下信息与函数的返回类型有关
 s=m.typeName(); //获取函数 g 的返回值的类型名
 cout<<s.data()<<endl; //输出 void
 i=m.returnType(); /*获取函数 g 返回值的类型，此处的类型是 QMetaType 中定义的枚举值，其中枚举
 值 QMetaType::void=43*/
 cout<<i<<endl; //输出 43
 //以下信息与函数的参数有关
 i=m.parameterType(1); /*获取函数 g 中索引号为 1 的参数类型，此处的类型是 QMetaType 中定义的
 枚举值，其中枚举值 QMetaType::float=38*/
 cout<<i<<endl; //输出 38
 QList<QByteArray> q=m.parameterNames(); //获取函数 g 的参数名列表
 cout<<q[0].data()<<q[1].data()<<endl; //输出 ij
 q=m.parameterTypes(); //获取函数 g 的参数类型列表。
 cout<<q[0].data()<<q[1].data()<<endl; //输出 intfloat
 return 0;
}
