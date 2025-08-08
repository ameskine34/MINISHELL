/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:30:35 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 15:56:49 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	save_content_(t_list **data, char *str, int *i)
{
	int		len;
	int		j;
	char	*word;

	len = 0;
	j = *i;
	(*i)++;
	while (str[*i] && str[*i] != ' ' && !(str[*i] >= 9 && str[*i] <= 13))
	{
		(*i)++;
		len++;
	}
	word = ft_substr(str, j, len + 1);
	add_node(data, word, NULL);
}

void	split_env_value(t_list **data, char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] == ' ' || (content[i] >= 9 && content[i] <= 13))
			save_space(data, content, &i);
		else
			save_content_(data, content, &i);
	}
}
