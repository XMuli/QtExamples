#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();  //创建子进程

    if (pid == 0) { //（此时子进程已经执行完成销毁）, 而父进程没有时间去销毁这个子进程的 pcb，故为僵尸进程
        printf("this is a child process, pid = %d  ppid = %d\n", getpid(), getppid());  
    } else if (pid > 0) {  //父进程
        while (true)
        {
            sleep(1);
           printf("this is a parent process, pid = %d  ppid = %d\n", getpid(), getppid());  //执行完后，父进程就结束了
        }
    }

    return 0;
}
