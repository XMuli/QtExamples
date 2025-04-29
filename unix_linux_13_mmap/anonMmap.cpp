#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
    int len = 4096;
    void* ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);  //创建匿名内存映射区，只需要修改倒数 2、3 两个阐述即可
    if (ptr == MAP_FAILED) {
        perror("[mmap fail] ");
        exit(1);
    }

    pid_t pid = fork();

    if (pid > 0) {  //父进程
         strcpy((char *)ptr, "this is parent process");
         wait(NULL);         //回收子进程
    } else if (pid == 0) {  //子进程
        // sleep(2);
        ((char *)ptr)[0] = 'a';  //故意覆盖掉'\0'，打印出来后面文章
        ((char *)ptr)[1] = 'b';
        ((char *)ptr)[2] = 'c';
        printf("%s", (char *)ptr);
    }

    munmap(ptr, len);

    return 0;
}
