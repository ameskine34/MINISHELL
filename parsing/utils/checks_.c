/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/07/08 10:05:38 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/08 10:05:38 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"


int	check_for_operations(t_list *data)
{
	char *operations[] = {"|", ">", "<", ">>", "<<", NULL};
	int i;

	i = 0;
	while (operations[i])
	{
		if (ft_strncmp(((t_cmd *)data->content)->component, operations[i],
				0) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}

int	check_for_redirections(char *str)
{
	char *redirections[] = {">", "<", ">>", "<<", NULL};
	int i;

	i = 0;
	while (redirections[i])
	{
		if (ft_strncmp(str, redirections[i],
				0) == 0)
			return (i + 2);
		i++;
	}
	return (0);
}

int	check_for_char(char *content, char ch)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (content[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	check_for_string(char *actual, char *expected)
{
	if (!actual || !expected)
		return (0);
	if (ft_strncmp(actual, expected, 0) == 0)
		return (1);
	return (0);
}
