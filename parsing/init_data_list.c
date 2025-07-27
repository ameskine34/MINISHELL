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

#include "../includes/parsing.h"

// * strace echo test""hello""test""ddd hello world '"ddd'

int	subcomponents_length(t_list *data)
{
	int length;

	length = 0;
	while (data)
	{
		if (((t_cmd *)data->content)->type == TOKEN_SPACE
			|| ((t_cmd *)data->content)->type == TOKEN_OPERATION)
			break ;
		length++;
		data = data->next;
	}
	return (length);
}

char	**init_subcomponents(t_list *data)
{
	int subcomp_len;
	int i;
	char **subcomponents;

	if (!data)
		return (NULL);
	while (data && ((t_cmd *)data->content)->type == TOKEN_SPACE)
		data = data->next;
	subcomp_len = subcomponents_length(data);
	if (subcomp_len == 0)
		return (NULL);
	subcomponents = gc_malloc((subcomp_len + 1) * sizeof(char *));
	if (!subcomponents)
		return (NULL);
	i = 0;
	while (i < subcomp_len)
	{
		subcomponents[i] = ft_strdup(((t_cmd *)data->content)->component);
		data = data->next;
		i++;
	}
	subcomponents[subcomp_len] = NULL;
	return (subcomponents);
}

t_list	*get_env_value_list(char *component)
{
	t_list *env_value_list;
	char *exp;

	exp = NULL;
	env_value_list = NULL;
	exp = expand_expression(component);
	if (exp && exp[0] == '"')
		add_node(&env_value_list, get_expression_content(exp), NULL);
	else
	{
		split_env_value(&env_value_list, exp);
		// free(exp);
	}
	return (env_value_list);
}

void	append_list_to_original(t_list **data, t_list *env_value_list,
		t_list **head)
{
	if (!env_value_list)
		return ;
	t_list *last_node;

	last_node = ft_lstlast(env_value_list);
	ft_lstadd_back(&env_value_list, (*data)->next);
	if ((*data)->prev)
	{
		(*data)->prev->next = env_value_list;
		env_value_list->prev = (*data)->prev;
		// free_cmd_node((*data)->content);
		// free(*data);
	}
	else
	{
		// free_cmd_node((*head)->content);
		// free(*head);
		(*head) = env_value_list;
	}
	(*data) = last_node;
}

void	init_data_list(t_list **head)
{
	t_list *env_value_list;
	t_list *data;
	t_list *temp;

	data = *head;
	while (data)
	{
		env_value_list = NULL;
		if ((check_for_operations(data)
				&& !check_for_string(((t_cmd *)(data)->content)->component,
					"|"))
			|| check_for_string(((t_cmd *)(data)->content)->component, "echo"))
			((t_cmd *)(data)->content)->subcomponents = init_subcomponents(data->next);
		if (check_for_char(((t_cmd *)(data)->content)->component, '$')
			&& ((t_cmd *)data->content)->component[0] != '\'')
			env_value_list = get_env_value_list(((t_cmd *)(data)->content)->component);
		if (env_value_list)
			append_list_to_original(&data, env_value_list, head);
		if (((t_cmd *)data->content)->component[0] == '"'
			|| ((t_cmd *)data->content)->component[0] == '\'')
			((t_cmd *)data->content)->component = get_expression_content(((t_cmd *)data->content)->component);
		(data) = data->next;
	}
}
