/*******************************************************************
 * Copyright (c) 2022~2023 XMuli  All rights reserved.
 * GitHub: https://github.com/XMuli
 * Description: 工厂方法模式(Factory Method)
 *              IProduct 下面有多个具体类，都通过 IFactory 定义的好接口，
 *              通过具体的 Factory 去 new 具体的 Product 对象
 * See: https://blog.csdn.net/silangquan/article/details/20492293
 ******************************************************************/

#pragma once
#include <iostream>
using namespace std;

/********************************************************
 每创建一个具体的 Product 类，就得创建一个具体的 Factory 类
********************************************************/
class IProduct
{
public:
    virtual ~IProduct() = default;
    virtual void doSomeThing() = 0;
};

class AProduct : public IProduct
{
public:
    virtual ~AProduct() = default;
    virtual void doSomeThing() override {
        cout << "this is A Product, do some thing..." << endl;
    };
};

class BProduct : public IProduct
{
public:
    virtual ~BProduct() = default;
    virtual void doSomeThing() override {
        cout << "this is B Product, do some thing..." << endl;
    };
};

class CProduct : public IProduct
{
public:
    virtual ~CProduct() = default;
    virtual void doSomeThing() override {
        cout << "this is C Product, do some thing..." << endl;
    };
};

class IFactory
{
public:
    virtual IProduct* creatProduct() = 0;
};

class AFactory : public IFactory
{
public:
    virtual ~AFactory() = default;
    virtual IProduct* creatProduct() override { return new AProduct(); };
};

class BFactory : public IFactory
{
public:
    virtual ~BFactory() = default;
    virtual IProduct* creatProduct() override { return new BProduct(); };
};

class CFactory : public IFactory
{
public:
    virtual ~CFactory() = default;
    virtual IProduct* creatProduct() override { return new CProduct(); };
};

//int main()
//{
//    AFactory aFactory;
//    BFactory bFactory;
//    CFactory cFactory;
//    aFactory.creatProduct()->doSomeThing();
//    bFactory.creatProduct()->doSomeThing();
//    cFactory.creatProduct()->doSomeThing();
//    return 0;
//}


/*****************************打印结果*******************************
this is A Product, do some thing...
this is B Product, do some thing...
this is C Product, do some thing...
 ******************************************************************/