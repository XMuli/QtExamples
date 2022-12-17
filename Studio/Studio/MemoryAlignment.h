/*******************************************************************
 * Copyright (c) 2022~2023 XMuli  All rights reserved.
 * GitHub: https://github.com/XMuli
 * Description: 类中字节对齐判断
 ******************************************************************/

// NOTE: 
#pragma once
class A
{
private:
    int m_a;
    char m_c1;
    char m_c2;

    static int g_sta;
};  // 8

class B
{
public:
    void fun() {};

private:
    char m_c1;
    int m_a;
    char m_c2;
}; // 12

class C
{
public:
    virtual void fun() {};

private:
    int m_a;
}; // 8
