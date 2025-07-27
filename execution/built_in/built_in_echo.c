/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:55:32 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/25 17:14:26 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

int    check_option(char *s)
{
    int i;

    i = 1;
    if (!s || s[0] != '-' || ft_strlen(s) == 1)
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

    new_line = 0;
    lst1 = lst->next;
    while (lst1 && check_option(lst1->content))
    {
        new_line = 1;
        lst1 = lst1->next;
    }
    while (lst1)
    {
        write(1,lst1->content, ft_strlen(lst1->content));
        lst1 = lst1->next;
        if (lst1)
            write(1," ",1);
    }
    if (!new_line)
        write(1,"\n",1);
}