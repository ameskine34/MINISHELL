/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:26:29 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/14 16:58:36 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_unset(t_list *lst, t_list **lst1)
{
    t_list *tmp;
    t_list *current;
    t_list *prev;

    tmp = lst->next;
    if (!tmp)
        return;

    while (tmp)
    {
        current = *lst1;
        prev = NULL;
        while (current)
        {
            if (!ft_strcmp(((t_env *)current->content)->key, tmp->content))
            {
                if (prev == NULL)
                    *lst1 = current->next;
                else
                    prev->next = current->next;
                free_env_node(current->content);
                free(current);
                break;
            }
            prev = current;
            current = current->next;
        }
        tmp = tmp->next;
    }
}