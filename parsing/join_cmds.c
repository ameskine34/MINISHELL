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

#include "../includes/parsing.h"


// int	get_len(t_list *data, int i)
// {
// 	int		len;
// 	t_cmd	*cmd;

// 	len = 0;
// 	while (data)
// 	{
// 		cmd = data->content;
// 		if (cmd->type != TOKEN_ARGUMENT && cmd->type != TOKEN_COMMAND)
// 		{
// 			data = data->next;
// 			continue ;
// 		}
// 		if (cmd->index == i)
// 			len++;
// 		else
// 			break ;
// 		data = data->next;
// 	}
// 	return (len);
// }

// void	join_cmd(t_list **data, int i, t_cmd *cmd_arr_content)
// {
// 	int		len;
// 	t_cmd	*cmd;
// 	int		j;

// 	len = get_len(*data, i);
// 	cmd_arr_content->arr_content = (char **)gc_malloc((len + 1)
// * sizeof(char *));
// 	if (!cmd_arr_content->arr_content)
// 		return ;
// 	j = 0;
// 	while (*data)
// 	{
// 		cmd = (*data)->content;
// 		if (cmd->type != TOKEN_ARGUMENT && cmd->type != TOKEN_COMMAND)
// 		{
// 			(*data) = (*data)->next;
// 			continue ;
// 		}
// 		if (cmd->index != i)
// 			break ;
// 		cmd_arr_content->arr_content[j] = ft_strdup(cmd->component);
// 		j++;
// 		(*data) = (*data)->next;
// 	}
// 	cmd_arr_content->arr_content[j] = NULL;
// }

void	join_cmd(t_list **data, int i)
{
	t_list *head;
	t_list *joined_list;

	head = *data;
	joined_list = NULL;
	while (*data)
	{
		if (((t_cmd *)(*data)->content)->index != i)
			break ;
		if (((t_cmd *)(*data)->content)->type == TOKEN_COMMAND
			|| ((t_cmd *)(*data)->content)->type == TOKEN_ARGUMENT)
			ft_lstadd_back(&joined_list,
				ft_lstnew(((t_cmd *)(*data)->content)->component));
		*data = (*data)->next;
	}
	((t_cmd *)head->content)->command_head = joined_list;
}

void	join_cmds(t_list *data)
{
	int i;
	t_cmd *cmd;

	i = 0;
	t_list *temp = data;
	while (data)
	{
		cmd = data->content;
		if (cmd->index == i)
		{
			join_cmd(&data, i);
			if (data)
				data = data->next;
		}
		i++;
	}
}