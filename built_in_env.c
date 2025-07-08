/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:46:50 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/08 19:03:29 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_env(t_list *envi)
{
    printf("22222222222222222");
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