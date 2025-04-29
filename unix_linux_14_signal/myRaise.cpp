#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid > 0) {
        int s;
        pid_t wpid = wait(&s);
        printf("this is a child process dide pid = %d\n", wpid);
            
        if (WIFSIGNALED(s))
            printf("dide by signal: %d\n", WTERMSIG(s));
    } else if (pid == 0) {
        raise(SIGINT); //给自己发射信号
    }
    
    return 0;
}
