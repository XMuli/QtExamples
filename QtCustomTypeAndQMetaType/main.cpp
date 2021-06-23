#include<QVariant>
#include <iostream>
using namespace std;

class A{public: int i;};
class B{public:int i;};
class D{public:D(int){}};//该类无 public 默认构造函数
class E{};
//class F{private: ~F(){};};  写露了
//声明类型
Q_DECLARE_METATYPE(A)
Q_DECLARE_METATYPE(B)
//Q_DECLARE_METATYPE(D) //错误，类 D 没有公有的默认构造函数

int main(int argc, char *argv[]){
    //注册类型
    qRegisterMetaType<B>();
    //qRegisterMetaType<E>(); //错误，类型 E 未使用宏 Q_DECLARE_METATYPE(T)声明
    A ma; ma.i=1;
    B mb; mb.i=2;
    //QVariant v1(ma); //错误，没有相应的构造函数。
    QVariant v;
    v.setValue(ma); //将对象 ma 存储在 v 之中
    cout<<v.value<A>().i<<endl; //输出 1。
    cout<<v.typeName()<<endl; //输出 A
    cout<<v.toString().toStdString()<<endl; //输出一个空字符，因为 ma 是一个对象，不是一个值。

    //自定义类型需要使用 userType 才能返回正确的类型 ID。
    cout<<v.typeToName(v.userType())<<endl; //输出 A
    cout<<v.typeToName(v.type())<<endl; //不一定输出 A。

    A ma1;
    ma1=v.value<A>(); //把存储在 v 之中的对象 ma 赋值给 ma1
    cout<<ma1.i<<endl; //输出 1，可见赋值成功。
    B mb1;
    //mb1=v.value<A>(); //错误，类型不相同。
    mb1=v.value<B>(); //正确，由类型 A 转换到类型 B 失败，此时 value 会返回一个默认构造的值。
    cout<<mb1.i<<endl; //输出 0。
    return 0;
}
