/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:05:03 by ameskine          #+#    #+#             */
/*   Updated: 2025/06/24 17:27:27 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    list_to_arr()
{}

void sort(t_list *lst1)
{
    char *temp;
    int i;
    int j;

    i = 0;
    while (lst1->my_env[i])
    {
        j = i + 1;
        while (lst1->my_env[j])
        {
            if (ft_strcmp(lst1->my_env[i], lst1->my_env[j]) > 0)
            {
               temp =  lst1->my_env[i];
               lst1->my_env[i] = lst1->my_env[j];
               lst1->my_env[j] = temp;
            }
            j++;
        }
        i++;
    }
}

// t_n    *after_equal(t_n *lst)
// {
//     int i; 

//     i = 0;
//     while (lst->my_env[i])
//     {
//         j = 0;
//         while (lst->my_env[i][j] && )
//         {
//             if (lst->my_env[i][j] == '=')
//             {
//                 lst->my_env[i] = ft_strjoin(lst->my_env[i], ft_strdup("\""));
//             }
//             j++;
//         }
//         i++;
//     }
//     return (lst);
// }

void	equel_implementation(t_n *lst1)
{
    int i;
    int j;
    t_n *lst2; 

    i = 0;
    j = 0;
    lst2 = NULL;
    while (lst1->my_env[i])
    {
        j = 0;
        lst1->my_env[i] = ft_strjoin(ft_strdup("declare -x "), lst1->my_env[i]);
        while (lst1->my_env[i][j])
        {
            if (lst1->my_env[i][j] == '=')
            {
                lst1->my_env[i] = ft_strjoin(lst1->my_env[i], ft_strdup("\""));
            }
            j++;
        }
        lst1->my_env[i] = ft_strjoin(lst1->my_env[i], ft_strdup("\""));
        i++;
    }
}

void    ft_export(t_n *lst1)
{
    // int i;

    // i = ft_lst_size(lst);
    sort(lst1);
    equel_implementation(lst1);
}