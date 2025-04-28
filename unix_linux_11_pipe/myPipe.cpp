#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd[2];   //用来标记管道的两端的文件描述符
    int ret = pipe(fd);  //创建管道 pipe. fd[2] 是固定的输出参数

    if (ret == -1) {
        perror("[pipe create file] ");
        return 0;
    }
        
    int pipeRead = fd[0];   
    int pipeWrite = fd[1];

    pid_t pid = fork();

    if (pid > 0) {                         //parent process
        dup2(pipeWrite, STDOUT_FILENO);    //重定向
        close(pipeRead);
        execlp("ps", "ps", "aux", NULL);
    } else if (pid == 0) {                 //child process
        dup2(pipeRead, STDIN_FILENO);      //重定向
        close(pipeWrite);
        execlp("grep", "grep", "bash", "--color=auto", NULL);
    }
    
    return 0;
}
