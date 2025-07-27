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

#include "../includes/parsing.h"


//  echo > echo < echo | echo >  echo >> dd | ls -l -la -lld

t_cmd	*init_cmd_node(char *component, char **subcomponents)
{
	t_cmd *cmd;

	cmd = (t_cmd *)gc_malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->type = 0;
	cmd->component = component;
	cmd->subcomponents = subcomponents;
	cmd->raw_exp = NULL;
	cmd->composed_exp = NULL;
	cmd->resolved_exp = NULL;
	cmd->arr_content = NULL;
	cmd->heredoc_filename = NULL;
	cmd->index = -1;
	cmd->has_ambiguous_redir = 0;
	cmd->command_head = NULL;
	return (cmd);
}

t_node_infos	*init_node_infos(t_list *data, t_list *env)
{
	t_node_infos *infos;

	infos = gc_malloc(sizeof(t_node_infos));
	if (!infos)
		return (NULL);
	infos->data = data;
	infos->env = env;
	infos->head = NULL;
	infos->index = 0;
	infos->num_of_pipes = 0;
	infos->num_of_processes = 0;
	infos->shell_level = 0;
	return (infos);
}
