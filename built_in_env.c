/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:46:50 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/16 21:24:42 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_env(t_list *envi)
{
    while (envi)
    {
        if (((t_env*)envi->content)->value)
        {
            printf("%s",((t_env*)envi->content)->key);
            printf("%s","=");
            printf("%s",((t_env*)envi->content)->value);
            printf("%s","\n");
        }
        envi = envi->next;
    }
}