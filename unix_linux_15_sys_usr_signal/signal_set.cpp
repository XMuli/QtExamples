#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    while (true) {
        sigset_t pendest;
        sigpending(&pendest);

        for (int i = 0; i < 64; i++) {    //每隔一秒，对系统信号阻塞集的信号做一次校验
            if (sigismember(&pendest, i))
                printf("1");
            else
                printf("0");
        }

        printf("\n"); 
        sleep(1);
    }

    return 0;
}
