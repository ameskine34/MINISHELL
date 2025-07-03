// // In the parent process

// // The forking loop
// for (int i = 0; i < num_of_processes; i++) {
//     pid = fork();
//     if (pid == 0) {
//         // Inside the child process (if pid == 0)

// // ... do your dup2() calls to set up stdin and stdout ...
// // For example, for an intermediate command:
// // dup2(pipes[i-1][0], STDIN_FILENO);
// // dup2(pipes[i][1], STDOUT_FILENO);

//     } else if (pid > 0) {
//         // Parent in the loop - just store the child's pid
//         pids[i] = pid;
//     }
// }

// // NOW, THE LOOP IS FINISHED. All children have been forked.
// // The parent must clean up its own file descriptors.
// for (int j = 0; j < num_of_pipes; j++) {
//     close(pipes[j][0]);
//     close(pipes[j][1]);
// }

// // Now the parent can safely wait for the children to complete,
// // knowing it won't be the cause of any deadlocks.
// for (int i = 0; i < num_of_processes; i++) {
//     waitpid(pids[i], &status, 0);
// }

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

{
    struct stat    x;

    ft_memset(&x, 0, sizeof(x)); // set to 0
    stat(cmd, &x); // fill the struct with file info
    if (S_ISDIR(x.st_mode)) // check if its a dir 
    {
        print_error(3, error, cmd);
        if (error)
            exit_status(126);
        return (NULL);
    }
}