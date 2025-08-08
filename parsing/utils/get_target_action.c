/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:00:50 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 14:57:13 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_gc_target	*get_target(void)
{
	static t_gc_target	target;

	return (&target);
}

t_gc_action	*get_action(void)
{
	static t_gc_action	action;

	return (&action);
}
