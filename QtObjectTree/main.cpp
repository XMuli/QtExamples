//#include "widget.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    return a.exec();
//}


/****************************************************
 *  示例 1：组合模式核心代码
 *  （组合模式指的是把类的对象组织成树形结构，这种树形结构也称为对象树）
 * **************************************************/
//#include <iostream>
//#include<vector> //使用容器。
//using namespace std;

//class A
//{
//public: //顶级父类。
//    vector<A*> v; //创建一个存储父类类型指针的容器，此步也可使用形如A* m[11]的数组代替，但数组不能自动扩容。
//    void add(A* ma) { v.push_back(ma);} //add函数的主要作用是将ma添加到容器v中。
//};

//class B :public A //需要继承自类A
//{
//public:
//    void add(A* ma) { v.push_back(ma); }
//};

//class C :public A  //需要继承自类A，该类无add函数，也就是说该类的对象不能有子对象。
//{
//    public:
//};

//int main(){
//    A ma, ma1, ma2, ma3;
//    B mb, mb1, mb2, mb3;
//    C mc, mc1, mc2, mc3;

//    //创建对象树。
//    ma.add(&mb); ma.add(&mb1);
//    mb.add(&mb3); mb.add(&mc); mb.add(&mc1);
//    mb1.add(&mc2); mb1.add(&ma1); mb1.add(&ma2);
//}


/****************************************************
 *  示例 2：打印出组合模式中的各对象的名称
 * **************************************************/
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class A {
public:
    string name;
    vector<A*> v;
    A(){}
    A(string n){name=n;}
    void add(A* ma) { v.push_back(ma);}
    string g(){return name;}
    void f(){ //用于显示当前对象的容器v中存储的内容。
        if(!v.empty()) {
            cout<<name<<"=";
            for (vector<int>::size_type i = 0; i!=v.size(); i++) //遍历容器v。
            {cout<<v[i]->g()<<",";} //输出容器v中存储的对象的名称，
                cout<<endl;} }

    void pt(){ //该函数会被递归调用，用以输出整个对象树中对象的名称。
        f();
        for (vector<int>::size_type i = 0; i!=v.size(); i++)
            v[i]->pt(); }
};

class B :public A {
public:
    B(string n){name=n;}
};

class C :public A { //需要继承自类A，该类无add函数，也就是说该类的对象不能有子对象。
public:
    C(string n){name=n;}
};

int main()
{ //创建对象时传递该对象的名称以便存储。
    A ma("ma"),ma1("ma1");
    B mb("mb"),mb1("mb1"),mb2("mb2"),mb3("mb3"),mb4("mb4");
    C mc1("mc1"),mc2("mc2");

    ma.add(&mb); //ma.v[0]=&mb;
    mb.add(&mb1); //mb.v[0]=&mb1;
    mb.add(&mb2); //mb.v[1]=&mb2;
    ma.add(&mb1); //ma.v[1]=&mb1;
    mb1.add(&mb3); //mb1.v[0]=&mb3;
    mb1.add(&mb4); //mb1.v[1]=&mb4;
    mb2.add(&mc1); //mb2.v[0]=&mc1;
    mb2.add(&mc2); //mb2.v[1]=&mc2;
    mb2.add(&ma1); //mb2.v[2]=&ma1;

    cout<<"各对象拥有的子对象"<<endl;
    ma.f(); mb.f(); mb1.f(); mb2.f();
    cout<<endl<<"整个对象中结构"<<endl;
    ma.pt();

    return 0;
}

/****************************************************
 *  示例 3：示例：使用父节点对象删除子结构对象
 * **************************************************/
//#include <iostream>
//#include <string>
//#include<vector>
//using namespace std;
//class A {public:
//    vector<A*> v; //容器
//    string name; //存储对象名
//    virtual string g(){return name;} //虚函数，用于获取子对象的名称。
//    A() {}
//    A(string n) {name=n;}
//    A(A* ma,string n) {name=n; ma->v.push_back(this); }
//    virtual ~A() { //虚析构函数，原理请参阅相关C++语法
//        cout << "~A" << endl; //❶ ，输出的字符用于测试
//        if(!v.empty()){//❷
//            cout << "XXXXX" << endl; //用于测试
//            for (vector<int>::size_type i = 0; i != v.size(); i++) //❸
//            { cout << "object = " <<v[i]->g()<< endl; //❹输出的字符用于测试
//                delete v[i]; //❺
//                //v[i]->~A();
//                cout<<"YYYY"<<endl; //❻输出的字符用于测试
//            }
//        }
//        cout << "#######" << endl; } //❼输出的字符用于测试
//};

//class B :public A
//{
//public:
//    string name;
//    string g(){return name;}
//    B() {}
//    B(string n){name=n;}
//    B(A* ma,string n):A(ma,n){ name=n; }
//    ~B() { cout << "~B" << ","; } //❽输出的字符用于测试
//};

//class C :public A
//{
//public:
//    string name;
//    string g(){return name;}
//    C(A* ma,string n):A(ma,n){ name=n;}
//    ~C() { cout << "~C" <<","; } //❾输出的字符用于测试
//};

//class D :public B
//{
//public:
//    string name;
//    string g(){return name;}
//    D(A* ma,string n):B(ma,n){ name=n;}
//    ~D() { cout << "~D" <<","; } //❿输出的字符用于测试
//};

//int main()
//{
//    A ma("ma"); //B mb("mb");
//    B *pb=new B(&ma,"pb"); B *pb1=new B(&ma,"pb1");
//    B *pb2=new B(pb,"pb2"); C *pc1=new C(pb,"pc1");
//    A* pa1=new A(pb1,"pa1"); B* pb3=new B(pb1,"pb3"); C* pc2=new C(pb1,"pc2");
//    D* pd1=new D(pc1,"pd1"); D* pd2=new D(pc1,"pd2");
//}
