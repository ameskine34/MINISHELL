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

#include "../../includes/minishell.h"

int	check_for_operations(t_list *data)
{
	char	*operations[6];
	int		i;

	i = 0;
	operations[0] = "|";
	operations[1] = ">";
	operations[2] = "<";
	operations[3] = ">>";
	operations[4] = "<<";
	operations[5] = NULL;
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
	char	*redirections[5];
	int		i;

	redirections[0] = ">";
	redirections[1] = "<";
	redirections[2] = ">>";
	redirections[3] = "<<";
	redirections[4] = NULL;
	i = 0;
	while (redirections[i])
	{
		if (ft_strncmp(str, redirections[i], 0) == 0)
			return (i + 2);
		i++;
	}
	return (0);
}

int	check_for_char(char *content, char ch)
{
	int	i;

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
