/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:00:16 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 15:06:16 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"
#include <fcntl.h>
#include <signal.h>

int	get_num_of_pipes(t_list *data)
{
	int		i;
	t_cmd	*cmd;


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

void	execution(t_node_infos *infos)
{
	t_list		*command_arg;
	int				pid;
	int				i;

	command_arg = (((t_cmd*)infos->data->content)->command_head);
	infos->num_of_pipes = get_num_of_pipes(infos->data);
	infos->num_of_processes = infos->num_of_pipes + 1;
	// while (command_arg)
	// {
	// 	printf("%s\n", (char *)command_arg->content);
	// 	command_arg = command_arg->next;
	// }
	if (infos->num_of_processes ==  1 && is_built_in(command_arg))
		execute_built_in(command_arg, &(infos->env));
	else
		init_processes(infos);
}