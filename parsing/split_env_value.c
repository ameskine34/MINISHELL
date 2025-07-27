/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:30:35 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/20 20:11:35 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	save_content_(t_list **data, char *str, int *i)
{
	int		len;
	int		j;
	char	*word;
	
	len = 0;
	j = *i;
	(*i)++;
	while (str[*i] && str[*i] != ' ')
	{
		(*i)++;
		len++;
	}
	word = ft_substr(str, j, len + 1);
	add_node(data, word, NULL);
}

void	save_space_(t_list **data, char *str, int *i)
{
	t_cmd *cmd_node;
	
	cmd_node = add_node(data, ft_strdup(" "), NULL);
	cmd_node->type = TOKEN_SPACE;
	skip_white_spaces(str, i);
}

void	split_env_value(t_list **data, char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (content[i] == ' ')
			save_space_(data, content, &i);
		else
			save_content_(data, content, &i);
	}
}