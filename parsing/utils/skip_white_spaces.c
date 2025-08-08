/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_white_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:55:13 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/31 10:10:51 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	skip_white_spaces(char *str, int *i)
{
	while (str[*i] && (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
}
