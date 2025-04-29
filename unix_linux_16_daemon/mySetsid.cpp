#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <time.h>

void func(int no); //用作回调函数，给 signal() 调用

int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid > 0) {
        _exit(1); //父进程退出
    } else if (pid == 0) {
        setsid();  //子进程创建为会话
        chdir("/Users/muli/Desktop/");  //改变进程的工作目录
        umask(0);    //重设置文件掩码

        close(STDIN_FILENO);   //关闭和终端的联系，文件描述符
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        __sigaction_u sigactu;  //设置信号捕捉
        sigactu.__sa_handler = func;

        struct sigaction act;
        act.sa_flags = 0;
        act.__sigaction_u = sigactu;
        sigaddset(&act.sa_mask, SIGQUIT);

        itimerval time;  //设置周期性的定时器
        time.it_value.tv_sec = 2;
        time.it_value.tv_usec = 0;
        time.it_interval.tv_sec = 1;
        time.it_interval.tv_usec = 0;

        sigaction(SIGVTALRM, &act, NULL);          //捕捉（下面一行发射的）信号，在 fun() 里面实现
        setitimer(ITIMER_VIRTUAL, &time, NULL);    //使用定时器，发射信号

        while (true); //保持该守护进程不死亡
    }

    return 0;
}

void func(int no) 
{
    time_t currtime;  //获取系统当前时间，传出参数
    time(&currtime);
    char* ptr = ctime(&currtime);

    int fd = open("/Users/muli/Desktop/setsid.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);  //写入磁盘文件
    write(fd, ptr, sizeof(ptr) + 1);
    close(fd);
}