/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:00:43 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/24 17:09:55 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	skip_ws_f_b(char *str, int *i, int *j)
{
	while (*j >= 0 && str[*j] && ((str[*j] >= 9 && str[*j] <= 13)
			|| str[*j] == ' '))
		(*j)--;
	while (str[*i] && ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' '))
		(*i)++;
}

int	ambiguous(char *str)
{
	int	i;
	int	j;
	int	inside_quotes;
	int	count;

	count = 0;
	if (!str || (str && str[0] == '\0'))
		return (-1);
	j = ft_strlen(str) - 1;
	i = 0;
	inside_quotes = 0;
	skip_ws_f_b(str, &i, &j);
	while (i < j)
	{
		if (str[i] == '"' || str[i] == '\'' && !inside_quotes)
			(1) && (inside_quotes = 1), (i++);
		if (str[i] == '"' || str[i] == '\'' && inside_quotes)
			(1) && (inside_quotes = 0), (i++);
		if (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && !inside_quotes)
			count++;
		i++;
	}
	return (count);
}
