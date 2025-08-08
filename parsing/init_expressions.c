/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_expressions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:54:43 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 15:35:33 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_raw_exp(t_cmd *cmd_node, int with_quotes)
{
	char	*joined_value;
	char	*exp_content;
	int		i;

	joined_value = ft_strdup("");
	if (!cmd_node->subcomponents)
		return (joined_value);
	i = -1;
	while (cmd_node->subcomponents[++i])
	{
		if (!with_quotes)
		{
			if ((cmd_node->subcomponents[i][0] == '\'')
					|| (cmd_node->subcomponents[i][0] == '"'))
				exp_content = get_expression_content
					(cmd_node->subcomponents[i]);
			else
				exp_content = ft_strdup(cmd_node->subcomponents[i]);
			joined_value = ft_strjoin(joined_value, exp_content);
		}
		else
			joined_value = ft_strjoin(joined_value, cmd_node->subcomponents[i]);
	}
	return (joined_value);
}

char	*get_exp(char *comp, t_list *env)
{
	char	*exp;

	exp = NULL;
	if (check_for_char(comp, '$') && comp[0] != '\'')
	{
		exp = expand_expression(comp, env);
		if (exp && exp[0] == '\0')
			exp = NULL;
	}
	else
		exp = ft_strdup(comp);
	return (exp);
}

// char	*get_resolved_exp(t_cmd *cmd_node, int with_quotes, t_list *env)
// {
// 	char	*joined_value;
// 	char	*exp;
// 	int		i;

// 	with_quotes = 0;
// 	i = -1;
// 	exp = NULL;
// 	joined_value = NULL;
// 	while (cmd_node->subcomponents[++i])
// 	{
// 		exp = get_exp(cmd_node->subcomponents[i], env);
// 		if (exp)
// 		{	
// 			joined_value = ft_strjoin(joined_value, exp);
// 		}
// 	}
// 	return (joined_value);
// }

// void	init_expressions(t_list *data, t_list *env)
// {
// 	t_cmd	*cmd_node;
// 	char	*resolved_exp;

// 	resolved_exp = NULL;
// 	while (data)
// 	{
// 		cmd_node = ((t_cmd *)data->content);
// 		if (cmd_node->subcomponents && cmd_node->type != TOKEN_HEREDOC)
// 		{
// 			resolved_exp = get_resolved_exp(cmd_node, 0, env);
// 			if (!resolved_exp || (resolved_exp && ambiguous(resolved_exp)))
// 				cmd_node->has_ambiguous_redir = 1;
// 		}
// 		data = data->next;
// 	}
// }
