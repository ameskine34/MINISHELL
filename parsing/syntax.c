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

#include "../includes/parsing.h"


int	operations_syntax(t_list *data)
{
	t_list *last_node;

	if (check_for_string(((t_cmd *)data->content)->component, "|"))
		return (syntax_error(UNEXPECTED_TOKEN, "|"), 1);
	last_node = ft_lstlast(data);
	while (data)
	{
		if (data->next && check_for_operations(data)
			&& check_for_operations(data->next))
			return (syntax_error(UNEXPECTED_TOKEN,
					((t_cmd *)data->next->content)->component), 1);
		data = data->next;
	}
	if (check_for_operations(last_node))
		return (syntax_error(UNEXPECTED_TOKEN, "newline"), 1);
	return (0);
}

int	check_syntax(t_list *data)
{
	return (operations_syntax(data));
}
