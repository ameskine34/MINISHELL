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

#include "../includes/parsing.h"


// ! COMMAND :  gcc main.c pasring.c syntax.c init_data.c init_nodes.c save_data_list.c _error.c tokenization.c utils/checks_.c get_env_vars.c ../execution/execute.c indexing.c
// -L../tools -lft -lreadline
// % j
//^ gcc *.c utils/*.c ../execution/*.c -L../tools -lft -lreadline
// 12:13:53 yaithadd@c2r4p12 ~ → ls -l > ' 'dd"'"'"'
// 12:14:40 yaithadd@c2r4p12 ~ → ls
// ' dd""'     " dd''"    Documgitents   goinfre   Pictures   Templates
// ' dd'\''"'   Desktop   Downloads   Music     Public     Videos

// & check leaks: valgrind --leak-check=full --show-leak-kinds=all ./a.out
// todo : handl echo $_ (that prints the last argument of the last executed command)

void	ctrlchandler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
void	count_line(void)
{
	int *i;

	i = count_lines();
	(*i)++;
}

int	main(int ac, char **av, char **env_)
{
	t_node_infos *infos;
	t_list *data;
	t_list *env;
	char *str;

	data = NULL;
	str = NULL;
	env = NULL;

	signal(SIGINT, ctrlchandler);
	signal(SIGQUIT, SIG_IGN);
	*get_action() = GC_ALLOCATE;
	*get_target() = GC_ENV_LIST;
	init_env_list(env_, &env);
	*get_action() = GC_ALLOCATE;
	*get_target() = GC_REGULARE;
	init_node_infos(data, env);
	while (1)
	{
		str = readline("minishell > ");
		if (!str)
		{
			*get_action() = GC_FREE;
			*get_target() = GC_REGULARE;
			gc_malloc(0);
			exit(*exit_status());
		}
		count_line();
		add_history(str);
		if (strlen(str) > 0)
		{
			pars_input(str, &(infos->data));
			execution(infos);
			free(str);
			*get_action() = GC_FREE;
			*get_target() = GC_REGULARE;
			gc_malloc(0);
			infos->data = NULL;
		}
	}
}
