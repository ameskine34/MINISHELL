/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/10/29 12:04:52 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/02 10:04:20 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last_head;

	if (*lst)
	{
		last_head = ft_lstlast(*lst);
		last_head->next = new;
		if (new)
			new->prev = last_head;
	}
	else
		*lst = new;
}
