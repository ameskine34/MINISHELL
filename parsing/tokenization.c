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

#include "../includes/parsing.h"


void	tokenization(t_list *data)
{
	t_cmd *cmd;

	while (data)
	{
		cmd = (t_cmd *)data->content;
		if (!data->prev || (data->prev
				&& check_for_string(((t_cmd *)data->prev->content)->component,
					"|")))
			cmd->type = TOKEN_COMMAND;
		if (((t_cmd *)data->content)->type == TOKEN_OPERATION)
			((t_cmd *)data->content)->type = check_for_operations(data);
		if (data->prev
			&& check_for_redirections(((t_cmd *)data->prev->content)->component))
			cmd->type = TOKEN_FILE;
		if (cmd->type == 0)
			cmd->type = TOKEN_ARGUMENT;
		data = data->next;
	}
}
