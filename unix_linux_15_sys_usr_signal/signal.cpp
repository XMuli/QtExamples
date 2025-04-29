#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

void func(int no); //用作回调函数，给 signal() 调用

int main(int argc, char *argv[])
{
    signal(SIGINT, func); //设置信号捕捉函数， 捕捉 ctrl + c

    while (true) {
        printf("Keep the thread running for the non-death state.\n"); 
        sleep(1);
    }

    return 0;
}

void func(int no) 
{
    printf("捕捉的信号为: %d\n", no);
}