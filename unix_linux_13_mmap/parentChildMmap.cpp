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
    int fd = open("it.txt", O_RDWR);

    if (fd == -1) {
        perror("[open file] ");
        _exit(1);
    }

    int len = lseek(fd, 0, SEEK_END);
    void* ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);  //创建内存映射区
    if (ptr == MAP_FAILED) {
        perror("[mmap fail] ");
        exit(1);
    }

    pid_t pid = fork();

    if (pid > 0) {  //父进程
         strcpy((char *)ptr, "(我是父进程写入数据到内存映射区内容)");  //下标0-53，一共 54 个，其中ptr[53]为'\0'
         wait(NULL);         //回收子进程
    } else if (pid == 0) {  //子进程
        // sleep(2);
        ((char *)ptr)[53] = 'a';  //故意覆盖掉'\0'，打印出来后面文章
        ((char *)ptr)[54] = 'b';
        ((char *)ptr)[57] = 'c';
        printf("%s", (char *)ptr);
    }

    munmap(ptr, len);
    close(fd);

    return 0;
}
