/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:03:06 by ameskine          #+#    #+#             */
/*   Updated: 2025/06/22 22:35:33 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void is_built_in(t_list *lst, t_env *lst1)
// {
//     if (!ft_strcmp(lst->content, "cd"))
//         ft_cd(lst, lst1);
//     else if (!ft_strcmp(lst->content, "pwd"))
//         ft_pwd();
//     else if (!ft_strcmp(lst->content, "export"))
//         ft_export(lst, lst1);
//     // else if (ft_strcmp(lst->content, "unset"))
//     //     ft_unset();
//     // else if (ft_strcmp(lst->content, "echo"))
//     //     ft_echo();
//     // else if (ft_strcmp(lst->content, "env"))
//     //     ft_env();
//     else if (!ft_strcmp(lst->content, "exit"))
//         ft_exit(lst);
//     else
//         return ;
// }

int main(int ac, char **av, char **env)
{
    int i = 0;
    t_list *lst;
    t_list *envi;

    lst = NULL;
    envi = NULL;
    // data = NULL;
    while (env[i])
    {
        set_envi(&envi ,env[i]);
        i++;
    }
    i = 1;
    while (i < ac)
    {
        ft_add_back(&lst, ft_new_node(av[i]));
        i++;
    }
    while (envi)
    {
        // printf("%s\n",(t_env *)envi->content->key);
        // printf("%s\n",(t_env *)envi->content->value); 
        printf("%s\n", ((t_env *)envi->content)->key);
        printf("%s\n", ((t_env *)envi->content)->value);
        envi = envi->next;
    }
}
