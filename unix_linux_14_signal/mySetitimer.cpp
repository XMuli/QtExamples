#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    itimerval time;
    // time.it_interval = 3;  //每隔 3s 一次循环定时

    //第一次触发定时器的时间为 5s + 3ms
    time.it_value.tv_sec = 5;     //5s 
    time.it_value.tv_usec = 3;    //3 ms

    setitimer(ITIMER_REAL, &time, NULL);

    while (true) {
        printf("-----printf()-----\n");
        sleep(1);
    }
    
    return 0;
}
