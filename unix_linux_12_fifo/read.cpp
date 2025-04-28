#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请按照格式输入: ./read myfifo\n");
        exit(1);
    }

    int ret = access(argv[1], F_OK); //判断文件是否存在
    if (ret == -1) {
        int r = mkfifo(argv[1], 0777);
        if (r == -1) {
            perror("[creator fifo file] ");
            exit(1);
        } else {
            printf("creator fifo success: %d\n", argv[1]);
        }
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("[open file] ");
        exit(1);
    }

    char buf[512];

    while (true) {
        int len = read(fd, buf, sizeof(buf));
        buf[len] = '\0';
        printf("buf = %s,  len = %d\n", buf, len);
    }

    close(fd);
    
    return 0;
}
