/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/27 11:44:16 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 15:54:53 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_if_only_spaces(t_list *data)
{
	while (data)
	{
		if (!check_for_string(((t_cmd *)data->content)->component, " "))
			return (0);
		data = data->next;
	}
	return (1);
}

int	pars_input(char *str, t_list **data, t_list *env)
{
	if (double_single_quotes_syntax(str))
		return (free(str), *exit_status() = 2,
			syntax_error(CODE_D_S_Q_SYN_ERR, NULL), 0);
	alloc_regulare();
	save_data_list(str, data);
	if (check_if_only_spaces(*data))
		return (free(str), free_regulare(), 0);
	init_subcomponents(*data);
	if (check_syntax(*data))
		return (free(str), free_regulare(), *exit_status() = 2, 0);
	if (init_heredoc(*data, env))
		return (free(str), free_regulare(), gc_fds(0, GC_FREE), 0);
	init_data_list(data, env);
	join_data_list(data);
	tokenization(*data);
	indexing(*data);
	join_cmds(*data);
	return (1);
}
