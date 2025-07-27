/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:04:34 by ameskine          #+#    #+#             */
/*   Updated: 2025/07/25 16:56:47 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// #include <string.h>
// #include <stdarg.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <errno.h>
// #include <limits.h>
// # include <stdarg.h>
// #include <readline/readline.h>
// #include <readline/history.h>
// #include <fcntl.h> //if you don t use it remove it
#include "execution.h"

// void	execution_phase(t_list *data, t_list *env);
// void execute_built_in(t_list *lst, t_list **env);
// int	is_built_in(t_list *lst);

void	ft_pwd(void);
void	ft_cd(t_list *lst, t_list *lst1);
void	pwd_changes(t_list *envi, char *current, char *new);
void	ft_exit(t_list *lst);
void	ft_echo(t_list *lst);
void	ft_export(t_list *lst, t_list *lst1);
void	sort(t_env *lst1);
// void	set_envi(t_list **envi, char *env);
char	*get_key(char *env);
t_env	*init_env(char *key, char *value);
void	ft_env(t_list *envi);
void	ft_lst_clear(t_list **lst, void (*del)(void *));
void	free_env_node(void *content);
void	update_or_add_env(t_list **env, char *key, char *value,
			int *is_equal_sign);
void	ft_unset(t_list *lst, t_list **lst1);
long	num_len(long res);

#endif