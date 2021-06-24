// 示例：动态属性及使用 property 和 setProperty 存取属性值。
#include "m.h"
#include<QVariant>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]){
    // 注册类型,此处没有体现这两个函数的作用，屏蔽之后依旧可运行
    // 若需要在队列中的信号和槽连接中，或 QObject 的属性系统中使用该类型，则还
    // 必须调用 qRegsiterMetaType 函数注册该类型，因为这些情况是动态运行的。
    // qRegisterMetaType<B>();
    // qRegisterMetaType<C>();

    B mb;
    C mc;
    D md;
    Z mz;

    mb.i=2;
    mc.i=3;
    md.i=4;

    mz.gb(mb);
    mz.gc(mc);
    mz.gd(md);
    //使用 porperty 和 setProperty 存取属性值。
    //mz.property("d"); //错误，不能使用 property 函数访问属性 d，因为属性 d 的类型 D 未注册。
    mz.property("MMM"); //这是正确的，因为属性 MMM 不存在，所以，返回的是一个空的 QVariant 对象，可见，属性不存在与属性的类型未注册是不同的。
    cout<<mz.fd().i<<endl; //输出 4。虽然不能使用 property 函数访问属性 d，但仍可使用存取函数访问该属性的值。
    cout<<mz.property("b").value<B>().i<<"  "<<mz.property("c").value<C>().i<<"  "<<endl;
    //cout<<mz.property("D").value<D>().i<<endl;  // D 没有申明，  Q_DECLARE_METATYPE(D)

    QVariant v;
    B mb1;
    mb1.i=6;
    v.setValue(mb1);
    //mz.setProperty("b",mb1); //错误，第二个参数的类型不匹配。
    mz.setProperty("b",v); //正确设置属性 b 的值的方法，把属性 b 的值设置为 v 中存储的值 mb1。
    mz.setProperty("c",v); //正确，但是属性 c 的类型与 v 中存储的值的类型不兼容，因此属性 c 不会被更改
    mz.setProperty("c",7); //原因同上。
    cout<<mz.property("b").typeName()<<endl; //输出 B，输出属性 b 的类型
    cout<<mz.property("c").typeName()<<endl; //输出 C，输出属性 c 的类型
    cout<<mz.property("b").value<B>().i<<endl; //输出 6。输出的是 mb1.i 的值。
    cout<<mz.property("c").value<C>().i<<endl; //输出 3，属性 c 的值并未被更改。

    //动态属性
    mc.i=7;
    v.setValue(mc);
    // mz.setProperty("w",mc); //错误，第二个参数的类型不匹配。
    mz.setProperty("x",v); //动态属性，新增加属性 x，并设置其值为 v 中存储的值(即 mc)
    cout<<mz.property("x").typeName()<<endl; //输出 C，即动态属性 x 的类型。
    cout<<mz.property("x").value<C>().i<<endl; //输出 7。

    Z mz1;
    //cout<<mz1.property("x").typeName()<<endl; //错误，动态属性 x 是基于对象 mz 的。
    cout<<mz1.property("b").typeName()<<endl; //输出 B，属性 b 不是动态属性。
    return 0; }
