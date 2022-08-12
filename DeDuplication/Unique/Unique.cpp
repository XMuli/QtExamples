// Unique.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/* 对应教程
 * STL 中给 vector 去重的三种方法: https://xmuli.blog.csdn.net/article/details/126322011
 * STL 的 std::set 创建自定义结构体的对象，定义严格弱序的比较函数: https://xmuli.blog.csdn.net/article/details/126354597
*/ 

struct MyData
{
    wstring name;
    wstring md5;

    // 方式一：重载类 < 函数
    //bool operator<(const MyData& d) const noexcept {
    //    return md5 < d.md5;
    //}
};

// 方式二：对自定义结构体类型，自定义比较函数 _Pr 【本次采用的方式】
bool cmpSort(const MyData& d1, const MyData& d2) {
    // Simple example
    return d1.md5 < d2.md5;

    // Complex sample
    //if (d1.md5 != d2.md5)
    //    return d1.md5 < d2.md5;
    //else
    //    return d1.name < d2.name;
};

// 方式二变种：同二，但采用 Lambda 表达式（某些部分算法中会失效）
auto cmpSortLambda = [](const MyData& d1, const MyData& d2) {
    return d1.md5 < d2.md5;
};

// 方式三：函数对象，略。更新，本来是写了略的，结果意外此处有意外的收获
struct cmpSortObj
{
    bool operator()(const MyData& d1, const MyData& d2) const {
        return d1.md5 < d2.md5;
    }
};

// ************* std::unique 的自定义比较函数 *************
bool cmpUnique(const MyData& d1, const MyData& d2) {
    return d1.md5 == d2.md5;                             // 非严格对象相等，可以达到目标，但会内存泄漏
    //return d1.md5 == d2.md5 && d1.name == d2.name;     // 满足语法和编译，但不满足实际需求
};

int main()
{
    vector<MyData> vec = { { L"a1.exe", L"B9204B6362A65C248950D5A41F341DCC"},
                           { L"a2.exe", L"B9204B6362A65C248950D5A41F341DCC"},
                           { L"b1.exe", L"C96D1AA5D314954417C28A645ED72665"},
                           { L"b2.exe", L"C96D1AA5D314954417C28A645ED72665"} };

    wcout.imbue(locale("", LC_CTYPE));
    wcout << L"----------调整前--------" << endl;
    for (const auto& it : vec)
        wcout << L"[it.name]" << it.name << L"[it.md5]" << it.md5 << endl;

    // ************* 『一』vector, sort + unique *************
    //sort(vec.begin(), vec.end(), cmpSort);
    //auto ite = std::unique(vec.begin(), vec.end(), cmpUnique);
    //vec.erase(ite, vec.end());

    // ************* 『二』vector + set（手动赋值） *************
    //set<MyData, cmpSortObj>  s;                           // "函数对象"创建 set 对象 --> OK
    set<MyData, decltype(cmpSort)*>  s(&cmpSort);           // "定义普通函数 + decltype"创建 set 对象 -->    OK:  编译、运行成功；调试也成功
    //set<MyData, decltype(cmpSort)*>  s;                   //                                      --> Error:  编译、运行成功；调试会失败

    for (unsigned i = 0; i < vec.size(); ++i)
        s.insert(vec[i]);                                   // 编译时，本行可验证上面创建 std::set 的结果
    vec.assign(s.begin(), s.end());

    // ************* 『三』vector + set（构造函数） *************
    // 效率不如『二』，故略

    wcout << L"----------调整后--------" << endl;
    for (const auto& it : vec)
        wcout << L"[it.name]" << it.name << L"[it.md5]" << it.md5 << endl;

    return 0;
}