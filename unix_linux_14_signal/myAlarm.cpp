#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int ret = alarm(5);
    printf("ret = %d\n", ret);

    sleep(2);
    ret = alarm(10); //重新设定定时器，返回值是返回之前闹钟的剩余的时间
    printf("ret = %d\n", ret);

    while (true) {
        printf("-------test-----\n");
        sleep(1);
    }
    
    return 0;
}
