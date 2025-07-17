#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
# include <stdarg.h>
#include <fcntl.h> 

int main()
{
    int fd[2];
    int status;
    int i = 0;
    int pid = 0;
    char *args[] = {"ls", "-a", NULL};

    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        i = execve("/usr/bin/ls", args, NULL);
        if (i == -1)
            printf("ERROR\n");
    }
    else
    {
        printf("sjfks\n");
    }
    waitpid(-1, &status, 0);
    // int j = WEXITSTATUS(status);
    // printf("this the exit status : %d\n", j);
}
