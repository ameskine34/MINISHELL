/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:42:07 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/06 20:03:58 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	handle_exit_numeric_error(char *content)
{
	write(2, "bash: exit: ", 12);
	write(2, content, ft_strlen(content));
	write(2, ": numeric argument required\n", 28);
	*exit_status() = 2;
	return (free_env_list(), free_regulare(), gc_fds(0, GC_FREE),
		exit(*exit_status()));
}

void	exit_one_arg(unsigned int n)
{
	*exit_status() = n;
	return (free_env_list(), free_regulare(), gc_fds(0, GC_FREE),
		exit(*exit_status()));
}

void	ft_exit(t_list *lst, t_node_infos *infos)
{
	long	n;
	int		error;
	int		j;

	error = 0;
	j = ft_lstsize(lst);
	if (infos->num_of_processes == 1)
		write(1, "exit\n", 5);
	if (j == 1)
		return (free_env_list(), free_regulare(), gc_fds(0, GC_FREE),
			exit(*exit_status()));
	else if (j > 1)
	{
		if (*(char *)lst->next->content == '\0')
			handle_exit_numeric_error(lst->next->content);
		n = ft_atol((lst->next->content), &error, 0, 1);
		if (error == 1)
			handle_exit_numeric_error(lst->next->content);
		else if (j > 2)
		{
			write(2, "bash: exit: too many arguments\n", 31);
			return (free_env_list(), free_regulare(), exit(1));
		}
		exit_one_arg(n);
	}
}
