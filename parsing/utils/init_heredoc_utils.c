/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:20:54 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/06 11:02:14 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_ranstring(void)
{
	char	*result;
	int		fd;
	int		i;
	char	b;

	result = gc_malloc(21);
	if (!result)
		return (NULL);
	fd = safe_open("/dev/random", O_RDONLY, 0);
	if (fd < 0)
		return (NULL);
	i = -1;
	while (i < 20)
	{
		read(fd, &b, 1);
		if (ft_isalnum(b))
			result[++i] = b;
	}
	close(fd);
	result[i] = '\0';
	return (result);
}

void	heredoc_ctrl_c(int sig)
{
	if (sig == SIGINT)
	{
		free_env_list();
		free_regulare();
		gc_fds(0, GC_FREE);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		exit(130);
	}
}

void	heredoc_ctrl_d(char *delimiter)
{
	char	*count_line;

	count_line = ft_itoa(*count_lines());
	write(2, "bash: warning: here-document at line ", 37);
	write(2, count_line, ft_strlen(count_line));
	write(2, " delimited by end-of-file (wanted `", 35);
	write(2, delimiter, ft_strlen(delimiter));
	write(2, "')\n", 3);
	free_env_list();
	free_regulare();
	gc_fds(0, GC_FREE);
	exit(0);
}
