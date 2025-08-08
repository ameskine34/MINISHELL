/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:04:34 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/08 22:33:42 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"

void	ft_pwd(t_list *env, t_node_infos *infos);
void	ft_cd(t_list *lst, t_list *envi, t_node_infos *infos);
void	pwd_changes(t_list *envi, char *current, char *new);
void	ft_exit(t_list *lst, t_node_infos *infos);
void	ft_echo(t_list *lst);
void	ft_export(t_list *lst, t_list *lst1);
char	*get_key(char *env);
t_env	*init_env(char *key, char *value);
void	ft_env(t_list *lst, t_list *envi);
void	update_or_add_env(t_list **env, char *key, char *value,
			int *is_equal_sign);
void	ft_unset(t_list *lst, t_list **lst1);
long	ft_atol(char *str, int *error, int i, int sign);
int		is_valid_key(char *key);
int		is_alphanum_or_underscore(int c);
void	sort_list(t_list *env);
void	swap_env_nodes(t_list *a, t_list *b);
void	handle_invalid_key_error(char *arg_content, char *key, char *value);
char	*ft_strcat(char *dst, char *s1, char *s2, char *s3);
char	*search_in_env(t_list *envi, char *str);
void	print_key(t_list *temp_env);

#endif