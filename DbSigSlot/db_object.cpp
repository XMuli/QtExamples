#include "object.h"

//db_object: 是由 moc 编译器 将 object.cpp 展开的内容(此处手写表示)

const char sig_names[] = "sig1()";
const char slot_names[] = "slot1()";
MetaObject Object::meta = {sig_names, slot_names};

void Object::sig1()
{
    MetaObject::active(this, 0);
}

void Object::slot1()
{
    cout << "-----------> this is slot1()";
}

// 槽的索引==> 槽函数
void Object::metacall(int idx)
{
    switch (idx) {
    case 0:
        slot1();
        break;
    default:
        break;
    }
}
