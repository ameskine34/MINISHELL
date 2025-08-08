/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/27 11:38:14 by yaithadd          #+#    #+#             */
/*   Updated: 2025/06/02 14:45:32 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	init_data(t_node_infos **infos, char **env_)
{
	init_signals();
	alloc_env_list();
	*infos = init_node_infos();
	init_env_list(env_, &((*infos)->env));
	(*infos)->cwd = getcwd(NULL, 0);
	gc_malloc_local(0, *get_target(), *get_action(), (*infos)->cwd);
	if (!(*infos)->cwd)
		write(2, "basha: error retrieving current directory\n", 42);
}

void	start_ex(t_node_infos *infos, char *str)
{
	execution(infos);
	free(str);
	free_regulare();
	gc_fds(0, GC_FREE);
}

void	ctrld(void)
{
	free_regulare();
	free_env_list();
	gc_fds(0, GC_FREE);
	write(1, "exit\n", 5);
	exit(*exit_status());
}

void	while_loop(t_node_infos *infos)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = readline("basha > ");
		if (!str)
			return (ctrld());
		count_line();
		add_history(str);
		if (ft_strlen(str) > 0)
		{
			if (pars_input(str, &(infos->data), infos->env))
				start_ex(infos, str);
			infos->data = NULL;
		}
	}
}

int	main(int ac, char **av, char **env_)
{
	t_node_infos	*infos;

	(void)ac;
	(void)av;
	init_data(&infos, env_);
	while_loop(infos);
}
