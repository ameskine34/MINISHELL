/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:55:32 by ameskine          #+#    #+#             */
/*   Updated: 2025/06/24 11:27:57 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    check_option(char *s)
{
    int i;

    i = 1;
    if (!s || s[0] != '-')
        return (0);
    while (s[i])
    {
        if (s[i] != 'n')
            return (0);
        i++;
    }
    return (1);
} 

void    ft_echo(t_list *lst)
{
    int new_line;
    t_list *lst1;

    lst = lst->next;
    new_line = 0;
    while (lst && check_option(lst->content))
    {
        new_line = 1;
        lst = lst->next;
    }
    lst1 = lst;
    while (lst1->next)
    {
        write(1,lst1->content, ft_strlen(lst1->content));
        lst1 = lst1->next;
        if (lst1->next)
            write(1," ",1);
    }
    if (!new_line)
        write(1,"\n",1);
}