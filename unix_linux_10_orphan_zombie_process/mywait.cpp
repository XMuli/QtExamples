#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("-----开始-----\n");

    pid_t pid = fork();  //创建子进程

    if (pid == 0) { //（此时子进程已经执行完成销毁）, 而父进程没有时间去销毁这个子进程的 pcb，故为僵尸进程
        while (true) {
            sleep(2);
            printf("this is a child process, pid = %d  ppid = %d\n", getpid(), getppid());  
        }
    } else if (pid > 0) {  //父进程
        //sleep(1);
        
        int status = 0;
        pid_t wpid = wait(&status);  //回收子进程

        if (WIFEXITED(status))   //判断是否正常退出
            printf("退出值是 val = %d\n", WEXITSTATUS(status));

        if (WIFSIGNALED(status))   //判断是狗被信号杀死
            printf("通过信号退出 val = %d\n", WTERMSIG(status));

        printf("this is a parent process, pid = %d  ppid =  %d\n", getpid(), getppid());  //执行完后，父进程就结束了
    }

    printf("+++++结束+++++\n");

    return 9;  //若是注释掉 12 和 15 行代码，会显示父父进程的 退出值是 9
}
