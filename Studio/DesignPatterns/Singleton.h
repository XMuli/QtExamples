/*******************************************************************
 * Copyright (c) 2022~2023 XMuli  All rights reserved.
 * GitHub: https://github.com/XMuli
 * Description: 单例模式 Singleton Pattern 的最优雅实现
 * Reference: https://zhuanlan.zhihu.com/p/37469260 单例介绍及好一篇
 ******************************************************************/
#pragma once

// 推荐使用 →《Effective C++》提出了一种更优雅的单例模式实现，称为 Meyers' Singleton
class Singleton
{
public:
    static Singleton& instance() {
        static Singleton instan;
        return instan;
    }

private:
    Singleton() {};
    ~Singleton() {};
    Singleton(const Singleton& obj) = delete;
    Singleton& operator=(const Singleton& obj) = delete;
};

//---------------------------------------------------------
// 不推荐使用 → Eager Singleton 是线程安全的，但存在潜在问题 no-local static 对象在不同编译单元中的初始化顺序是未定义的
class Singleton2
{
public:
    static Singleton2& instance() {
        return instan;
    }

private:
    Singleton2() {};
    ~Singleton2() {};
    Singleton2(const Singleton2&) = delete;
    Singleton2& operator=(const Singleton2&) = delete;

private:
    static Singleton2 instan;
};

Singleton2 Singleton2::instan;

