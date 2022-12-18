/*******************************************************************
 * Copyright (c) 2022~2023 XMuli  All rights reserved.
 * GitHub: https://github.com/XMuli
 * Description: C++ 类的特殊五个函数
 * Ref：https://en.cppreference.com/w/cpp/language/rule_of_three  https://en.wikipedia.org/wiki/Special_member_functions
 ******************************************************************/

#pragma once
#include <iostream>
#include <utility>
using namespace std;

class A
{
public:
    A() : m_ptr(nullptr) {
        std::cout << "default constructor" << endl;
    }

    A(const char* s) : m_ptr(nullptr) {
        std::cout << "no-default-val constructor" << endl;
        if (s) {
            auto n = std::strlen(s) + 1;
            m_ptr = new char[n];
            std::memcpy(m_ptr, s, n);
        }
    }

    A(const A& other)
        : m_ptr(nullptr) {
        std::cout << "copy constructor" << endl;
        if (other.m_ptr) {
            auto n = std::strlen(other.m_ptr) + 1;
            m_ptr = new char[n];
            std::memcpy(m_ptr, other.m_ptr, n);
        }
    }

    A& operator = (const A& other) {
        std::cout << "copy assignment constructor" << endl;
        if (this != &other) {
            delete[] m_ptr;  // Free the existing resource.

            if (other.m_ptr != nullptr) {
                auto n = std::strlen(other.m_ptr) + 1;
                m_ptr = new char[n];
                std::memcpy(m_ptr, other.m_ptr, n);
            }
        }

        return *this;
    }

    A(A&& other) noexcept    // 行参无 const
        : m_ptr(nullptr) {
        std::cout << "move constructor" << endl;
        if (other.m_ptr)
            m_ptr = std::move(other.m_ptr);

        other.m_ptr = nullptr;
    }

    A& operator=(A&& other) noexcept {  // 行参无 const
        std::cout << "move assignment constructor" << endl;
        if (this != &other) {
            delete[] m_ptr;  // Free the existing resource.

            if (other.m_ptr)
                m_ptr = std::move(other.m_ptr);

            other.m_ptr = nullptr;
        }

        return *this;
    }

    ~A() {
        std::cout << "destructor" << endl;
        if (m_ptr)
            delete[] m_ptr;
    }

private:
    char* m_ptr;
};

A fn() {
    A t("A fun()");
    return t;
}

int main()
{
    A a1("a1");                // default constructor
    A a2(a1);                  // copy constructor
    A a3 = a1;                 // copy constructor
    a1 = a3;                   // copy assignment constructor
    std::cout << "----------------------------\n\n";

    //fn();                    // function returning a A object
    A a5 = std::move(a1);      // move constructor
    A a6;                      // default constructor
    a6 = std::move(a1);        // move assignment constructor
    std::cout << "Hello World!\n";

    return 0;
}

/*************************** 运行结果 *******************************
* no-default-val constructor
copy constructor
copy constructor
copy assignment constructor
----------------------------

move constructor
default constructor
move assignment constructor
Hello World!
destructor
destructor
destructor
destructor
destructor
 ******************************************************************/
