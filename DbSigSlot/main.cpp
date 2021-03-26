#include <iostream>
#include "object.h"
using namespace std;

// 目的：自行构造 moc 编译器，手动将 object.h --> db_bject.cpp (宏 和 moc 编译器处理的部分)
// 时间：2021-003-26
// 作者：偕臧  ifmet.cn
// 下载：https://github.com/xmuli/QtExamples
// 参考：https://blog.csdn.net/perfectguyipeng/article/details/78082360

int main(int argc, char *argv[])
{
    Object *obj1 = new Object();
    Object *obj2 = new Object();

    Object::db_connet(obj1, "sig1()", obj2, "slot1()");
    obj1->testSignal();
    return 0;
}
