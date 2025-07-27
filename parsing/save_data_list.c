/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/29 08:31:49 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 15:44:59 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	save_word(t_list **data, char *str, int *i)
{
	int len;
	int j;
	char *word;

	len = 0;
	j = *i;
	while (str[*i] && str[*i] <= 126 && str[*i] != 34 && str[*i] != 39
		&& str[*i] != ' ' && !(str[*i] >= 9 && str[*i] <= 13) && str[*i] != 60
		&& str[*i] != 62 && str[*i] != '|' && str[*i] != '$' && str[*i] != '/')
	{
		(*i)++;
		len++;
	}
	word = ft_substr(str, j, len);
	add_node(data, word, NULL);
}

void	save_space(t_list **data, char *str, int *i)
{
	t_cmd *cmd_node;

	cmd_node = add_node(data, ft_strdup(" "), NULL);
	cmd_node->type = TOKEN_SPACE;
	skip_white_spaces(str, i);
}

void	save_single_quotes_content(t_list **data, char *str, int *i)
{
	int len;
	int j;
	char *word;

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
	add_node(data, word, NULL);
}
void	save_double_quotes_content(t_list **data, char *str, int *i)
{
	int len;
	int j;
	char *word;

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
	add_node(data, word, NULL);
}

// ? ------------------save operations-----------------------

void	save_operations(t_list **data, char *str, int *i)
{
	int j;
	t_cmd *cmd_node;

	j = (*i);
	if (str[j + 1] == '>' && str[j] == '>')
	{
		cmd_node = add_node(data, ft_strdup(">>"), NULL);
		(*i) += 2;
	}
	else if (str[j + 1] == '<' && str[j] == '<')
	{
		cmd_node = add_node(data, ft_strdup("<<"), NULL);
		(*i) += 2;
	}
	else if (str[j] == '<')
	{
		cmd_node = add_node(data, ft_strdup("<"), NULL);
		(*i)++;
	}
	else if (str[j] == '>')
	{
		cmd_node = add_node(data, ft_strdup(">"), NULL);
		(*i)++;
	}
	else if (str[j] == '|')
	{
		cmd_node = add_node(data, ft_strdup("|"), NULL);
		(*i)++;
	}
	cmd_node->type = TOKEN_OPERATION;
}

void	save_var(t_list **data, char *str, int *i)
{
	int len;
	int j;
	char *word;

	len = 0;
	j = *i;
	(*i)++;
	while (str[*i] && str[*i] <= '~' && str[*i] != '"' && str[*i] != '\''
		&& str[*i] != ' ' && !(str[*i] >= 9 && str[*i] <= 13) && str[*i] != '<'
		&& str[*i] != '>' && str[*i] != '|' && str[*i] != '$'
		&& str[*i] != '/')
	{
		(*i)++;
		len++;
	}

	word = ft_substr(str, j, len + 1);
	add_node(data, word, NULL);
}

void	save_back_slash(t_list **data, char *str, int *i)
{
	int len;
	int j;
	char *word;

	len = 0;
	j = *i;
	(*i)++;
	while (str[*i] && str[*i] == '/')
	{
		(*i)++;
		len++;
	}
	word = ft_substr(str, j, len + 1);
	add_node(data, word, NULL);
}

void	save_data_list(char *str, t_list **data)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '!' && str[i] <= '~' && str[i] != '"' && str[i] != '\''
			&& str[i] != '<' && str[i] != '>' && str[i] != '|' && str[i] != '$'
			&& str[i] != '/')
			save_word(data, str, &i);
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			save_space(data, str, &i);
		if (str[i] == '\'')
			save_single_quotes_content(data, str, &i);
		if (str[i] == '"')
			save_double_quotes_content(data, str, &i);
		if (str[i] == '|' || str[i] == '>' || str[i] == '<')
			save_operations(data, str, &i);
		if (str[i] == '$')
			save_var(data, str, &i);
		if (str[i] == '/')
			save_back_slash(data, str, &i);
	}
}
