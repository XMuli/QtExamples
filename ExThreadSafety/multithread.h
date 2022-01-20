/*******************************************************************
 * Copyright (C)  2022  偕臧  All rights reserved.
 *
 * Author:  偕臧 <xmulitech@gmail.com>
 * GitHub:  https://github.com/xmuli
 * Blog:    https://ifmet.cn
 *
 * Create: 2022.01.12
 * Modify: 2022.01.14
 * File: multithread.h
 * Description: 一个多线程竞争的例子，分析出现的“非线程安全”的具体原因，以及两个
 *			 解决方法：atomic 和 mutex
 *
 ******************************************************************/
#ifndef MULTITHREAD_H
#define MULTITHREAD_H

#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

// 方案一：定义为原子变量 atomic
//atomic<int> g_num = 0;

// 方案二：加锁 mutex
int g_num = 0;
mutex g_mutex;

void addition()
{
	for (int i = 0; i < 5000; ++i) {
		g_mutex.lock();  // 尝试和下一行的 cout 行互换位置
		cout << "threadId:" << this_thread::get_id() << "  g_num:" << g_num << endl;
		g_num++;
		g_mutex.unlock();
	}
}

使用示例
int main()
{
	thread th1(addition);
	thread th2(addition);
	th1.join();
	th2.join();

	cout << "g_num:" << g_num << endl;
	return 0;
}

#endif