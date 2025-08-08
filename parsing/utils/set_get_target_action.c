/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get_target_action.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:21:19 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 14:59:26 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	alloc_regulare(void)
{
	*get_action() = GC_ALLOCATE;
	*get_target() = GC_REGULARE;
}

void	alloc_env_list(void)
{
	*get_action() = GC_ALLOCATE;
	*get_target() = GC_ENV_LIST;
}

void	free_regulare(void)
{
	*get_action() = GC_FREE;
	*get_target() = GC_REGULARE;
	gc_malloc(0);
}

void	free_env_list(void)
{
	*get_action() = GC_FREE;
	*get_target() = GC_ENV_LIST;
	gc_malloc(0);
}
