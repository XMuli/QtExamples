#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid > 0) {
        while (true) {
            printf("this is a parent process = %d\n", getpid());
            sleep(1);
        }
    } else if (pid == 0) {
        sleep(5);
        kill(getppid(), SIGKILL);
    }
    
    return 0;
}