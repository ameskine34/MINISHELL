/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/30 09:56:49 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/12 19:18:16 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*get_env_value_list(t_list *data, t_list *env)
{
	t_list	*env_value_list;
	char	*exp;
	char	*component;
	t_cmd	*cm_nd;

	exp = NULL;
	env_value_list = NULL;
	component = ((t_cmd *)(data)->content)->component;
	exp = expand_expression(component, env);
	if (!exp)
		return (((t_cmd *)data->content)->component = ft_strdup(""),
			((t_cmd *)data->content)->skip_node = 1, NULL);
	else if (exp && exp[0] == '"')
	{
		cm_nd = add_node(&env_value_list, get_expression_content(exp), NULL);
		cm_nd->type = TOKEN_WORD;
	}
	else
		split_env_value(&env_value_list, exp);
	return (env_value_list);
}

void	append_list_to_original(t_list **data, t_list *env_value_list,
		t_list **head)
{
	t_list	*last_node;

	if (!env_value_list)
		return ;
	last_node = ft_lstlast(env_value_list);
	ft_lstadd_back(&env_value_list, (*data)->next);
	if ((*data)->prev)
	{
		(*data)->prev->next = env_value_list;
		env_value_list->prev = (*data)->prev;
	}
	else
		(*head) = env_value_list;
	(*data) = last_node;
}

void	init_data_list(t_list **head, t_list *env)
{
	t_list *(env_value_list), *data;
	data = *head;
	while (data)
	{
		env_value_list = NULL;
		if (check_for_char(((t_cmd *)(data)->content)->component, '$')
			&& ((t_cmd *)data->content)->component[0] != '\'')
		{
			env_value_list = get_env_value_list(data, env);
			if (env_value_list)
				append_list_to_original(&data, env_value_list, head);
		}
		else if (data && (((t_cmd *)data->content)->component[0] == '"'
				|| ((t_cmd *)data->content)->component[0] == '\''))
			((t_cmd *)data->content)->component = get_expression_content
				(((t_cmd *)data->content)->component);
		if (data)
			(data = data->next);
	}
}
