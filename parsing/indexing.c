/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:31:12 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/14 16:36:19 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	indexing(t_list *data)
{
	int i;
	t_cmd *cmd;

	i = 0;
	while (data)
	{
		cmd = data->content;
		if (cmd->type != TOKEN_PIPE)
			cmd->index = i;
		if (cmd->type == TOKEN_PIPE)
			i++;
		data = data->next;
	}
}