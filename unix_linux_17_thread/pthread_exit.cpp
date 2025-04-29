#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int num = 13; //设置为全局变量，在全局区域，共享

void* myfun(void* arg);

int main(int argc, char *argv[])
{
    void* p = (void *)&num;  //传一个地址进去（voi* 也是 4 个字节）
    pthread_t id[5] = {0};
    for (int i = 0; i < 5; i++) {
        pthread_create(&(id[i]), NULL, myfun, p);
        printf("i = %d, thread id: %ld\n", i, id[i]);
    }

    // pthread_exit(nullptr);  //终止主线程
    int j = 0;
    while (true) {
        sleep(1);
        printf ("main thread-----%d------\n", j++);
    }
    
    return 0;
}

void* myfun(void* arg)
{
    for (int i = 0; i < 5; i++) {
        printf ("child thread-----%d------\n", i);

        if (i == 2) {
             _exit(0); //退出进程
            // pthread_exit(nullptr);  //终止主线程
        }        
    }

    return nullptr;
}
