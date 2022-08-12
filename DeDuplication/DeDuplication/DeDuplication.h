#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct MyData
{
    wstring name;
    wstring md5;
};

class DeDuplication
{
private:
    static bool cmpSort(const MyData& d1, const MyData& d2) {  // 注意，必须是静态
        // Simple example
        return d1.md5 < d2.md5;

        // Complex sample
        //if (d1.md5 != d2.md5)
        //    return d1.md5 < d2.md5;
        //else
        //    return d1.name < d2.name;
    };

public:
    void finally()
    {
        wcout.imbue(locale("", LC_CTYPE));
        wcout << L"----------调整前--------" << endl;
        for (const auto& it : m_vec)
            wcout << L"[it.name]" << it.name << L"[it.md5]" << it.md5 << endl;


        set<MyData, decltype(DeDuplication::cmpSort)*>  s(&DeDuplication::cmpSort);
        for (unsigned i = 0; i < m_vec.size(); ++i)
            s.insert(m_vec[i]);

        m_vec.assign(s.begin(), s.end());

        wcout << L"----------调整后--------" << endl;
        for (const auto& it : m_vec)
            wcout << L"[it.name]" << it.name << L"[it.md5]" << it.md5 << endl;
    };

private:
    vector<MyData>  m_vec = { { L"a1.exe", L"B9204B6362A65C248950D5A41F341DCC"},
                              { L"a2.exe", L"B9204B6362A65C248950D5A41F341DCC"},
                              { L"b1.exe", L"C96D1AA5D314954417C28A645ED72665"},
                              { L"b2.exe", L"C96D1AA5D314954417C28A645ED72665"} };
};
