// #include <fcntl.h>
// #include <limits.h>
// #include <readline/history.h>
// #include <readline/readline.h>
// #include <signal.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/wait.h>
// #include <unistd.h>

// void	ex(char **cmd[])
// {
// 	int	i;
// 	int	in_fd;
// 	int	pipe_fd[2];
// 	int	pid;
// 	int	status;

// 	status = 0;
// 	i = 0;
// 	in_fd = STDIN_FILENO;
// 	while (i < 3)
// 	{
// 		if (pipe(pipe_fd) < 0)
// 			return ;
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			dup2(in_fd, STDIN_FILENO);
// 			if (in_fd != STDIN_FILENO)
// 				close(in_fd);
// 			dup2(pipe_fd[1], STDOUT_FILENO);
// 			close(pipe_fd[0]);
// 			close(pipe_fd[1]);
// 			execve(cmd[i][0], cmd[i] + 1, NULL);
// 		}
// 		waitpid(pid, NULL, 0);
// 		if (in_fd != STDIN_FILENO)
// 			close(in_fd);
// 		in_fd = pipe_fd[0];
// 		close(pipe_fd[1]);
// 		i++;
// 	}
// 	pipe(pipe_fd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		dup2(in_fd, STDIN_FILENO);
// 		if (in_fd != STDIN_FILENO)
// 			close(in_fd);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		execve(cmd[i][0], cmd[i] + 1, NULL);
// 	}
// 	waitpid(pid, &status, 0);
// 	if (in_fd != STDIN_FILENO)
// 		close(in_fd);
// 	close(pipe_fd[0]);
// 	close(pipe_fd[1]);
// 	printf("exit code %s\n", status);
// 	//  * lst command.
// }

// int	main(void)
// {
// 	char *cmd1[] = {"/usr/bin/ls", "ls", "-l", NULL};
// 	char *cmd2[] = {"/usr/bin/grep", "grep", "Makefile", NULL};
// 	char *cmd3[] = {"/usr/bin/echo", "echo", "hello", "world", NULL};
// 	char **cmds[] = {cmd1, cmd2, cmd3};
// 	// int i = 0;
// 	// while (i < 3)
// 	// {
// 	// 	int j = 0;
// 	// 	printf("path: %s\n",cmds[i][0]);
// 	//     // printf("first cmd %s\n", *(cmds[i] + 1));
// 	// 	i++;
// 	// }
// 	ex(cmds);
// }