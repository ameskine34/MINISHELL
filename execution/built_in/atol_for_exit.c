/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_for_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:07:52 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/04 17:59:22 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

int	get_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

void	skip_whitespace(char *str, int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
}

long	ft_atol(char *str, int *error, int i, int sign)
{
	long	res;
	int		digit;

	res = 0;
	digit = 0;
	skip_whitespace(str, &i);
	sign = get_sign(str, &i);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if (sign == 1)
				if (res > (LLONG_MAX - digit) / 10)
					*error = 1;
			if (sign == -1)
				if (-res < (LLONG_MIN + digit) / 10)
					*error = 1;
			res = res * 10 + digit;
		}
		else
			*error = 1;
		i++;
	}
	return (res * sign);
}
