#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < 4; ++i) {
        printf("++++i = %d\n", i);
    }

    pid_t pid = -1;

    pid = fork();

    if (pid > 0)
        printf("this is a parent process, pid = %d\n", getpid());
    else if (pid == 0)
        printf("this is a child process, pid = %d  ppid = %d\n", getpid(), getppid());

    for (int i = 0; i < 4; ++i) {
       printf("----i = %d\n", i);
    }

    return 0;
}
