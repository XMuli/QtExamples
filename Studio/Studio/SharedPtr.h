/*******************************************************************
 * Copyright (c) 2022~2023 XMuli  All rights reserved.
 * GitHub: https://github.com/XMuli
 * Description: C++ 实现一个核心的 shared_ptr 智能指针模板类；实现了引用计数是线程安全的，但访问管理的资源不是线程安全的。
 * Note: 书写测试时，若使用默认构造函数, 成员变量 _ptr、_refCount、_pMutex 在 release() 中容易崩溃；推荐带参的构造函数，无错
 * Ref: https://juejin.cn/post/7111726931301072910#heading-8
 *      https://cloud.tencent.com/developer/article/1688444
 *      https://blog.csdn.net/Z_Stand/article/details/98512756
 ******************************************************************/

#pragma once
#include <iostream>
#include <mutex>
using namespace std;

template <typename T>
class SharedPtr
{
public:
    SharedPtr() : _ptr(nullptr), _refCount(nullptr), _pMutex(nullptr) { cout << "default constructor" << endl; };
    SharedPtr(T* obj) : _ptr(obj), _refCount(new int(1)), _pMutex(new mutex) { cout << "no default constructor" << endl; };

    SharedPtr(const SharedPtr<T>& obj)  // 其 _refCount 可以通过另外一个指针来修改，指向的是同一个地址
        : _ptr(obj._ptr)
        , _refCount(obj._refCount)
        , _pMutex(obj._pMutex)
    {
        cout << "copy constructor" << endl;
        addRefCount();
    };

    SharedPtr<T>& operator=(const SharedPtr<T>& obj)
    {
        cout << "copy assignment constructor" << endl;
        if (&obj != this) {
            if (_ptr != obj._ptr) {
                release();            // 先释放旧的资源

                _ptr = obj._ptr;
                _refCount = obj._refCount;
                _pMutex = obj._pMutex;

                addRefCount();        // 再技计数 +1
            }
        }

        return *this;
    }

    //SharedPtr(SharedPtr<T>&& obj) noexcept;
    //SharedPtr<T>& operator=(SharedPtr<T>&& obj)noexcept;

    ~SharedPtr() { cout << "destructor" << endl; release(); }
    T& operator*() { return *_ptr; }
    T* operator->() { return _ptr; }

    int useCount() { return *_refCount; }
    T* get() { return _ptr; }

private:
    void addRefCount()
    {
        cout << "addRefCount" << endl;
        _pMutex->lock();
        ++*_refCount;
        _pMutex->unlock();
    }

    void release()
    {
        cout << "release" << endl;
        bool bDelMutex = false;
        _pMutex->lock();

        if (_ptr && --*_refCount == 0) {  // 先校验是否存在，及计数为 0 才释放
            delete _ptr;
            delete _refCount;
            _ptr = nullptr;
            _refCount = nullptr;

            bDelMutex = true;
        }

        _pMutex->unlock();
        if (bDelMutex)
            delete _pMutex;
    }

private:                  // 需在构造函数中初始化
    T* _ptr;              // 指向管理资源的指针
    int* _refCount;       // 引用计数
    mutex* _pMutex;       // 计数自增非原子操作，加锁解决多线程
};

//int main()
//{
//    SharedPtr<int> sp1(new int(10));
//    SharedPtr<int> sp2(sp1);
//    *sp2 = 20;
//                                                                //sp1 与 sp2 在管理这部分资源，引用计数为 2
//    cout << sp1.useCount() << "  *ptr:" << *sp1 << endl;		//2	 20
//    cout << sp2.useCount() << "  *ptr:" << *sp2 << endl;		//2	 20
//                                                                  
//    SharedPtr<int> sp3(new int(30));                              
//    sp2 = sp3;		                                            //sp3 赋值给它，释放管理的旧资源，引用计数-1，   
//    cout << sp1.useCount() << "  *ptr:" << *sp1 << endl;        //1	 20
//    cout << sp2.useCount() << "  *ptr:" << *sp2 << endl;        //2	 30
//    cout << sp3.useCount() << "  *ptr:" << *sp3 << endl;        //2	 30
//                                                                  
//    sp1 = sp3;                                                    
//    cout << sp1.useCount() << "  *ptr:" << *sp1 << endl;        //3	 30
//    cout << sp2.useCount() << "  *ptr:" << *sp2 << endl;        //3	 30
//    cout << sp3.useCount() << "  *ptr:" << *sp3 << endl;        //3	 30
//
//    std::cout << "Hello World!\n";
//    return 0;
//}

/*****************************打印结果*******************************
no default constructor
copy constructor
addRefCount
2  *ptr:20
2  *ptr:20
no default constructor
copy assignment constructor
release
addRefCount
1  *ptr:20
2  *ptr:30
2  *ptr:30
copy assignment constructor
release
addRefCount
3  *ptr:30
3  *ptr:30
3  *ptr:30
Hello World!
destructor
release
destructor
release
destructor
release
 ******************************************************************/