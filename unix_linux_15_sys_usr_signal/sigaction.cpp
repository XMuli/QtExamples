#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

void func(int no); //用作回调函数

int main(int argc, char *argv[])
{
    __sigaction_u sigactu;
    sigactu.__sa_handler = func; //另一个变量 sigactu.__sa_sigaction 不用赋值

    struct sigaction act;
    act.sa_flags = 0;     //通常给 0
    act.__sigaction_u = sigactu;
    sigemptyset(&act.sa_mask);  //清空 自定义信号集
    sigaddset(&act.sa_mask, SIGQUIT);  //向指定 系统阻塞集 中写入 自定义的信号集，添加需要屏蔽的信号(ctrl + 反斜杠 触发)

    sigaction(SIGINT, &act, NULL);

    while (true) {
        printf("Keep the thread running for the non-death state.\n");
        sleep(1);
    };
    
}

void func(int no) 
{
    printf("捕捉的信号为: %d\n", no);
    sleep(4);
    printf("醒了\n");
}