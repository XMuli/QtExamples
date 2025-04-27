#include <stdio.h>
#include <unistd.h>


int g_num = 200;

int main(int argc, char *argv[])
{
    pid_t pid = -1;

    int i = 0;

    for (i = 0; i < 3; ++i) {
        pid = fork();

        if (pid == 0)  //如果当前进程是子进程，就跳出此循环，不在进行 fork() 创建新的子进程
            break;
    }

    if (i == 0) {
        g_num += 5;
        printf("this is a child process (i == 2), pid = %d  ppid = %d\n", getpid(), getppid());
    }


    if (i == 1){
        g_num += 5;
        printf("this is a child process (i == 2), pid = %d  ppid = %d\n", getpid(), getppid());
    }

    if (i == 2) {
        g_num += 5;
        printf("this is a child process (i == 2), pid = %d  ppid = %d\n", getpid(), getppid());
    }

    if (i == 3) {
        g_num += 100;
        printf("this is a parent process (i == 3), pid = %d  ppid = %d\n", getpid(), getppid());
    }

    printf("g_nmu = %d\n", g_num);

    return 0;
}
