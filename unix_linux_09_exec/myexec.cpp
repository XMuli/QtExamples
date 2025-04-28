#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < 3; i++)
        printf("-----i = %d\n", i);

    pid_t pid = fork();  //创建子进程

    if (pid == 0) {
        execl("/bin/ls", "占位参数", "-al", NULL);  //ls 程序使用子进程的地址空间
//        execl("./hello", "占位参数", NULL);           //一般是调用自己的程序，而非系统的程序
    }

    for (int i = 0; i < 3; i++)
        printf("+++++i = %d\n", i);

    return 0;
}
