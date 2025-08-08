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

#include "../includes/minishell.h"

void	child_exec(t_node_infos *infos, int n_of_cmd, int i)
{
	if (infos->in_fd != STDIN_FILENO)
	{
		dup2(infos->in_fd, STDIN_FILENO);
		close(infos->in_fd);
	}
	if (i < n_of_cmd - 1)
	{
		close(infos->pipe_fd[0]);
		dup2(infos->pipe_fd[1], STDOUT_FILENO);
		close(infos->pipe_fd[1]);
	}
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	execute_cmd(infos);
}

void	parent_exec(t_node_infos *infos, int n_of_cmd, int i)
{
	signal(SIGINT, SIG_IGN);
	if (infos->in_fd != STDIN_FILENO)
		close(infos->in_fd);
	if (i < n_of_cmd - 1)
	{
		close(infos->pipe_fd[1]);
		infos->in_fd = infos->pipe_fd[0];
	}
}

void	to_wait(int towait)
{
	int	status;

	waitpid(towait, &status, 0);
	while (wait(NULL) != -1)
		;
	*exit_status() = set_exit_status_code(status);
	init_signals();
}

void	add_pipes_to_garbage(t_node_infos *infos)
{
	gc_fds(infos->pipe_fd[0], GC_ALLOCATE);
	gc_fds(infos->pipe_fd[1], GC_ALLOCATE);
}

void	init_processes(t_node_infos *infos)
{
	int (n_of_cmd), pid, i, towait;
	n_of_cmd = infos->num_of_processes;
	infos->in_fd = STDIN_FILENO;
	i = 0;
	while (i < n_of_cmd)
	{
		infos->index = i;
		if (i < n_of_cmd - 1)
		{
			if (pipe(infos->pipe_fd) < 0)
				return (perror("pipe: "), free_regulare(), gc_fds(0, GC_FREE));
			add_pipes_to_garbage(infos);
		}
		pid = fork();
		if (i == n_of_cmd - 1)
			towait = pid;
		if (pid == -1)
			return (perror("fork: "), free_regulare(), gc_fds(0, GC_FREE));
		else if (pid == 0)
			child_exec(infos, n_of_cmd, i);
		parent_exec(infos, n_of_cmd, i);
		i++;
	}
	to_wait(towait);
}
