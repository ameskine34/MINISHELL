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

#include "../includes/parsing.h"


//*   echo hello | ls -l |<< $USER"DD" > outfile"$USER"

// * gcc *.c utils/*.c -L../tools -lft -lreadline

void	pars_input(char *str, t_list **data)
{
	*get_target() = GC_REGULARE;
	*get_action() = GC_ALLOCATE;
	if (double_single_quotes_syntax(str))
		return (free(str));
	save_data_list(str, data);
	init_data_list(data);
	join_data_list(data);
	init_expressions(*data);
	tokenization(*data);
	if (check_syntax(*data))
	{
		*get_target() = GC_REGULARE;
		*get_action() = GC_FREE;
		gc_malloc(0);
		return ;
	}
	indexing(*data);
	join_cmds(*data);
}
