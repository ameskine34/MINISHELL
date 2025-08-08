/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/05/16 10:09:31 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 16:24:00 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_cmd(t_node_infos *infos)
{
	t_cmd	*cmd;

	while (infos->data)
	{
		cmd = infos->data->content;
		if (cmd->index == infos->index)
		{
			infos->head = infos->data;
			return ;
		}
		infos->data = infos->data->next;
	}
}

void	free_garbage(void)
{
	free_env_list();
	free_regulare();
	gc_fds(0, GC_FREE);
}

char	**arr_env(t_list *env)
{
	char	**arr_env_;
	char	*value;
	char	*key;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(env);
	arr_env_ = gc_malloc(sizeof(char *) * (len + 1));
	while (env)
	{
		key = ((t_env *)env->content)->key;
		value = ((t_env *)env->content)->value;
		arr_env_[i] = ft_strjoin_tree(key, "=", value);
		env = env->next;
		i++;
	}
	arr_env_[i] = NULL;
	return (arr_env_);
}

void	execute_cmd(t_node_infos *infos)
{
	t_list	*command_arg;
	char	*path;
	char	**arr_env_;

	path = NULL;
	arr_env_ = NULL;
	command_arg = NULL;
	get_cmd(infos);
	dup_redirections(infos->head, 1);
	if (infos->head)
		command_arg = (((t_cmd *)infos->head->content)->command_head);
	if (!command_arg)
		return (free_garbage(), gc_fds(0, GC_FREE), exit(0));
	if (is_built_in(command_arg))
		return (execute_built_in(command_arg, &(infos->env), infos),
			free_garbage(), gc_fds(0, GC_FREE), exit(*exit_status()));
	path = get_path(infos);
	arr_env_ = arr_env(infos->env);
	execve(path, ((t_cmd *)infos->head->content)->arr_content, arr_env_);
	free_garbage();
	gc_fds(0, GC_FREE);
	err_or(NULL, CODE_SYS_CALL);
}
