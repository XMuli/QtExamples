#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    while (true) {
        sleep(1);
        printf("hello world\n");
    }
    
    return 0;
}
