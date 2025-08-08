/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:58:20 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 15:59:57 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	skip_next_space(t_list **data)
{
	if ((*data)->next
		&& check_for_string(((t_cmd *)(*data)->next->content)->component, " "))
		(*data) = (*data)->next;
}

void	skip_space_to_prev(t_list **data)
{
	if (*data && check_for_string(((t_cmd *)(*data)->content)->component, " "))
		(*data) = (*data)->prev;
}

void	skip_space_to_next(t_list **data)
{
	if (*data && check_for_string(((t_cmd *)(*data)->content)->component, " "))
		(*data) = (*data)->next;
}
