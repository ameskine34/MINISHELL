/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:23:48 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/07 13:54:26 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	pwd_changes(t_list *envi, char *current, char *new)
{
	t_list	*list;
	char	*pwd;

	current = (void *)current;
	pwd = NULL;
	list = envi;
	while (list)
	{
		if (ft_strcmp("PWD", ((t_env *)list->content)->key) == 0)
		{
			pwd = ((t_env *)list->content)->value;
			((t_env *)list->content)->value = ft_strdup(new);
		}
		list = list->next;
	}
	list = envi;
	while (list)
	{
		if (ft_strcmp("OLDPWD", ((t_env *)list->content)->key) == 0)
			((t_env *)list->content)->value = ft_strdup(pwd);
		list = list->next;
	}
}

void	setting_error(char *current, int i)
{
	current = (void *)current;
	if (i == 1)
	{
		perror("cd: error retrieving current directory");
		*exit_status() = 1;
		return ;
	}
	if (i == 2)
	{
		perror("bash: cd");
		*exit_status() = 1;
		return ;
	}
	if (i == 3)
	{
		perror("cd: error retrieving new directory");
		*exit_status() = 1;
		return ;
	}
}

void	handle_cd_no_args(t_list *envi, t_node_infos *infos)
{
	char	*current;
	char	*new;
	char	*home;

	home = search_in_env(envi, "HOME");
	if (!home || home[0] == '\0')
	{
		write(2, "bash: cd: HOME not set\n", 23);
		*exit_status() = 1;
		return ;
	}
	current = getcwd(NULL, 0);
	gc_malloc_local(0, GC_ENV_LIST, GC_ALLOCATE, (void *)current);
	if (!current)
		setting_error(current, 1);
	if (chdir(home) != 0)
		setting_error(current, 2);
	new = getcwd(NULL, 0);
	gc_malloc_local(0, GC_ENV_LIST, GC_ALLOCATE, (void *)new);
	if (!new)
		setting_error(current, 3);
	pwd_changes(envi, current, new);
	infos->cwd = ft_strdup(search_in_env(infos->env, "PWD"));
	*exit_status() = 0;
}

void	handle_cd_one_arg(t_list *lst, t_list *envi, t_node_infos *infos)
{
	char *(arg), *current_pwd;
	arg = (char *)lst->next->content;
	if (chdir(arg) != 0)
	{
		perror("bash: cd");
		*exit_status() = 1;
		return ;
	}
	current_pwd = getcwd(NULL, 0);
	gc_malloc_local(0, GC_ENV_LIST, GC_ALLOCATE, (void *)current_pwd);
	if (!current_pwd)
	{
		write(2, "cd: error retrieving current directory\n", 39);
		if (infos->cwd)
			pwd_changes(envi, NULL, ft_strjoin(ft_strjoin(infos->cwd, "/"),
					arg));
		else
			pwd_changes(envi, NULL, ft_strdup(arg));
		infos->cwd = ft_strdup(search_in_env(infos->env, "PWD"));
		*exit_status() = 1;
		return ;
	}
	pwd_changes(envi, NULL, current_pwd);
	infos->cwd = ft_strdup(search_in_env(infos->env, "PWD"));
	*exit_status() = 0;
}

void	ft_cd(t_list *lst, t_list *envi, t_node_infos *infos)
{
	int	k;

	k = ft_lstsize(lst);
	if (k == 1)
		handle_cd_no_args(envi, infos);
	else if (k == 2)
		handle_cd_one_arg(lst, envi, infos);
	else if (k > 2)
	{
		write(2, "bash: cd: too many arguments\n", 29);
		*exit_status() = 1;
	}
}
