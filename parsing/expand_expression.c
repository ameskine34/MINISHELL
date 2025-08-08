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

#include "../includes/minishell.h"

char	*expand_env_var(char *expression, t_list *env, int in_d_quotes)
{
	char	*var_name;
	char	*var_value;
	t_env	*env_node;

	if (ft_strlen(expression) == 1)
	{
		var_value = ft_strdup(expression);
		return (var_value);
	}
	var_name = ft_substr(expression, 1, ft_strlen(expression) - 1);
	if (ft_strlen(var_name) == 1 && var_name[0] == '?')
		return (var_value = ft_itoa(*exit_status()));
	env_node = get_env(env, var_name);
	if (!env_node || (env_node && (env_node->value[0] == '\0')))
	{
		if (in_d_quotes)
			var_value = ft_strdup("");
		else
			var_value = NULL;
		return (var_value);
	}
	var_value = env_node->value;
	return (var_value);
}

char	*expand_double_quotes_var(char *expression, t_list *env)
{
	t_list	*local_list;
	char	*cmd_node_comp;
	char	*result;
	char	*exp;

	local_list = NULL;
	exp = ft_strdup("");
	save_data_list_between_d_quotes(&local_list, expression);
	while (local_list)
	{
		cmd_node_comp = ((t_cmd *)local_list->content)->component;
		if (check_for_char(cmd_node_comp, '$'))
			result = expand_env_var(cmd_node_comp, env, 1);
		else
			result = ft_strdup(cmd_node_comp);
		exp = ft_strjoin(exp, result);
		local_list = local_list->next;
	}
	return (exp);
}

char	*expand_expression(char *expression, t_list *env)
{
	char	*result;

	result = NULL;
	if (check_for_char(expression, '$') && expression[0] != '\'')
	{
		if (expression[0] == '"')
			result = expand_double_quotes_var(expression, env);
		else
			result = expand_env_var(expression, env, 0);
	}
	return (result);
}
