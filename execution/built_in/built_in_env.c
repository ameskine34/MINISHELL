/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:46:50 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/19 20:21:06 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void    ft_env(t_list *envi)
{
    while (envi)
    {
        if (((t_env*)envi->content)->value)
        {
            write(1 , ((t_env*)envi->content)->key, ft_strlen(((t_env*)envi->content)->key));
            write(1 , "=", 1);
            write(1 , ((t_env*)envi->content)->value, ft_strlen(((t_env*)envi->content)->value));
            write(1 ,"\n", 1);
        }
        envi = envi->next;
    }
}