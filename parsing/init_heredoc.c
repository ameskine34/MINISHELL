/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:07:15 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/07 14:19:18 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	read_content(int fd, char *delimiter, int expand, t_list *env)
{
	char	*str;

	signal(SIGINT, heredoc_ctrl_c);
	while (1)
	{
		str = readline("> ");
		if (!str)
			heredoc_ctrl_d(delimiter);
		if (check_for_string(str, delimiter))
		{
			free_env_list();
			free_regulare();
			gc_fds(0, GC_FREE);
			exit(0);
		}
		if (expand)
		{
			str = expand_double_quotes_var(str, env);
			str = ft_strjoin(str, "\n");
		}
		else
			str = ft_strjoin(str, "\n");
		write(fd, str, ft_strlen(str));
	}
}

int	expand(char **comp)
{
	int	i;

	i = 0;
	if (comp)
	{
		while (comp[i])
		{
			if (comp[i][0] == '"' || comp[i][0] == '\'')
				return (0);
			i++;
		}
	}
	return (1);
}

int	open_read_write_herdoc(char *file_name, int *fd_write, int *fd_read)
{
	*fd_write = safe_open(file_name, O_CREAT | O_RDWR, 0);
	if (*fd_write < 0)
		return (1);
	gc_fds(*fd_write, GC_ALLOCATE);
	*fd_read = safe_open(file_name, O_RDONLY, 0);
	if (*fd_read < 0)
		return (1);
	gc_fds(*fd_read, GC_ALLOCATE);
	return (0);
}

int	heredoc(t_cmd *cmd_node, t_list *env)
{
	int		fd;
	int		pid;
	char	*delimiter;
	char	*file_name;
	int		status;

	file_name = ft_ranstring();
	if (!file_name)
		return (1);
	delimiter = get_raw_exp(cmd_node, 0);
	if (open_read_write_herdoc(file_name, &fd, &(cmd_node->heredoc_fd_read)))
		return (unlink(file_name), 1);
	unlink(file_name);
	pid = fork();
	if (pid == 0)
		read_content(fd, delimiter, expand(cmd_node->subcomponents), env);
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	init_signals();
	*exit_status() = set_exit_status_code(status);
	if (*exit_status() == 130)
		return (1);
	close(fd);
	return (0);
}

int	init_heredoc(t_list *data, t_list *env)
{
	while (data)
	{
		if (check_for_string(((t_cmd *)data->content)->component, "<<")
			&& ((t_cmd *)data->content)->subcomponents)
			if (heredoc(((t_cmd *)data->content), env))
				return (1);
		data = data->next;
	}
	return (0);
}
