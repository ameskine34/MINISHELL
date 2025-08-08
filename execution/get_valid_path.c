/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/05/27 13:49:08 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 13:49:32 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_command(char **path, char *cmd)
{
	struct stat	file_stat;

	ft_memset(&file_stat, 0, sizeof(struct stat));
	if (stat(cmd, &file_stat) == -1)
		if (errno == ENAMETOOLONG)
			return (err_or(cmd, CODE_FILE_NAME_TO_LONG));
	if (access(cmd, X_OK))
	{
		if (errno == EACCES)
			return (err_or(cmd, CODE_PERM_DENIED));
		if (errno == ENOENT)
			return (err_or(cmd, CODE_N_S_F_O_D));
	}
	if (S_ISDIR(file_stat.st_mode))
		return (err_or(cmd, CODE_IS_DIRECTORY));
	*path = cmd;
}

char	*check_with_flag(char **env_path_arr, char *cmd, int flag)
{
	int			i;
	char		*path;
	char		*command;
	struct stat	file_stat;

	i = 0;
	ft_memset(&file_stat, 0, sizeof(struct stat));
	while (env_path_arr[i])
	{
		if (cmd[0] == '\0')
			break ;
		command = ft_strjoin("/", cmd);
		path = ft_strjoin(env_path_arr[i], command);
		stat(path, &file_stat);
		if (!access(path, flag) && !S_ISDIR(file_stat.st_mode))
			return (path);
		i++;
	}
	return (NULL);
}

void	get_valid_path(char **path, char **env_path_arr, char *cmd)
{
	*path = check_with_flag(env_path_arr, cmd, X_OK);
	if (!(*path))
	{
		*path = check_with_flag(env_path_arr, cmd, F_OK);
		if (*path)
			return (err_or(*path, CODE_PERM_DENIED));
		return (err_or(cmd, CODE_CMD_NOT_FOUND));
	}
}

char	*get_path(t_node_infos *infos)
{
	t_env	*env_;
	char	*path;

	path = NULL;
	env_ = get_env(infos->env, "PATH");
	if (check_for_char(((t_cmd *)infos->head->content)->command_head->content,
			'/'))
		check_command(&path,
			((t_cmd *)infos->head->content)->command_head->content);
	else if (env_ && env_->value[0] != '\0')
		get_valid_path(&path, ft_split(env_->value, ':'),
			((t_cmd *)infos->head->content)->command_head->content);
	else if (!env_ || (env_ && env_->value && (env_->value[0] == '\0')))
		check_command(&path,
			((t_cmd *)infos->head->content)->command_head->content);
	return (path);
}
