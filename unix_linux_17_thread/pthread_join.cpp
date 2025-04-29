#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int number = 1234; //要是一个全局的变量哦，或者是堆的空间
void* myfun(void* arg);

int main(int argc, char *argv[])
{
    pthread_t pthread = 0;
    int ret = pthread_create(&pthread, NULL, myfun, NULL);

    if (ret != 0)
        printf("error: %s\n", strerror(ret));

    printf("parent thread id: %ld\n", pthread_self);

    void* ptr = nullptr;

    pthread_join(pthread, &ptr); //阻塞等待子线程退出，并且回收 pcb
    printf("number = %d\n", *((int*)ptr));

    int i = 0;
    while (i < 10 ) {
        printf("parent i = %d\n", i++);
    }
    
    return 0;
}

void* myfun(void* arg)
{
    printf("child thread id: %ld\n", pthread_self());

    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            // int number = 1234;   //若是为栈里面的数据，则会组线程里面，会崩溃或者失败
            pthread_exit(&number);  //此处的地址，必须是指向堆或者全局变量
        }

        printf("child i = %d\n", i);
    }

    return NULL;
}
