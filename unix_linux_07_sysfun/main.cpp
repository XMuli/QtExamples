#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    int fp = open("hello.txt", O_RDWR);
    int fp2 = open("temp.txt", O_WRONLY | O_CREAT, 0664);  //创建文件时候，必须要有权限
    printf("fp = %d\n", fp);
    printf("fp2 = %d\n", fp2);

    if (fp == -1)
        perror("[注释信息: ]");

    char buf[4096];
    int len = read(fp, buf, sizeof(buf));

    while (len > 0)
    {
        int ret = write(fp2, buf, len);
        len = read(fp, buf, sizeof(buf));
        printf("ret = %d\n", ret);
    }

    close(fp);
    close(fp2);

    return 0;
}