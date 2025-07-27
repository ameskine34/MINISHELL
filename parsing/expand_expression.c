/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_expression.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/07/08 17:10:13 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/08 17:10:13 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"


char	*expand_env_var(char *expression)
{
	char *var_name;
	char *var_value;

	if (ft_strlen(expression) == 1)
	{
		var_value = ft_strdup(expression);
		return (var_value);
	}
	var_name = ft_substr(expression, 1, ft_strlen(expression) - 1);
	// var_value = getenv(var_name);
	// if (!var_value)
	// 	var_value = ft_strdup("");
	var_value = ft_strdup("expanded:)");
	// free(var_name);
	return (var_value);
}

char	*expand_double_quotes_var(char *expression)
{
	t_list *local_list;
	t_list *local_list_tmp;
	char *cmd_node_comp;
	char *result;
	char *exp;
	char *temp_exp;

	local_list = NULL;
	exp = ft_strdup("");
	save_data_list_between_d_quotes(&local_list, expression);
	local_list_tmp = local_list;
	while (local_list)
	{
		cmd_node_comp = ((t_cmd *)local_list->content)->component;
		if (check_for_char(cmd_node_comp, '$'))
			result = expand_env_var(cmd_node_comp);
		else
			result = ft_strdup(cmd_node_comp);
		exp = ft_strjoin(exp, result);
		// free(result);
		local_list = local_list->next;
	}
	return (exp);
}

char	*expand_expression(char *expression)
{
	if (check_for_char(expression, '$') && expression[0] != '\'')
	{
		if (expression[0] == '"')
			return (expand_double_quotes_var(expression));
		else
			return (expand_env_var(expression));
	}
}
// $
// void	get_var_value(char *expression)
// {
// 	char *next_content;
// 	char *result;

// 	next_content = NULL;
// 	if (data->next)
// 		next_content = ((t_cmd *)data->next->content)->content;
// 	if (ft_strlen(content) == 1 && (next_content == NULL
// 			|| ft_strncmp(next_content, " ", ft_strlen(next_content)) == 0
// 			|| ft_strncmp(next_content, "$", ft_strlen(next_content)) == 0))
// 		return ;
// 	result = replace_env_var(data);
// 	if (if_space(result) == 1)
// 		((t_cmd *)data->content)->has_ambiguous_redir = 1;
// }
