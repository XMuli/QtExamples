#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    alarm(1);

    int n = 0;
    while (true) {
        printf("%d\n", n++);
    }

    return 0;
}
