/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:42:07 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/16 23:54:28 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

long ft_atoi(char *str, int *error)
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
    ft_printf("%s", "bash: exit: ");
    ft_printf("%s", content);
    ft_printf("%s", ": numeric argument required\\n");
    exit(2);
}

void handle_exit_too_many_args()
{
    ft_printf("%s", "bash: exit: too many arguments\\n");
    exit(1);
}

void ft_exit(t_list *lst) //overall i need to hold the exit value (void ft_exit(t_list *lst, int last_exit_status))
{
	int error;
	unsigned int n;
	int j;

	j = ft_lst_size(lst);
	printf("%s", "exit\n");
	if (j == 1)
	{
		exit(1);//i need to take the value of the last exit code
	}
	else if (j > 1)
	{
		n = ft_atoi((lst->next->content), &error);
		if (error == 1)
		{
			handle_exit_numeric_error(lst->next->content);
		}
		else if (j > 2)
		{
			handle_exit_too_many_args();
		}
		else
			exit(n);
	}
}