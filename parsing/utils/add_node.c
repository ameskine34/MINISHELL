/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:00:22 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/19 15:23:51 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_cmd *add_node(t_list **data, char *component, char **subcomponents)
{
	t_cmd	*cmd_node;

	cmd_node = init_cmd_node(component, subcomponents);
	ft_lstadd_back(data, ft_lstnew((void *)cmd_node));
	return (cmd_node);
}
