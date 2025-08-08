/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:27:18 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 14:55:11 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	*count_lines(void)
{
	static int	lines;

	return (&lines);
}

void	count_line(void)
{
	int		*i;

	i = count_lines();
	(*i)++;
}
