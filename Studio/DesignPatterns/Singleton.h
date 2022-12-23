/*******************************************************************
 * Copyright (c) 2022~2023 XMuli  All rights reserved.
 * GitHub: https://github.com/XMuli
 * Description: 单例模式 Singleton Pattern 的最优雅实现
 * Reference: https://zhuanlan.zhihu.com/p/37469260 单例介绍及好一篇
 ******************************************************************/
#pragma once

// 《Effective C++》提出了一种更优雅的单例模式实现，称为 Meyers' Singleton
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

