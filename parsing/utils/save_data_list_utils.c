/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:26:53 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/07 10:36:31 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	save_space(t_list **data, char *str, int *i)
{
	t_cmd	*cmd_node;

	cmd_node = add_node(data, ft_strdup(" "), NULL);
	cmd_node->type = TOKEN_SPACE;
	skip_white_spaces(str, i);
}

void	save_single_quotes_content(t_list **data, char *str, int *i)
{
	int		len;
	int		j;
	char	*word;
	t_cmd	*cmd_node;

	len = 0;
	j = *i;
	(*i)++;
	while (str[*i] && str[*i] <= 126 && str[*i] != 39)
	{
		(*i)++;
		len++;
	}
	(*i)++;
	word = ft_substr(str, j, len + 2);
	cmd_node = add_node(data, word, NULL);
	cmd_node->type = TOKEN_WORD;
}

void	save_double_quotes_content(t_list **data, char *str, int *i)
{
	int		len;
	int		j;
	char	*word;
	t_cmd	*cmd_node;

	len = 0;
	j = *i;
	(*i)++;
	while (str[*i] && str[*i] <= 126 && str[*i] != 34)
	{
		(*i)++;
		len++;
	}
	(*i)++;
	word = ft_substr(str, j, len + 2);
	cmd_node = add_node(data, word, NULL);
	cmd_node->type = TOKEN_WORD;
}

// ? ------------------save operations-----------------------

void	save_operations(t_list **data, char *str, int *i)
{
	int		j;
	t_cmd	*cmd_node;

	j = (*i);
	if (str[j + 1] == '>' && str[j] == '>')
		cmd_node = add_node(data, ft_strdup(">>"), NULL);
	else if (str[j + 1] == '<' && str[j] == '<')
		cmd_node = add_node(data, ft_strdup("<<"), NULL);
	else if (str[j] == '<')
		cmd_node = add_node(data, ft_strdup("<"), NULL);
	else if (str[j] == '>')
		cmd_node = add_node(data, ft_strdup(">"), NULL);
	else
		cmd_node = add_node(data, ft_strdup("|"), NULL);
	if ((str[j + 1] == '>' && str[j] == '>') || (str[j + 1] == '<'
			&& str[j] == '<'))
		(*i) += 2;
	else
		(*i)++;
	cmd_node->type = TOKEN_OPERATION;
}

void	save_var(t_list **data, char *str, int *i)
{
	int		len;
	int		j;
	char	*word;

	len = 0;
	j = *i;
	(*i)++;
	while ((str[*i] >= 'A' && str[*i] <= 'Z') || (str[*i] >= 'a'
			&& str[*i] <= 'z') || (str[*i] >= '0' && str[*i] <= '9')
		|| str[*i] == '_')
	{
		(*i)++;
		len++;
	}
	word = ft_substr(str, j, len + 1);
	add_node(data, word, NULL);
}
