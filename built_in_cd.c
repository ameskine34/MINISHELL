/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:23:48 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/03 22:42:16 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd_changes(t_list *envi, char *current, char *new)
{
    while (envi)
    {
        if (!ft_strncmp("PWD", ((t_env*)envi->content)->key, 3))
        {
            free(((t_env *)envi->content)->value);
            ((t_env *)envi->content)->value = ft_strdup(new);
        }
        else if (!ft_strncmp("OLDPWD", ((t_env*)envi->content)->key, 6))
        {
            free(((t_env *)envi->content)->value);
            ((t_env *)envi->content)->value = ft_strdup(current);
        }
        envi = envi->next;
    }
}

void    ft_cd(t_list *lst, t_list *envi)
{
    int i; 
    char *current;
    char *new;
    int k;

    k = ft_lst_size(lst);
    if (k == 1)
    {
        current = getcwd(NULL, 0); // will be the new OLDPWD
        i = chdir(getenv("HOME"));
        if (i == 0)
        {
            new = getcwd(NULL, 0); // will be the new PWD
            pwd_changes(envi, current, new);
        }
    }
    else if (k == 2)
    {
        current = getcwd(NULL, 0); // will be the new OLDPWD
        if (!chdir(lst->next->content))
        {
                new = getcwd(NULL, 0); // will be the new PWD
                pwd_changes(envi, current, new);
        }
        else if (!ft_strncmp("..", lst->next->content, 2) && chdir(lst->next->content))
        {
            ft_printf("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory"); // i have to write in the stderror
            exit(0);
        }
        else
        {
            ft_printf("bash: cd: ");
            ft_printf("%s", lst->next->content);
            ft_printf(" No such file or directory\n");
            exit(1);
        }
    }
    else if (k > 2)
    {
        ft_printf("bash: cd: too many arguments");
        exit(1); //i have to return till running the minishell again 
    }
}