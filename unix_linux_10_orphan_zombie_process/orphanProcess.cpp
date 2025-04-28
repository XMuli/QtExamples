#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();  //创建子进程

    if (pid == 0) { //存活时间大于 1s（此时父进程已经执行完成销毁）, 为孤儿子进程
        sleep(1);
        printf("this is a child process, pid = %d  ppid = %d\n", getpid(), getppid());  
    } else if (pid > 0) {  //父进程
        printf("this is a parent process, pid = %d  ppid = %d\n", getpid(), getppid());  //执行完后，父进程就结束了
    }

    return 0;
}
