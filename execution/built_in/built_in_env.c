/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:46:50 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/03 17:02:50 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	ft_env(t_list *lst, t_list *envi)
{
	if (ft_lstsize(lst) == 1)
	{
		while (envi)
		{
			if (((t_env *)envi->content)->value)
			{
				write(1, ((t_env *)envi->content)->key,
					ft_strlen(((t_env *)envi->content)->key));
				write(1, "=", 1);
				write(1, ((t_env *)envi->content)->value,
					ft_strlen(((t_env *)envi->content)->value));
				write(1, "\n", 1);
			}
			envi = envi->next;
		}
		*exit_status() = 0;
	}
	else
	{
		write(2, "env: `", 6);
		write(2, lst->next->content, ft_strlen(lst->next->content));
		write(2, "' :No such file or directory\n", 29);
		*exit_status() = 127;
	}
}
