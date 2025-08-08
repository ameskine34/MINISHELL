/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/29 09:27:50 by yaithadd          #+#    #+#             */
/*   Updated: 2025/06/01 14:40:06 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*init_cmd_node(char *component, char **subcomponents)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)gc_malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->type = 0;
	cmd->component = component;
	cmd->subcomponents = subcomponents;
	cmd->has_word = 0;
	cmd->raw_exp = NULL;
	cmd->composed_exp = NULL;
	cmd->resolved_exp = NULL;
	cmd->arr_content = NULL;
	cmd->heredoc_fd_read = -1;
	cmd->index = -1;
	cmd->has_ambiguous_redir = 0;
	cmd->command_head = NULL;
	cmd->skip_node = 0;
	cmd->skip_dollar = 0;
	return (cmd);
}

t_node_infos	*init_node_infos(void)
{
	t_node_infos	*infos;

	infos = gc_malloc(sizeof(t_node_infos));
	if (!infos)
		return (NULL);
	infos->data = NULL;
	infos->cwd = NULL;
	infos->env = NULL;
	infos->head = NULL;
	infos->index = 0;
	infos->num_of_pipes = 0;
	infos->num_of_processes = 0;
	return (infos);
}
