/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:00:46 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/26 15:31:30 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	*allocate(t_list **list, int size)
{
	void	*address;
	t_list	*node;

	address = malloc(size);
	if (!address)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = address;
	node->next = NULL;
	node->prev = NULL;
	ft_lstadd_back(list, node);
	return (address);
}

void	free_(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
}

void	*gc_malloc_local(int size, t_gc_target target, t_gc_action action)
{
	static t_list	*env_list;
	static t_list	*regulare_list;

	if (action == GC_ALLOCATE)
	{
		if (target == GC_REGULARE)
			return (allocate(&regulare_list, size));
		else if (target == GC_ENV_LIST)
			return (allocate(&env_list, size));
	}
	if (action == GC_FREE)
	{
		if (target == GC_REGULARE)
		{
			return (free_(regulare_list), regulare_list = NULL, (void *)0);
		}
		else if (target == GC_ENV_LIST)
			return (free_(env_list), env_list = NULL, (void *)0);
	}
}
