/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:45:26 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/04 18:56:52 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	ft_pwd(t_list *envi, t_node_infos *infos)
{
	char	*path;

	(void)envi;
	path = getcwd(NULL, 0);
	gc_malloc_local(0, GC_ENV_LIST, GC_ALLOCATE, (void *)path);
	if (!path)
	{
		if (infos->cwd)
		{
			write(1, infos->cwd, ft_strlen(infos->cwd));
			write(1, "\n", 1);
			*exit_status() = 0;
			return ;
		}
		write(2, "pwd: error retrieving current directory\n", 40);
		*exit_status() = 1;
		return ;
	}
	write(1, path, ft_strlen(path));
	write(1, "\n", 1);
	*exit_status() = 0;
}
