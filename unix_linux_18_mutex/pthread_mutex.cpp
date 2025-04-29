#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int g_num = 0; //在全局区域，共享
#define MAXNUMBER 100000
pthread_mutex_t g_mutex; //创建全局的互斥锁

void* funA(void* arg);
void* funB(void* arg);

int main(int argc, char *argv[])
{
    pthread_mutex_init(&g_mutex, nullptr); //对锁进行初始化

    pthread_t pthreadA = 0;
    pthread_t pthreadB = 0;
    pthread_create(&pthreadA, nullptr, funA, nullptr);  //创建两个子线程
    pthread_create(&pthreadB, nullptr, funB, nullptr);

    pthread_join(pthreadA, nullptr);  //阻塞，回收资源
    pthread_join(pthreadB, nullptr);

    pthread_mutex_destroy(&g_mutex);  //释放互斥锁资源
    return 0;
}

void* funA(void* arg)
{
    for (int i = 0; g_num < MAXNUMBER; i++) {
        pthread_mutex_lock(&g_mutex);
        int a = g_num;
        a++;
        g_num = a;
        printf("A thread id: %ld,   num = %d\n", pthread_self(), g_num);
        pthread_mutex_unlock(&g_mutex);

        usleep(10); //沉睡 10 毫秒， 模拟时间片轮转，效果更明显
    }

    return nullptr;
}

void* funB(void* arg)
{
    for (int i = 0; g_num < MAXNUMBER; i++) {
        pthread_mutex_lock(&g_mutex);
        int b = g_num;
        b++;
        g_num = b;
        printf("B thread id: %ld,   num = %d\n", pthread_self(), g_num);
        pthread_mutex_unlock(&g_mutex);

        usleep(10); //沉睡 10 毫秒， 模拟时间片轮转，效果更明显
    }

    return nullptr;
}
