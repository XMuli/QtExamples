#include <iostream>
#include <QVector>
using namespace std;


class A
{
public:

    void add(A *pt){ m_v.push_back(pt); }

    QVector<A *> m_v;
    QString m_name;
};

class B : public A
{
public:
    void add(A *pt){ m_v.push_back(pt); }
};


class C : public A
{
public:
};

int main(int argc, char *argv[])
{
    A ma1;
    B mb1, mb2, mb3, mb4;
    C mc1, mc2, mc3;

    ma1.add(&mb1); ma1.add(&mb3);
    mb1.add(&mc1); mb1.add(&mb2);
    mb3.add(&mc2); mb3.add(&mc3); mb3.add(&mb4);

    return 0;
}
