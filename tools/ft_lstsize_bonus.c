/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:38:12 by yaithadd          #+#    #+#             */
/*   Updated: 2024/11/15 17:38:21 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	// t_list	*head;

	count = 0;
	// head = lst;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
