#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请按照格式输入: ./write myfifo\n");
        _exit(1);
    }

    int ret = access(argv[1], F_OK); //判断文件是否存在
    if (ret == -1) {
        int r = mkfifo(argv[1], 0777);
        if (r == -1) {
            perror("[creator fifo file] ");
            _exit(1);
        } else {
            printf("creator fifo success: %d\n", argv[1]);
        }
    }

    int fd = open(argv[1], O_WRONLY);

    if (fd == -1) {
        perror("[open file] ");
        _exit(1);
    }

    char const *p = "this is 2020-04-01, code";

    while (true) {
        sleep(2);
        int len = write(fd, p, strlen(p) + 1);
    }

    close(fd);

    return 0;
}
