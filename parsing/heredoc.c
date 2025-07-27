/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:20:54 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/24 14:33:12 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*ft_ranstring(void)
{
	char	*result;
	int		fd;
	int		i;
	char	b;

	result = gc_malloc(21);
	if (!result)
		return (NULL);
	fd = open("/dev/random", O_RDONLY);
	i = -1;
	while (i < 20)
	{
		read(fd, &b, 1);
		if (ft_isalnum(b))
			result[++i] = b;
	}
	result[i] = '\0';
	return (result);
}

void	ctrl_c(int sig)
{
	if (sig = SIGINT)
		exit(130);
}
// bash: warning: here-document at line 1 delimited by end-of-file (wanted `d')
void	ctrl_d(char *delimiter)
{
	char	*count_line;

	count_line = ft_itoa(*count_lines());
	write(2, "bash: warning: here-document at line ", 37);
	write(2, count_line, ft_strlen(count_line));
	write(2, " delimited by end-of-file (wanted `", 35);
	write(2, delimiter, ft_strlen(delimiter));
	write(2, "')\n", 3);
	*get_action() = GC_FREE;
	*get_target() = GC_REGULARE;
	gc_malloc(0);
	exit(0);
}

void	read_content(int fd, int pid, char *delimiter)
{
	char	*str;

	signal(SIGINT, ctrl_c);
	while (1)
	{
		str = readline("> ");
		if (!str)
			ctrl_d(delimiter);
		if (ft_strlen(str) != 0 && check_for_string(str, delimiter))
		{
			close(fd);
			*get_action() = GC_FREE;
			*get_target() = GC_REGULARE;
			gc_malloc(0);
			exit(0);
			break ;
		}
		str = ft_strjoin(str, "\n");
		write(fd, str, ft_strlen(str));
	}
	*get_action() = GC_FREE;
	*get_target() = GC_REGULARE;
	gc_malloc(0);
}

void	heredoc(t_list *data)
{
	t_cmd	*cmd_node;
	int		fd;
	int		pid;
	char	*delimiter;

	cmd_node = ((t_cmd *)data->content);
	cmd_node->heredoc_filename = ft_ranstring();
	delimiter = get_raw_exp(cmd_node, 0);
	fd = open(cmd_node->heredoc_filename, O_CREAT | O_RDWR, 0777);
	if (fd < 0)
		return ;
	unlink(cmd_node->heredoc_filename);
	pid = fork();
	if (pid == 0)
		read_content(fd, pid, delimiter);
	waitpid(pid, exit_status(), 0);
	close(fd);
	// free(delimiter);
	if (WIFEXITED(*exit_status()))
		*exit_status() = WEXITSTATUS(*exit_status());
}
