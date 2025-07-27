/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/05/16 10:09:31 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 16:24:00 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"


void	get_cmd(t_node_infos *infos)
{
	t_cmd *cmd;

	while (infos->data)
	{
		cmd = infos->data->content;
		if (cmd->index == infos->index)
		{
			infos->head = infos->data;
			return ;
		}
		infos->data = infos->data->next;
	}
}

void	execute_cmd(t_node_infos *infos)
{
	char *path;
	char **content;

	get_cmd(infos);
	// t_list *temp = infos->head;
	// printf("===> node:\n");
	// while (temp)
	// {
	// 	if (((t_cmd *)temp->content)->type == TOKEN_PIPE)
	// 		break ;
	// 	printf("   %s\n", ((t_cmd *)temp->content)->component);
	// 	temp = temp->next;
	// }
	exit(0);
	// dup_redirections(infos->head);
	// get_valid_path(&path, infos->head); // TODO
	// path = ft_strjoin("/usr/bin/",
	// 		((t_cmd *)infos->head->content)->arr_content[0]);
	// execve(path, ((t_cmd *)infos->head->content)->arr_content, NULL);
	// dprintf(2,
		// "%s command not found\n",((t_cmd *)infos->head->content)->arr_content[0]);
}
