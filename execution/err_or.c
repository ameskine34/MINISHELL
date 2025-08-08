/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:48:32 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/06 08:35:45 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_err_or(char *token, char *msg)
{
	char	*ms;

	ms = ft_strdup("basha: ");
	if (token)
	{
		ms = ft_strjoin(ms, token);
		ms = ft_strjoin(ms, ": ");
	}
	if (ms)
	{
		ms = ft_strjoin(ms, msg);
		ms = ft_strjoin(ms, "\n");
	}
	write(2, ms, ft_strlen(ms));
}

void	err_or(char *token, int code)
{
	if (code == CODE_PERM_DENIED)
		return (print_err_or(token, MSG_PERM_DENIED), free_regulare(),
			free_env_list(), exit(126));
	if (code == CODE_CMD_NOT_FOUND)
		return (print_err_or(token, MSG_CMD_NOT_FOUND), free_regulare(),
			free_env_list(), exit(127));
	if (code == CODE_N_S_F_O_D)
		return (print_err_or(token, MSG_N_S_F_O_D), free_regulare(),
			free_env_list(), exit(127));
	if (code == CODE_IS_DIRECTORY)
		return (print_err_or(token, MSG_IS_DIRECTORY), free_regulare(),
			free_env_list(), exit(126));
	if (code == CODE_FILE_NAME_TO_LONG)
		return (print_err_or(token, MSG_FILE_NAME_TOO_LONG), free_regulare(),
			free_env_list(), exit(126));
	if (code == CODE_SYS_CALL)
		return (perror("basha: "), free_regulare(), free_env_list(), exit(1));
}
