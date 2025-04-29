#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int g_number = 0;
pthread_rwlock_t lock;

void* writeFunc(void* arg);
void* readFunc(void* arg);

int main(int argc, char *argv[])
{
    pthread_t p[8];

    pthread_rwlock_init(&lock, nullptr); //初始化一个锁

    for (int i = 0; i < 3; i++) {  //创建写线程
        pthread_create(&p[i], nullptr, writeFunc, nullptr);
    }

    for (int i = 3; i < 8; i++) {  //创建读线程
        pthread_create(&p[i], nullptr, readFunc, nullptr);
    }

    for (int i = 0; i < 8; i++) {  //阻塞回收子线程的 pcb
        pthread_join(p[i], nullptr);
    }

    pthread_rwlock_destroy(&lock); //销毁读写锁，释放锁资源
    
    return 0;
}

void* writeFunc(void* arg)
{
    while (true) {
        pthread_rwlock_wrlock(&lock); //加写锁
        g_number++;
        printf("--write: %lu, %d\n", pthread_self(), g_number);
        pthread_rwlock_unlock(&lock);  //解锁
        usleep(500);
    }
    
    return nullptr;
}

void* readFunc(void* arg)
{
    while (true) {
        pthread_rwlock_rdlock(&lock);  //加读锁
        printf("--read : %lu, %d\n", pthread_self(), g_number);
        pthread_rwlock_unlock(&lock);  //解锁
        usleep(500);
    }

    return nullptr;
}
