/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_data_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:43:37 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/24 13:12:11 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	remove_node(t_list **data)
{
	t_list	*temp;

	temp = (*data)->next;
	if ((*data)->prev)
		(*data)->prev->next = (*data)->next;
	if ((*data)->next)
		(*data)->next->prev = (*data)->prev;
	// free_cmd_node((*data)->content);
	// free(*data);
	(*data) = temp;
}

void	join_nodes(t_list **data)
{
	t_list	*head;
	t_list	*temp;
	char	*result;

	head = (*data);
	result = ft_strdup("");
	while (*data)
	{
		if (((t_cmd *)(*data)->content)->type == TOKEN_OPERATION
			|| ((t_cmd *)(*data)->content)->type == TOKEN_SPACE)
			break ;
		temp = (*data)->next;
		result = ft_strjoin(result, ((t_cmd *)(*data)->content)->component);
		if (*data != head)
		{
			// free_cmd_node((*data)->content);
			// free(*data);
		}
		(*data) = temp;
	}
	// free(((t_cmd *)head->content)->component);
	((t_cmd *)head->content)->component = result;
	head->next = (*data);
	if (*data)
		(*data)->prev = head;
}

void	join_data_list(t_list **data)
{
	t_list	*head;
	t_list	*temp;
	t_cmd	*cmd_node;

	while (*data && ((t_cmd *)(*data)->content)->type == TOKEN_SPACE)
	{
		temp = (*data)->next;
		// free_cmd_node((*data)->content);
		// free(*data);
		(*data) = temp;
	}
	head = *data;
	while (*data)
	{
		if (((t_cmd *)(*data)->content)->type != TOKEN_SPACE
			&& ((t_cmd *)(*data)->content)->type != TOKEN_OPERATION)
			join_nodes(data);
		if (*data && ((t_cmd *)(*data)->content)->type == TOKEN_SPACE)
			remove_node(data);
		if (*data && ((t_cmd *)(*data)->content)->type == TOKEN_OPERATION)
			(*data) = (*data)->next;
	}
	(*data) = head;
}
