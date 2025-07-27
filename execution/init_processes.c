/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/05/27 14:56:34 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 16:11:24 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	init_processes(t_node_infos *infos) // i need the env in the argument;
{
	int n_of_cmd;
	int pid;
	int i;

	n_of_cmd = infos->num_of_processes;
	infos->in_fd = STDIN_FILENO;
	i = 0;
	while (i < n_of_cmd)
	{
		infos->index = i;
		if (i < n_of_cmd - 1)
		{
			if (pipe(infos->pipe_fd) < 0)
			{
				perror("pipe");
				// infos->exit_status = 1;
			}
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			// infos->exit_status = 1;
		}
		else if (pid == 0)
		{
			execute_cmd(infos);
			if (infos->in_fd != STDIN_FILENO)
			{
				dup2(infos->in_fd, STDIN_FILENO);
				close(infos->in_fd);
			}
			if (i < n_of_cmd - 1)
			{
				close(infos->pipe_fd[0]); // Close the read end of the new pipe
				dup2(infos->pipe_fd[1], STDOUT_FILENO);
				close(infos->pipe_fd[1]);
			}
			// is_built_in(data, &env, i); // to pass it to built_in
		}
		else
		{
			if (infos->in_fd != STDIN_FILENO)
				close(infos->in_fd);
			if (i < n_of_cmd - 1)
			{
				close(infos->pipe_fd[1]);
				infos->in_fd = infos->pipe_fd[0];
			}
		}
		i++;
	}
	while (wait(NULL) > 0)
		;
}

