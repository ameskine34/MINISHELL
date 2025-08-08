/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/05/14 10:00:16 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 15:06:16 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	dup_stdin_stdout(int *fd_stdin, int *fd_stdout)
{
	*fd_stdin = dup(STDIN_FILENO);
	gc_fds(*fd_stdin, GC_ALLOCATE);
	*fd_stdout = dup(STDOUT_FILENO);
	gc_fds(*fd_stdout, GC_ALLOCATE);
}

void	close_dup_stdin_stdout(int fd_stdin, int fd_stdout)
{
	close(fd_stdin);
	close(fd_stdout);
}

void	original_stdin_stdout(int fd_stdin, int fd_stdout)
{
	dup2(fd_stdout, 1);
	dup2(fd_stdin, 0);
	close_dup_stdin_stdout(fd_stdin, fd_stdout);
}

void	init_built_in(t_node_infos *infos, t_list *command_arg)
{
	int	fd_stdin;
	int	fd_stdout;

	dup_stdin_stdout(&fd_stdin, &fd_stdout);
	if (dup_redirections(infos->data, 0))
		return (original_stdin_stdout(fd_stdin, fd_stdout));
	execute_built_in(command_arg, &(infos->env), infos);
	original_stdin_stdout(fd_stdin, fd_stdout);
}

void	execution(t_node_infos *infos)
{
	t_list	*command_arg;

	if (!infos->data)
		return (*exit_status() = 0, (void)0);
	alloc_env_list();
	command_arg = (((t_cmd *)infos->data->content)->command_head);
	infos->num_of_pipes = get_num_of_pipes(infos->data);
	infos->num_of_processes = infos->num_of_pipes + 1;
	if (infos->num_of_processes == 1 && is_built_in(command_arg))
		return (init_built_in(infos, command_arg));
	else
		return (init_processes(infos));
}
