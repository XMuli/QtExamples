// 使用反射机制获取属性的信息
// 使用 QMetaObject 成员函数存取属性值

#include "m.h"
#include<QMetaProperty>
int main(int argc, char *argv[])
{
    Z mz;
    const QMetaObject *p = mz.metaObject();
    QMetaProperty pe = p->property(p->indexOfProperty("b"));

    cout << pe.name()<< endl;
    cout << pe.typeName()<< endl;
    pe.write(&mz, 14);
    cout << pe.read(&mz).value<int>()<<endl;  // pe 是主题，是一个具体的属性，类型为 int

    return 0;
}
