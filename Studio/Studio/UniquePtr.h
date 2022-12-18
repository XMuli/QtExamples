/*******************************************************************
 * Copyright (c) 2022~2023 XMuli  All rights reserved.
 * GitHub: https://github.com/XMuli
 * Description: C++ 实现一个核心的 unique_ptr 智能指针模板类；
 * Ref: https://www.jianshu.com/p/77c2988be336
 *		https://juejin.cn/post/7122641980315680782
 *		https://juejin.cn/post/7099967913594978341
 ******************************************************************/

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class UniquePtr
{
public:
	constexpr UniquePtr() : _ptr(nullptr) { cout << "default constructor" << endl; };
	explicit  UniquePtr(T* obj) : _ptr(obj) { cout << "no default constructor" << endl; };

	UniquePtr(UniquePtr<T>&& obj) noexcept 
		: _ptr(obj._ptr) 
	{
		cout << "move constructor" << endl;
		obj._ptr = nullptr;
	}
	UniquePtr<T>& operator=(UniquePtr<T>&& obj) noexcept
	{
		cout << "move assignment constructor" << endl;
		if (&obj != this) {
			if (obj._ptr) {
                _ptr = obj._ptr;
                obj._ptr = nullptr;
			}
		}

		return *this;
	}

	UniquePtr(const UniquePtr<T>& obj) = delete;		// C++11 delete 禁止方式，C++98 用 private 来隐藏
    UniquePtr<T>& operator=(const UniquePtr<T>& obj) = delete;

	~UniquePtr()
	{
		cout << "destructor" << endl;
		if (_ptr) {
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*() const { return *_ptr; }
	T* operator->() const { return _ptr; }
	T* get() const { return _ptr; }

	T* release()            // return std::exchange(_ptr, nullptr); // C++14
	{
		T* temp = _ptr;
        _ptr = nullptr;
		return temp;
	}

	void reset(T* ptr)		// std::exchange(_ptr, ptr); // C++14
	{
		_ptr = ptr;
	}

	void swap(UniquePtr<T>& obj)
	{
		std::swap(_ptr, obj._ptr);
	}

private:
	T* _ptr;
};

//int main()
//{
//	UniquePtr<int> up1(new int(10));
//	cout << "up1:" << up1.get() << "  *ptr:" << *up1 << endl;
//	UniquePtr<int> up2(std::move(up1));                 // 控制权变更
//	cout << "up1:" << up1.get() << endl;		        // nullptr, 此时 up1 已无控制权
//	cout << "up2:" << up2.get() << "  *ptr:" << *up2 << endl;
//	
//	UniquePtr<int> up3(new int(30));
//	UniquePtr<int> up4(new int(40));
//	cout << "up3:" << up3.get() << "  *ptr:" << *up3 << endl;
//	cout << "up4:" << up4.get() << "  *ptr:" << *up4 << endl;
//	up3 = std::move(up2);                               // 控制权变更
//	cout << "up3:" << up3.get() << "  *ptr:" << *up3 << endl;
//	cout << "up4:" << up4.get() << "  *ptr:" << *up4 << endl;
//	up3.swap(up4);
//	cout << "up3:" << up3.get() << "  *ptr:" << *up3 << endl;
//	cout << "up4:" << up4.get() << "  *ptr:" << *up4 << endl;
//	
//	up3.release();
//	cout << "up3:" << up3.get() << endl;
//	
//	std::cout << "Hello World!\n";
//	return 0;
//}

/*******************************************************************
 * 打印结果:
 * no default constructor
 * up1:01355E78  *ptr:10
 * move constructor
 * up1:00000000
 * up2:01355E78  *ptr:10
 * no default constructor
 * no default constructor
 * up3:01355AF0  *ptr:30
 * up4:01355B20  *ptr:40
 * move assignment constructor
 * up3:01355E78  *ptr:10
 * up4:01355B20  *ptr:40
 * up3:01355B20  *ptr:40
 * up4:01355E78  *ptr:10
 * up3:00000000
 * Hello World!
 * destructor
 * destructor
 * destructor
 * destructor
 ******************************************************************/