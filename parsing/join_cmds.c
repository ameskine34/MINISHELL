/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/05/14 17:58:13 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/26 18:40:21 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	join_cmd(t_list **data, int i)
{
	t_list	*head;
	t_list	*joined_list;

	head = *data;
	joined_list = NULL;
	while (*data)
	{
		if (((t_cmd *)(*data)->content)->index != i)
			break ;
		if (((t_cmd *)(*data)->content)->type == TOKEN_WORD
			|| ((t_cmd *)(*data)->content)->type == TOKEN_ARGUMENT)
			if (!((t_cmd *)(*data)->content)->skip_node)
				ft_lstadd_back(&joined_list,
					ft_lstnew(((t_cmd *)(*data)->content)->component));
		*data = (*data)->next;
	}
	((t_cmd *)head->content)->command_head = joined_list;
}

void	fill_arr_content(t_list *head, t_list *to_fill)
{
	int	i;

	i = 0;
	while (to_fill)
	{
		((t_cmd *)head->content)->arr_content[i] = ft_strdup
			((char *)to_fill->content);
		to_fill = to_fill->next;
		i++;
	}
	((t_cmd *)head->content)->arr_content[i] = NULL;
}

void	init_arr_content(t_list *data)
{
	while (data)
	{
		if (((t_cmd *)data->content)->command_head)
		{
			((t_cmd *)data->content)->arr_content = gc_malloc
				((ft_lstsize(((t_cmd *)data->content)
							->command_head) + 1) * sizeof(char *));
			fill_arr_content(data, ((t_cmd *)data->content)->command_head);
		}
		data = data->next;
	}
}

void	join_cmds(t_list *data)
{
	int		i;
	t_cmd	*cmd;
	t_list	*temp;

	i = 0;
	temp = data;
	while (data)
	{
		cmd = data->content;
		if (cmd->index == i)
			join_cmd(&data, i);
		if (data)
			data = data->next;
		i++;
	}
	init_arr_content(temp);
}
