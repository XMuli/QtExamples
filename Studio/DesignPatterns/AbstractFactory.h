/*******************************************************************
 * Copyright (c) 2022~2023 XMuli  All rights reserved.
 * GitHub: https://github.com/XMuli
 * Description: 抽象工厂模式(Abstract Factory)
 *              Up产品 up1、up2 两款式产品，Down 有 down1、down2 两款式产品；
 * 每个工厂一次只生产 Up + Down 系列产品，即可组成套装出售；比如
 * AFactory 生产 up1 + down1； BFactory 生产 up2 + down2；
 * CFactory 生产 up1 + down2； 等各种组合
 * See: https://blog.csdn.net/silangquan/article/details/20492293
 ******************************************************************/
#pragma once
#include <iostream>
using namespace std;

/***************************************************************************
 每一个具体的 Factory 类，都可以创建多款 product，但是每款只能够生成 1 个(对象)
***************************************************************************/

class IUpProduct
{
public:
    virtual ~IUpProduct() = default;
    virtual void doSomeThing() = 0;
};

class Up1Product : public IUpProduct
{
public:
    virtual ~Up1Product() = default;
    virtual void doSomeThing() override {
        cout << "this is 1 UpProduct, do some thing..." << endl;
    }
};

class Up2Product : public IUpProduct
{
public:
    virtual ~Up2Product() = default;
    virtual void doSomeThing() override {
        cout << "this is 2 UpProduct, do some thing..." << endl;
    }
};

class IDownProduct
{
public:
    virtual ~IDownProduct() = default;
    virtual void doSomeThing() = 0;
};

class Down1Product : public IDownProduct
{
public:
    virtual ~Down1Product() = default;
    virtual void doSomeThing() override {
        cout << "this is 1 DownProduct, do some thing..." << endl;
    }
};

class Down2Product : public IDownProduct
{
public:
    virtual ~Down2Product() = default;
    virtual void doSomeThing() override {
        cout << "this is 2 DownProduct, do some thing..." << endl;
    }
};

class IFactory
{
public:
    virtual ~IFactory() = default;
    virtual IUpProduct* creatorUpProduct() = 0;
    virtual IDownProduct* creatorDownProduct() = 0;
};

class AFactory : public IFactory
{
public:
    virtual ~AFactory() = default;
    virtual IUpProduct* creatorUpProduct() override {
        return new Up1Product();
    }
    virtual IDownProduct* creatorDownProduct() override {
        return new Down1Product();
    }
};

class BFactory : public IFactory
{
public:
    virtual ~BFactory() = default;
    virtual IUpProduct* creatorUpProduct() override {
        return new Up2Product();
    }
    virtual IDownProduct* creatorDownProduct() override {
        return new Down2Product();
    }
};

class CFactory : public IFactory
{
public:
    virtual ~CFactory() = default;
    virtual IUpProduct* creatorUpProduct() override {
        return new Up1Product();
    }
    virtual IDownProduct* creatorDownProduct() override {
        return new Down2Product();
    }
};

//int main()
//{
//    AFactory aFactory;
//    aFactory.creatorUpProduct()->doSomeThing();
//    aFactory.creatorDownProduct()->doSomeThing();
//    cout << endl;
//
//    BFactory bFactory;
//    bFactory.creatorUpProduct()->doSomeThing();
//    bFactory.creatorDownProduct()->doSomeThing();
//    cout << endl;
//
//    CFactory cFactory;
//    cFactory.creatorUpProduct()->doSomeThing();
//    cFactory.creatorDownProduct()->doSomeThing();
//    cout << endl;
//    return 0;
//}

/*****************************打印结果*******************************
this is 1 UpProduct, do some thing...
this is 1 DownProduct, do some thing...

this is 2 UpProduct, do some thing...
this is 2 DownProduct, do some thing...

this is 1 UpProduct, do some thing...
this is 2 DownProduct, do some thing...
 ******************************************************************/