/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:20:11 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/07 12:18:26 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_file_error(char *token, char *msg, int is_child, int exit_code)
{
	char	*msg_error;

	msg_error = ft_strdup("basha: ");
	if (token)
	{
		msg_error = ft_strjoin(msg_error, token);
		msg_error = ft_strjoin(msg_error, ": ");
	}
	if (msg)
		msg_error = ft_strjoin(msg_error, msg);
	msg_error = ft_strjoin(msg_error, "\n");
	write(2, msg_error, ft_strlen(msg_error));
	if (is_child)
		return (free_regulare(), free_env_list(), gc_fds(0, GC_FREE),
			exit(exit_code));
	else
		*exit_status() = exit_code;
}

void	file_error(char *token, int code, int is_child)
{
	char	*msg_error;

	if (code == CODE_AMB_REDIRECT)
		return (print_file_error(token, MSG_AMB_REDIRECT, is_child, 1));
	if (code == 0)
	{
		msg_error = ft_strdup("basha: ");
		if (token)
		{
			msg_error = ft_strjoin(msg_error, token);
			msg_error = ft_strjoin(msg_error, ": ");
		}
		write(2, msg_error, ft_strlen(msg_error));
		perror("");
		if (is_child)
			return (free_regulare(), free_env_list(), gc_fds(0, GC_FREE),
				exit(1));
		else
			*exit_status() = 1;
	}
}
