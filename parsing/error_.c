/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _error.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:20:39 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/04 10:56:19 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

#define UNEXPECTED_TOKEN_MSG "bash: syntax error near unexpected token "

void	print_error(char *msg, char *token)
{
	write(1, msg, ft_strlen(msg));
	write(1, "`", 1);
	write(1, token, ft_strlen(token));
	write(1, "'", 1);
	write(1, "\n", 1);
}

void	syntax_error(int err, char *token)
{
	if (err == UNEXPECTED_TOKEN)
		return (print_error(UNEXPECTED_TOKEN_MSG, token));
	printf("other error msg\n");
}