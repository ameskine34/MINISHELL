/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 08:30:34 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/06 09:04:39 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	safe_open(char *filename, int flags, int is_child)
{
	int	fd;

	fd = open(filename, flags, 0777);
	if (fd < 0)
		file_error(filename, 0, is_child);
	return (fd);
}
