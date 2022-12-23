/*******************************************************************
 * Copyright (c) 2022~2023 XMuli  All rights reserved.
 * GitHub: https://github.com/XMuli
 * Description: 观察者模式 Observer Pattern
 * Reference: 情景 → Subject 发送一个消息，然后所有的 Observer A、B、C 
 *            都有收到，并且对相同的消息，做出各自不同的操作响应
 * See: https://www.cnblogs.com/suzhou/p/dp16obsvr.html
 ******************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Observer {  // 观察者
public: 
    virtual void update(string msg) = 0;
    virtual void doSomeThing() = 0;

protected:
    string m_msg;
};

class Subject {
public:
    Subject() = default;
    virtual ~Subject() = default;
    virtual void addObsvr(Observer* obj) = 0;
    virtual void removeObsvr(Observer* obj) = 0;
    virtual void notify(string msg) = 0;
};

//---------------------------------------------------------
class ConcreteSubject: public Subject {
public:
    ConcreteSubject() {};
    virtual ~ConcreteSubject() { m_obsvrs.clear(); }
    virtual void addObsvr(Observer* obj) override {
        m_obsvrs.push_back(obj);
    }
    virtual void removeObsvr(Observer* obj) override {
        m_obsvrs.remove(obj);
    }
    virtual void notify(string msg) override {
        for (const auto& it : m_obsvrs)
            it->update(msg);

        for (const auto& it : m_obsvrs)
            it->doSomeThing();

        cout << endl;
    }

private:
    list<Observer*> m_obsvrs;
};

class AObserver : public Observer {
public:
    void update(string msg) override { m_msg = msg; }
    virtual void doSomeThing() override { cout << "AObserver: 对 " << m_msg << " 进行 A 的操作" << endl; }
};

class BObserver : public Observer {
public:
    void update(string msg) override { m_msg = msg; }
    virtual void doSomeThing() override { cout << "BObserver: 对 " << m_msg << " 进行 B 的操作" << endl; }
};

class CObserver : public Observer {
public:
    void update(string msg) override { m_msg = msg; }
    virtual void doSomeThing() override { cout << "CObserver: 对 " << m_msg << " 进行 C 的操作" << endl; }
};

int main() 
{
    AObserver* a = new AObserver();
    BObserver* b = new BObserver();
    CObserver* c = new CObserver();
    ConcreteSubject* concreSubject = new ConcreteSubject();

    concreSubject->addObsvr(a);
    concreSubject->addObsvr(b);
    concreSubject->addObsvr(c);
    concreSubject->notify("messagebox 1");

    concreSubject->removeObsvr(c);
    concreSubject->notify("messagebox 2");

    //a->doSomeThing();
    //b->doSomeThing();
    //c->doSomeThing();
    return 0;
}


/*****************************打印结果*******************************
AObserver: 对 messagebox 1 进行 A 的操作
BObserver: 对 messagebox 1 进行 B 的操作
CObserver: 对 messagebox 1 进行 C 的操作

AObserver: 对 messagebox 2 进行 A 的操作
BObserver: 对 messagebox 2 进行 B 的操作
 ******************************************************************/
