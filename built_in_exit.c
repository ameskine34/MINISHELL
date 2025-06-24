/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:42:07 by ameskine          #+#    #+#             */
/*   Updated: 2025/06/24 12:03:40 by ameskine         ###   ########.fr       */
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
				if (sign == 1 && (str[i] > '7' || str[i + 1] != '\0'))
					*error = 1;
				else if (sign == -1 && (str[i] > '8' || str[i + 1] != '\0'))
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

int ft_check_valid(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && (s[i] != '-' && s[i] != '+'))
			return (0);
		i++;
	}
	return (1);
}

void ft_exit(t_list *lst)
{
	int j;
	int error;

	j = ft_lst_size(lst) - 1;
	long n;
	// if (j == 1)
	// {
	// 	exit();//i need to take the value of the last exit code
	// }
	if (j > 1 && !ft_check_valid(lst->next->content))
	{
		ft_printf("%s\n", "exit");
		ft_printf("%s", "bash: exit: ");
		ft_printf("%s", lst->next->content);
		ft_printf("%s", ": numeric argument required");
		exit(2);
	}
	else if (j > 2)
	{
		ft_printf("%s\n", "exit");
		ft_printf("%s", "bash: exit: too many arguments");
		exit(1);
	}
	else
	{
		n = ft_atoi((lst->next->content), &error);
		if (error == 1)
		{
			ft_printf("%s\n", "exit");
			ft_printf("%s", "bash: exit: ");
			ft_printf("%s", lst->next->content);
			ft_printf("%s", ": numeric argument required");
			exit(2);
		}
		else
			exit(n);
	}
}
// exit with previous exit_code
// exit with 2 if arg1 not valid
// set exit_code to 1 if has more than one arg
