/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:26:29 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/17 00:53:51 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_unset(t_list *lst, t_list **lst_env)
{
    t_list *current_env;
    t_list *prev_env;
    t_list *tmp;

    current_env = *lst_env;
    prev_env = NULL;
    tmp = lst->next;
    while (current_env)
    {
        if (!ft_strcmp(((t_env *)current_env->content)->key, tmp->content))
        {
            if (prev_env == NULL)
                *lst_env = current_env->next;
            else
                prev_env->next = current_env->next;
            free_env_node(current_env->content);
            free(current_env);
            break; 
        }
        prev_env = current_env;
        current_env = current_env->next;
    }
    tmp = tmp->next;
}