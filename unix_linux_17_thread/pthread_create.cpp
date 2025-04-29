#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* myfun(void* arg);

int main(int argc, char *argv[])
{
    pthread_t pthread = 0;  //创建一个子线程
    int ret = pthread_create(&pthread, NULL, myfun, NULL);
    printf("parent thread id: %ld\n", pthread_self);

    sleep(2);  //避免主线程运行后，就死亡了，而子线程没机会
    for (int i = 0; i < 5; i++) {  //验证子线程，并不会执行这里面的代码，只会执行回调函数 muyfun 里面的
        printf("i = %d\n", i);
    }
    
    return 0;
}

void* myfun(void* arg)
{
    printf("child thread id: %ld\n", pthread_self());
    return NULL;
}
