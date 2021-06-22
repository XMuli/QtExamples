#include<QVariant>
#include <iostream>
using namespace std;

class C{}; //自定义类型
//Q_DECLARE_METATYPE(C)

int main()
{
    QVariant v('a'); // QVariant 没有专门的 char 构造函数，此处的字符 a 会被转换为 int 型，因此 v中存储的是数值 97，而不是字符 a 。
    cout<<v.value<int>()<<endl; //输出 97
    cout<<v.value<char>()<<endl; //输出 a，将 97 转换为 char 型，并输出转换后的值。
    cout<<v.toChar().toLatin1()<<endl; //输出 a，原因同上，注意 toChar 返回的类型是 QChar 而不是 char。
    cout<<v.toString().toStdString()<<endl; //输出 97，把存储在 v 中的值转换为 QString，然后以字符串形式输出。
    cout<<v.typeName()<<endl; //输出 int，可见存储在 v 中的值的类型为 int
    cout<<v.typeToName(v.type())<<endl; //输出 int，其中 type 返回存储值的枚举形式表示的类型，而typeToName 则以字符串形式显示该枚举值所表示的类型。

    char c='b';
    v.setValue(c);
    cout<<v.toString().toStdString()<<endl; //输出 b
    cout<<v.typeName()<<endl; //输出 char，若是使用 QVariant 构造函数和直接赋值 char 型字符，此处会输出 int，这是 setValue 与他们的区别。

    C mc; //自定义类型 C 的对象 mc
    //QVariant v1(mc); //错误，没有相应的构造函数。
    QVariant v2;
    //v2=mc; //错误，没有与类型 C 匹配的赋值运算符函数。
    //v2.setValue(mc); //错误，自定义类型 C 未使用宏 Q_DECLARE_METATYPE 声明。
    return 0;
}
