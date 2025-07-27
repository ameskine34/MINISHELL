/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:42:07 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/20 20:17:41 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

long num_len(long res)
{
	long i;

	i = 0;
	while (res != 0)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

int get_sign(char *str, int *i)
{
	int sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

void skip_whitespace(char *str, int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
}

long ft_atol(char *str, int *error)
{
	long res;

	int(i), (j), (sign);
	(1) && (i = 0, j = 0);
	res = 0;
	skip_whitespace(str, &i);
	sign = get_sign(str, &i);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (num_len(res) == 18)
			{
				if (sign == 1 && (res > (LLONG_MAX - (str[i] - '0')) / 10))
					*error = 1;
				else if (sign == -1 && (res > (LLONG_MIN + (str[i] - '0')) / 10))
					*error = 1;
			}
			res = res * 10 + (str[i] - '0');
		}
		else
			*error = 1;
		i++;
	}
	return ((res * sign));
}

void handle_exit_numeric_error(char *content)
{
    write(1 , "bash: exit: ", 12);
    write(1 , content, ft_strlen(content));
    write(1 , ": numeric argument required\n", 27);
    exit(2);
}

void ft_exit(t_list *lst) //overall i need to hold the exit value (void ft_exit(t_list *lst, int last_exit_status))
{
	int error;
	unsigned int n;
	int j;

	j = ft_lstsize(lst);
	write(1 , "exit\n", 5);
	if (j == 1)
		exit(1);//i need to take the value of the last exit code
	else if (j > 1)
	{
		n = ft_atol((lst->next->content), &error);
		if (error == 1)
			handle_exit_numeric_error(lst->next->content);
		else if (j > 2)
		{
			write(1 , "bash: exit: too many arguments\n", 30);
    		exit(1);
		}
		else
			exit(n);
	}
}
