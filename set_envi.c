/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:49:03 by ameskine          #+#    #+#             */
/*   Updated: 2025/06/23 16:13:04 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *get_key(char *env)
{
    int i = 0;
    char *key = NULL;
    while (env[i])
    {
        if (env[i] == '=')
            break;
        i++;
    }
    i++;
    key = ft_substr(env, 0, i);
    return (key);
}

char *get_value(char *env)
{
    char *value = NULL;
    int i = 0;
    while (env[i])
    {
        if (env[i] == '=')
            break;
        i++;
    }
    i++;
    value = ft_substr(env, i, ft_strlen(env));
    return (value);
}

t_env   *init_env(char *key, char *value)
{
    t_env *lst = malloc(sizeof(t_env));
    if (!lst)
        return (NULL);
    lst->key = key;
    lst->value = value;
    return (lst);
}

void    set_envi(t_list **envi, char *env)
{
    t_env *lst = NULL;
    lst = init_env(get_key(env), get_value(env));
    if (!lst)
        return ;
    ft_add_back(envi, ft_new_node(lst));
}