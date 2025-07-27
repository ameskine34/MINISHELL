/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_single_quotes_syntax.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:43:21 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/21 12:47:56 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	double_single_quotes_syntax(char *str)
{
	int	i;
	int	d_quotes_count;
	int	s_quotes_count;
	int	is_in_double;
	int	is_in_single;

	i = 0;
	d_quotes_count = 0;
	s_quotes_count = 0;
	is_in_double = 0;
	is_in_single = 0;
	while (str[i])
	{
		if (str[i] == '"' && is_in_single == 0)
		{
			d_quotes_count++;
			is_in_double = 1;
		}
		if (str[i] == '\'' && is_in_double == 0)
		{
			s_quotes_count++;
			is_in_single = 1;
		}
		if (d_quotes_count % 2 == 0)
			is_in_double = 0;
		if (s_quotes_count % 2 == 0)
			is_in_single = 0;
		i++;
	}
	if ((d_quotes_count % 2) != 0 || (s_quotes_count % 2) != 0)
		return (syntax_error(0, NULL), 1);
	return (0);
}
