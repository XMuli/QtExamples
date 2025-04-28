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

    int i = 0;
    for ( ; i < 2; i++) {
        pid_t pid = fork();
        
        if (pid == 0)
            break;

        if (pid == -1)
            perror("[creator process file:]");

    }

    if (i == 0) {                         //child process 1
        dup2(pipeWrite, STDOUT_FILENO);   
        close(pipeRead);
        execlp("ps", "ps", "aux", NULL);
    } else if (i == 1) {                 //child process 2
        dup2(pipeRead, STDIN_FILENO);    
        close(pipeWrite);
        execlp("grep", "grep", "bash", "--color=auto", NULL);
    } else if (i == 2) {                 //parent process
        close(pipeWrite);
        close(pipeRead);

        // sleep(2);
        int wpid;
        while ( wpid = waitpid(-1, NULL, WNOHANG) != -1) {  //回收子进程
            if (wpid == 1) ///sbin/init splash 进程    /sbin/launchd
                continue;

            if (wpid == 0) 
                continue;

            printf("child dide pid = %d\n", wpid);
        }    
    }
    
    printf("pipeWrite = %d,  pipeRead = %d\n", pipeWrite, pipeRead);
    return 0;
}
