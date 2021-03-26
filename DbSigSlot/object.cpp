#include "object.h"
#include <cstring>

static int findSignalIndex(const char *str, const char *subStr)
{
    if (!str || !subStr || strlen(str) < strlen(subStr))
        return -1;

    int ret = strcmp(str, subStr);
    if (ret == 0)
        return ret;
    else
        return -1;

}

void Object::db_connet(Object *sender, const char *sig, Object *receiver, const char *slot)
{
    int sig_idx = findSignalIndex(sender->meta.sig_names, sig);
    int slot_idx = findSignalIndex(receiver->meta.slot_names, slot);

    if (sig_idx == -1 || slot_idx == -1) {
        cout<<"signal or slot not found!";
        return;
    } else {
        Connection c = {receiver, slot_idx};
        sender->connectionsMap.insert(pair<int, Connection>(sig_idx, c));  // connectionsMap 私有成员
    }
}

void Object::testSignal()
{
    db_emit sig1();
}

Object::Object()
{

}

Object::~Object()
{

}

// 通过 sender 的信号 idx ==> 槽函数
void MetaObject::active(Object *sender, int idx)
{
    pair<ConnectionMapIt, ConnectionMapIt> ret;
    ret = sender->connectionsMap.equal_range(idx);  // 寻找[idx,  )
    for (ConnectionMapIt it = ret.first; it != ret.second; ++it) {
        Connection c = (*it).second;
        c.recviver->metacall(idx);
    }

}
