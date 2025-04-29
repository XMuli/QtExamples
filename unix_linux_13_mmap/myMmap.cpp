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

    ((char *)ptr)[0] = 'a';
    ((char *)ptr)[1] = 'b';
    ((char *)ptr)[2] = 'c';
    
    printf("%s\n", (char*)ptr);  //释放内存映射区
    munmap(ptr, len);
    close(fd);

    return 0;
}
