/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/05/27 13:38:24 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 16:23:00 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	dup_(t_list *data, int t_o_r, int is_child, int *ret)
{
	int		fd;
	char	*filename;

	if (data->next)
		filename = ((t_cmd *)data->next->content)->component;
	fd = -1;
	if (t_o_r == TOKEN_IN_REDIRECTION)
		fd = safe_open(filename, O_RDONLY, is_child);
	else if (t_o_r == TOKEN_OUT_REDIRECTION_OVERWRITE)
		fd = safe_open(filename, O_RDWR | O_CREAT | O_TRUNC, is_child);
	else if (t_o_r == TOKEN_OUT_REDIRECTION_APPEND)
		fd = safe_open(filename, O_RDWR | O_CREAT | O_APPEND, is_child);
	else if (t_o_r == TOKEN_HEREDOC)
		fd = ((t_cmd *)data->content)->heredoc_fd_read;
	if (fd < 0)
		return (*ret = 1, (void)0);
	if (t_o_r == TOKEN_IN_REDIRECTION || t_o_r == TOKEN_HEREDOC)
		dup2(fd, 0);
	else
		dup2(fd, 1);
	close(fd);
}

int	dup_redirections(t_list *head, int is_child)
{
	int	type_of_redirection;
	int	return_value;

	type_of_redirection = 0;
	return_value = 0;
	while (head)
	{
		if (((t_cmd *)head->content)->type == TOKEN_PIPE)
			break ;
		type_of_redirection = ((t_cmd *)head->content)->type;
		if (type_of_redirection >= 2 && type_of_redirection <= 5)
			dup_(head, type_of_redirection, is_child, &return_value);
		if (return_value == -1)
			break ;
		head = head->next;
	}
	return (return_value);
}
