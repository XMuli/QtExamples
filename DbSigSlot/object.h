#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <map>
using namespace std;

#define db_signals protected
#define db_slots
#define db_emit

class Object;
struct MetaObject          // 元对象
{
    const char *sig_names;
    const char *slot_names;

    static void active(Object *sender, int idx);
};

struct Connection
{
    Object *recviver;
    int method;
};

typedef multimap<int, Connection> ConnectionMap;
typedef multimap<int, Connection>::iterator ConnectionMapIt;

class Object
{
    static MetaObject meta;
    void metacall(int idx);

public:
    static void db_connet(Object *sender, const char *sig, Object *receiver, const char *slot);
    void testSignal();

public:
    Object();
    virtual ~Object();

db_signals:
    void sig1();
//    void sig2();

public db_slots:
    void slot1();
//    void slot2();

friend class MetaObject;
private:
    ConnectionMap connectionsMap;
};

#endif // OBJECT_H
