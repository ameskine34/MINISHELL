/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:03:28 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 14:57:01 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_num_of_pipes(t_list *data)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	while (data)
	{
		cmd = data->content;
		if (cmd->type == TOKEN_PIPE)
			i++;
		data = data->next;
	}
	return (i);
}
