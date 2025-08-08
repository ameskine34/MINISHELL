/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:22:21 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 14:55:58 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*get_env(t_list *list, char *key)
{
	t_env	*result;

	result = NULL;
	while (list)
	{
		if (check_for_string(((t_env *)list->content)->key, key)
			&& ((t_env *)list->content)->value != NULL)
		{
			result = list->content;
			break ;
		}
		list = list->next;
	}
	return (result);
}
