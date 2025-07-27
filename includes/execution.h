/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:00:37 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/14 10:11:42 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

#include "../includes/parsing.h"



// * execution functions:

void	execute_cmd(t_node_infos *infos);
void	dup_redirections(t_list *head);
void	get_valid_path(char **path, t_list *head);
// t_node_infos	*init_node_infos(void);
// void	init_pipes(t_list *data, t_node_infos *infos);
void	init_processes(t_node_infos *infos);
void execute_built_in(t_list *lst, t_list **env);
int	is_built_in(t_list *lst);

#endif