/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:05:03 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/08 19:09:56 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void    swap_env_nodes(t_list *a, t_list *b)
{
    void *tmp;

    tmp = a->content;
    a->content = b->content;
    b->content = tmp;
}

static void    sort_list(t_list *env)
{
    t_list *env_current;
    t_list *env_next;

    env_current = env;
    if (env == NULL)
        return ;
    while (env_current)
    {
        env_next = env_current->next;
        while (env_next)
        {
            if (ft_strcmp(((t_env *)env_current->content)->key, ((t_env *)env_next->content)->key) > 0)
            {
                swap_env_nodes(env_current, env_next);
            }
            env_next = env_next->next;
        }
        env_current = env_current->next;
    }
}

// void    swap_env(char **s, char **s2)
// {
//     char *tmp;

//     tmp = *s;
//     *s = *s2;
//     *s2 = tmp;
// }

// void    sort_env(char **env)
// {
//     int i;
//     int j;

//     i = 0;
//     if (!env || !*env)
//         return ;
//     while (env[i])
//     {
//         j = i+1;
//         while (env[j])
//         {
//             if (ft_strcmp(env[i], env[j]) > 0)
//             {
//                 swap_env(&env[i], &env[j]);
//             }
//             j++;
//         }
//         i++;
//     }
// }
static int     is_alpha(int c)
{
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

static int     is_valid_key(char *key)
{
    int i;

    i = 0;
    while (key[i])
    {
        if (!is_alpha(key[i]))
            return (0);
        i++;
    }
    return (1);
}

static void    update_or_add_env(t_list **env, char *key, char *value)
{
    t_list *envi;
    
    envi = *env;
    while (envi)
    {
        if (!ft_strcmp(((t_env *)envi->content)->key, key))
        {
            free(((t_env *)envi->content)->value);
            (((t_env *)envi->content)->value) = ft_strdup(value);
            return ;
        }
        envi = envi->next;
    }
    ft_add_back(&envi, ft_new_node(init_env(key, value)));
}

void    ft_export(t_list *lst, t_list *env)
{
    char *equal_sign;
    t_list *temp_env;
    t_list *args;
    char *value;
    char *key;
        
    args = lst->next;
    if (ft_lst_size(lst) == 1)
    {
        sort_list(env);
        temp_env = env;
        while (temp_env)
        {
            printf("%s", "declare -x ");
            printf("%s", ((t_env *)temp_env->content)->key);
            printf("%s", "=\"");
            printf("%s", ((t_env *)temp_env->content)->value);
            printf("%s\n", "\"");
            temp_env = temp_env->next;
        }
    }
    else
    {
        while (args)
        {
            equal_sign = ft_strchr1(args->content, '=');
            if (equal_sign)
            {
                key = ft_substr(args->content, 0, equal_sign - (char *)args->content);
                value = ft_strdup(equal_sign + 1);        
            }
            else if (!is_valid_key(key))
            {
                ft_printf("minishell: export: `", 2);
                ft_printf(args->content, 2);
                ft_printf("': not a valid identifier\n", 2);
                free(key);
                free(value);
            }
            else
            {
                update_or_add_env(&env, key, value);
                free(key);
                free(value);
            }
            args = args->next;
        }
    }
}

