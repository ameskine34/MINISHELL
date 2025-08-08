/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _error.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/30 18:20:39 by yaithadd          #+#    #+#             */
/*   Updated: 2025/05/04 10:56:19 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_error(char *msg, char *token)
{
	write(2, msg, ft_strlen(msg));
	write(2, "`", 1);
	write(2, token, ft_strlen(token));
	write(2, "'", 1);
	write(2, "\n", 1);
}

void	d_s_q_syn_err_print(void)
{
	write(2, MSG_D_S_Q_SYN_ERR, ft_strlen(MSG_D_S_Q_SYN_ERR));
	write(2, "\n", 1);
}

void	syntax_error(int err, char *token)
{
	if (err == CODE_UNEXPECTED_TOKEN)
		return (print_error(MSG_UNEXPECTED_TOKEN_MSG, token));
	if (err == CODE_D_S_Q_SYN_ERR)
		return (d_s_q_syn_err_print());
}
