/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:03:06 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/03 22:50:59 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void is_built_in(t_list *lst, t_list **lst1)
{
    if (!ft_strcmp(lst->content, "cd"))
        ft_cd(lst, *lst1);
    else if (!ft_strcmp(lst->content, "pwd"))
        ft_pwd();
    // else if (!ft_strcmp(lst->content, "export"))
    //     ft_export(lst, lst1);
    else if (!ft_strcmp(lst->content, "echo"))
        ft_echo(lst);
    // else if (ft_strcmp(lst->content, "unset"))
    //     ft_unset();
    // else if (ft_strcmp(lst->content, "env"))
    //     ft_env(*lst1);
    else if (!ft_strcmp(lst->content, "exit"))
        ft_exit(lst);
    else
        return ;
}

// int main(int ac, char **av, char **env)
// {
//     int i = 0;
//     t_list *lst;
//     t_list *envi;

//     lst = NULL;
//     envi = NULL;
//     // data = NULL;
//     while (env[i])
//     {
//         set_envi(&envi ,env[i]);
//         i++;
//     }
//     i = 0;
//     while (i < ac)
//     {
//         ft_add_back(&lst, ft_new_node(ft_strdup(av[i+1])));
//         i++;
//     }
//     is_built_in(lst, &envi);
//     while (envi)
//     { 
//         printf("%s", ((t_env *)envi->content)->key);//The (t_env *) typecast is essential for informing the compiler about 
//         // the actual data type stored in the void *content member of your linked list node. 
//         // It allows you to correctly access the key and value members of your t_env structure,
//         //  preventing compilation errors and ensuring proper memory interpretation.
//         printf("%s\n", ((t_env *)envi->content)->value);
//         envi = envi->next;
//     }
// }
int main(int ac, char **av, char **env)
{
    t_list *lst1;
    t_list *lst;
    int i;

    i = 0;
    while (env[i])
    {
        set_envi(&lst1, env[i]);
        i++;
    }
    i = 0;
    while (i < ac)
    {
        ft_add_back(&lst, ft_new_node(ft_strdup(av[i+1])));
        i++;
    }
    execution_phase(lst, lst1);
}