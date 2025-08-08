/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/05/04 15:06:43 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/12 20:09:41 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tokenization(t_list *data)
{
	t_cmd	*cmd;

	while (data)
	{
		cmd = (t_cmd *)data->content;
		if (cmd->type == TOKEN_WORD)
		{
			data = data->next;
			continue ;
		}
		if (cmd->type == TOKEN_OPERATION)
		{
			cmd->type = check_for_operations(data);
			if (cmd->type >= TOKEN_OUT_REDIRECTION_OVERWRITE
				&& cmd->type <= TOKEN_HEREDOC)
				if (data->next)
					((t_cmd *)data->next->content)->type = TOKEN_FILE;
		}
		if (cmd->type == 0)
			cmd->type = TOKEN_ARGUMENT;
		data = data->next;
	}
}
