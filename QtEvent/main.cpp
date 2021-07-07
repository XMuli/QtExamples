//#include <QApplication>
//#include<QWidget>
//#include<QObject>
//#include <iostream>
//using namespace std;

//QEvent::Type t1=(QEvent::Type)1333;
//QEvent e(t1); //使用 QEvent 的构造函数在堆栈上创建自定义事件

//class E:public QEvent
//{public: //子类化 QEvent 以创建自定义事件
//    //方式 1：使用静态成员。
//    //使用静态成员主要是为了正确初始化父类部分 QEvent，比如
//    //E():t2((QEvent::Type)1324),QEvent(t2){}，若 t2 不是静态的，则则初始化之后 t2 为 1324，但传递
//    //给 QEvent 的 t2 是一个不确定的值，因为按照 C++规则，对父类部分的初始化先于数据成员的初始化。
//    static QEvent::Type t2; //注意：不要使用名称 t，因为 QEvent 类之中有一个名称为 t 的成员变量。
//    E():QEvent(t2){}
//    //方式 2：使用带一个参数的构造函数
//    QEvent::Type t3;
//    explicit E(QEvent::Type t4):t3(t4),QEvent(t4){}
//};

//QEvent::Type E::t2=(QEvent::Type)1334;

//class A:public QWidget
//{public:
//    bool event(QEvent* e){ //重写 event 函数以处理自定义事件
//        if(e->type()==t1) //判断事件类型是否为 t1
//        {cout<<"AE"<<e->type()<<",";
//            f1((E*)e); //调用自定义的处理函数处理该事件
//            return 1; }
//        if(e->type()==E::t2) {cout<<"BE"<<e->type()<<","; f2((QEvent*)e); return 1; }
//        if(e->type()==((E*)e)->t3){cout<<"CE"<<e->type()<<","; f3((E*)e); return 1;}
//        return QWidget::event(e);
//    } //event 结束
//    //以下为处理自定义事件的事件处理函数
//    void f1(E *e){cout<<"F1"<<endl;}
//    void f2(QEvent *e){cout<<"F2"<<endl;}
//    void f3(E *e){cout<<"F3"<<endl;}
//}; //类 A 结束。

//int main(int argc, char *argv[])
//{ QApplication aa(argc,argv);
//    A ma; E me; E *pe=new E((QEvent::Type)1335);
//    //发布或发送事件
//    aa.sendEvent(&ma,&e); aa.sendEvent(&ma,&me); aa.postEvent(&ma,pe);
//    //aa.postEvent(&ma,&me); //错误，发布的事件 me 必须是在堆上创建的。
//    ma.resize(333,222);
//    ma.show(); aa.exec(); return 0;
//}



//---------------------------------------------------------------------------------------------------------
//示例：使用事件过滤器处理自定义事件
#include <QApplication>
#include<QWidget>
#include<QObject>
#include <iostream>
using namespace std;
QEvent::Type t1=(QEvent::Type)QEvent::registerEventType(1333);
QEvent e1(t1); //使用 QEvent 的构造函数创建自定义事件
//t2 的值与 t1 重复，使用 registerEventType 会自动产生一个合法的值
QEvent::Type t2=(QEvent::Type)QEvent::registerEventType(1333);
QEvent e2(t2);
class A:public QWidget{public:
    bool event(QEvent* e){
        if(e->type()==t1) {
            cout<<"AE"<<e->type()<<",";
            f1((QEvent*)e);
            return 1;
        }

        if(e->type()==t2) {
            cout<<"BE"<<e->type()<<",";
            f2((QEvent*)e);
            return 1;
        }

        return QWidget::event(e);
    } //event 结束

    void f1(QEvent *e){cout<<"F1"<<endl;}
    void f2(QEvent *e){cout<<"F2"<<endl;}
};
class B:public QObject{public:
    bool eventFilter(QObject *w, QEvent *e){
        if(e->type()==t1){
            cout<<"A"<<endl;
            return 1;
        }

        if(e->type()==t2){
            cout<<"B"<<endl;
            return 0;
        }
        return 0;}
};
int main(int argc, char *argv[]){ QApplication aa(argc,argv);
    A ma; B mb;
    ma.installEventFilter(&mb); //安装事件过滤器
    aa.sendEvent(&ma,&e1);
    aa.sendEvent(&ma,&e2);
    ma.resize(333,222);
    ma.show();
    aa.exec();
    return 0; }
