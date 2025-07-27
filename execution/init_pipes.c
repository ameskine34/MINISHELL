/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:27:33 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/27 14:48:54 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"



// void	init_pipes(t_list *data, t_node_infos *infos)
// {
// 	int	i;

// 	infos->data = data;
// 	infos->num_of_pipes = get_num_of_pipes(data);
// 	infos->num_of_processes = infos->num_of_pipes + 1;
// 	infos->pipes = malloc(infos->num_of_pipes * sizeof(int *));
// 	if (!infos->pipes)
// 		return ;
// 	i = 0;
// 	while (i < infos->num_of_pipes)
// 	{
// 		infos->pipes[i] = malloc(2 * sizeof(int));
// 		pipe(infos->pipes[i]);
// 		i++;
// 	}
// }
