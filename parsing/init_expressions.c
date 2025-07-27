/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_expressions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:54:43 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/24 14:16:35 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*get_raw_exp(t_cmd *cmd_node, int with_quotes)
{
	char	*joined_value;
	char	*exp_content;
	int		i;

	joined_value = ft_strdup("");
	i = -1;
	while (cmd_node->subcomponents[++i])
	{
		if (!with_quotes)
		{
			exp_content = get_expression_content(ft_strdup(cmd_node->subcomponents[i]));
			joined_value = ft_strjoin(joined_value, exp_content);
			// free(exp_content);
		}
		else
			joined_value = ft_strjoin(joined_value, cmd_node->subcomponents[i]);
	}
	return (joined_value);
}

void	join_resolved_exp(char **joined_value, char *exp, int with_quotes)
{
	char	*exp_content;

	if (!with_quotes)
	{
		exp_content = get_expression_content(exp);
		*joined_value = ft_strjoin(*joined_value, exp_content);
		// free(exp_content);
	}
	else
	{
		*joined_value = ft_strjoin(*joined_value, exp);
		// free(exp);
	}
}

char	*get_resolved_exp(t_cmd *cmd_node, int with_quotes)
{
	char	*joined_value;
	char	*exp;
	int		i;

	i = -1;
	joined_value = ft_strdup("");
	while (cmd_node->subcomponents[++i])
	{
		if (check_for_char(cmd_node->subcomponents[i], '$')
			&& cmd_node->subcomponents[i][0] != '\'')
			exp = expand_expression(cmd_node->subcomponents[i]);
		else
			exp = ft_strdup(cmd_node->subcomponents[i]);
		join_resolved_exp(&joined_value, exp, with_quotes);
	}
	return (joined_value);
}

void	init_expressions(t_list *data)
{
	int		i;
	t_cmd	*cmd_node;

	while (data)
	{
		cmd_node = ((t_cmd *)data->content);
		if (cmd_node->subcomponents)
		{
			if (check_for_string(cmd_node->component, "<<"))
				heredoc(data);
			if (ambiguous(get_resolved_exp(cmd_node, 1)))
				cmd_node->has_ambiguous_redir = 1;
		}
		data = data->next;
	}
}

// * echo hello > $USER"$USER"DD
