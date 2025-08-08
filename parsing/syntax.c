/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/27 17:20:20 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/04 10:57:54 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	red_error(t_list *data)
{
	skip_next_space(&data);
	if (data->next && check_for_operations(data->next))
		return ((syntax_error(CODE_UNEXPECTED_TOKEN,
					((t_cmd *)data->next->content)->component), 1));
	return (0);
}

int	pipe_error(t_list *data)
{
	skip_next_space(&data);
	if (data->next
		&& check_for_string(((t_cmd *)data->next->content)->component, "|"))
		return ((syntax_error(CODE_UNEXPECTED_TOKEN,
					((t_cmd *)data->next->content)->component), 1));
	return (0);
}

int	operations_syntax(t_list *data)
{
	t_list	*last_node;
	char	*component;

	skip_space_to_next(&data);
	if (data && check_for_string(((t_cmd *)data->content)->component, "|"))
		return (syntax_error(CODE_UNEXPECTED_TOKEN, "|"), 1);
	last_node = ft_lstlast(data);
	while (data)
	{
		component = ((t_cmd *)data->content)->component;
		if (check_for_redirections(component))
			if (red_error(data))
				return (1);
		if (check_for_string(component, "|"))
			if (pipe_error(data))
				return (1);
		data = data->next;
	}
	skip_space_to_prev(&last_node);
	if (last_node && check_for_operations(last_node))
		return (syntax_error(CODE_UNEXPECTED_TOKEN, "newline"), 1);
	return (0);
}

int	check_syntax(t_list *data)
{
	return (operations_syntax(data));
}
