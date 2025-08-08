/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_subcomponents.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 09:39:06 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/07 14:20:58 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	subcomponents_length(t_list *data)
{
	int	length;

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

char	**init_subcomponent_arr(t_list *data)
{
	int		subcomp_len;
	int		i;
	char	**subcomponents;

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
		subcomponents[i++] = ft_strdup(((t_cmd *)data->content)->component);
		data = data->next;
	}
	subcomponents[subcomp_len] = NULL;
	return (subcomponents);
}

void	init_subcomponents(t_list *data)
{
	while (data)
	{
		if (check_for_redirections(((t_cmd *)data->content)->component))
			((t_cmd *)(data)->content)->subcomponents = init_subcomponent_arr
				(data->next);
		data = data->next;
	}
}
