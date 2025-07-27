/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:19:11 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/19 21:03:42 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	ft_lst_clear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	free_env_node(void *content)
{
	t_env *env_node = (t_env *)content;
	if (env_node)
	{
		free(env_node->key);
		free(env_node->value);
		free(env_node);
	}
}

int	is_built_in(t_list *lst)
{
    if (!ft_strcmp(lst->content, "cd"))
        return (1);
    else if (!ft_strcmp(lst->content, "pwd"))
        return (1);
    else if (!ft_strcmp(lst->content, "export"))
        return (1);
    else if (!ft_strcmp(lst->content, "echo"))
        return (1);
    else if (!ft_strcmp(lst->content, "env"))
        return (1);
    else if (!ft_strcmp(lst->content, "exit"))
        return (1);
    else if (!ft_strcmp(lst->content, "unset"))
        return (1);
    else
        return (0);
}