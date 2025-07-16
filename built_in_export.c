/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:05:03 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/16 12:56:59 by ameskine         ###   ########.fr       */
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

static int     is_alphanum_or_underscore(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '_');
}

static int     is_valid_key(char *key)
{
    int i;

    if (!key || !key[0])
        return (0);
    if (!((key[0] >= 'A' && key[0] <= 'Z') || (key[0] >= 'a' && key[0] <= 'z') || key[0] == '_'))
        return (0);
    i = 1;
    while (key[i])
    {
        if (!is_alphanum_or_underscore(key[i]))
            return (0);
        i++;
    }
    return (1);
}

void    update_or_add_env(t_list **env, char *key, char *value, int *is_equal_sign)
{
    t_list *envi;
    
    envi = *env;
    while (envi)
    {
        if (!ft_strcmp(((t_env *)envi->content)->key, key) && *is_equal_sign)
        {
            free(((t_env *)envi->content)->value);
            (((t_env *)envi->content)->value) = ft_strdup(value);
            return ;
        }
        else if (!ft_strcmp(((t_env *)envi->content)->key, key) && !*is_equal_sign)
            return ;
        envi = envi->next;
    }
    ft_add_back(env, ft_new_node(init_env(ft_strdup(key), ft_strdup(value))));
}

void    ft_export(t_list *lst, t_list *env)
{
    char *equal_sign;
    t_list *temp_env;
    t_list *args;
    char *value;
    char *key;
    int is_equal_sign;

    is_equal_sign = 0;
    equal_sign = NULL;
    args = lst->next;
    temp_env = NULL;
    value = NULL;
    key = NULL;
    if (ft_lst_size(lst) == 1)
    {
        sort_list(env);
        temp_env = env;
        while (temp_env)
        {
            if (((t_env *)temp_env->content)->key)
            {
                printf("%s", "declare -x ");
                printf("%s", ((t_env *)temp_env->content)->key);
            }
            if (((t_env *)temp_env->content)->value)
            {   if (((t_env *)temp_env->content)->value[0] != '\"')
                    printf("%s", "=\"");
                else
                    printf("=");
                printf("%s", ((t_env *)temp_env->content)->value);
                if (((t_env *)temp_env->content)->value[ft_strlen(((t_env *)temp_env->content)->value - 1)] != '\"')
                    printf("%s\n", "\"");
                else
                    printf("\n");
            }
            else
                printf("\n");
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
                is_equal_sign = 1;
                key = ft_substr(args->content, 0, equal_sign - (char *)args->content);
                value = ft_strdup(equal_sign + 1);    
            }
            else
            {
                is_equal_sign = 0;
                key = ft_strdup(args->content);
                value = NULL;
            }
            if (!is_valid_key(key))
            {
                ft_printf("minishell: export: `", 2);
                ft_printf(args->content, 2);
                ft_printf("': not a valid identifier\n", 2);
                free(key);
                if (value)
                    free(value);
            }
            else
            {
                update_or_add_env(&env, key, value, &is_equal_sign);
                free(key);
                if (value) 
                    free(value);
            }
            args = args->next;
        }
    }
}
