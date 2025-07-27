/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data_list_between_d_quotes.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:35:58 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/22 11:51:37 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	save_content(t_list **data, char *str, int *i)
{
	int		len;
	int		j;
	char	*word;

	len = 0;
	j = *i;
	while (str[*i] && str[*i] != '$') // && str[*i] != '\'' && str[*i] != '"'
	{
		(*i)++;
		len++;
	}
	word = ft_substr(str, j, len);
	add_node(data, word, NULL);
}

void	save_var_name(t_list **data, char *str, int *i)
{
	int		len;
	int		j;
	char	*word;

	len = 0;
	j = *i;
	(*i)++;
	while (str[*i] && str[*i] != '$' && ((str[*i] >= 65 && str[*i] <= 90)
			|| (str[*i] >= 48 && str[*i] <= 57) || str[*i] == 95 || (str[*i] >= 97 && str[*i] <= 122)))
	{
		(*i)++;
		len++;
	}
	word = ft_substr(str, j, len + 1);
	add_node(data, word, NULL);
}

void	save_data_list_between_d_quotes(t_list **data, char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != '$')
			save_content(data, content, &i);
		if (content[i] == '$')
			save_var_name(data, content, &i);
		// if (content[i] == '\'' || content[i] == '"')
		// 	i++;
	}
}
