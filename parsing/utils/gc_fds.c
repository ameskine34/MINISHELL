/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_fds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:52:48 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/03 21:31:19 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	gc_fds(int fd, t_gc_action action)
{
	static int	arr[4096];
	int			i;

	if (action == GC_ALLOCATE)
		arr[fd] = fd;
	else if (action == GC_FREE)
	{
		i = 3;
		while (i < 4096)
		{
			if (arr[i] != 0)
			{
				close(arr[i]);
				arr[i] = 0;
			}
			i++;
		}
	}
}
