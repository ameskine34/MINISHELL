/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:00:46 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/06 10:28:22 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*allocate(t_list **list, int size)
{
	void	*address;
	t_list	*node;

	address = malloc(size);
	if (!address)
		return (free_regulare(), free_env_list(), gc_fds(0, GC_FREE), write(2,
				"malloc error\n", 13), exit(1), (void *)0);
	node = malloc(sizeof(t_list));
	if (!node)
		return (free_regulare(), free_env_list(), gc_fds(0, GC_FREE), write(2,
				"malloc error\n", 13), exit(1), (void *)0);
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

void	append_add_to_gc(void *add, t_list **env_list, t_list **regular_list,
		t_gc_target target)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (free_regulare(), free_env_list(), gc_fds(0, GC_FREE), write(2,
				"malloc error\n", 13), exit(1));
	node->content = add;
	node->next = NULL;
	node->prev = NULL;
	if (target == GC_REGULARE)
		ft_lstadd_back(env_list, node);
	else if (target == GC_ENV_LIST)
		ft_lstadd_back(regular_list, node);
}

void	*gc_malloc_local(int size, t_gc_target target, t_gc_action action,
		void *add)
{
	static t_list	*env_list;
	static t_list	*regulare_list;

	if (add)
		return (append_add_to_gc(add, &env_list, &regulare_list, target), NULL);
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
	return (NULL);
}
