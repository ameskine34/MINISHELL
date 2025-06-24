/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:35:42 by ameskine          #+#    #+#             */
/*   Updated: 2025/06/23 12:35:44 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			count += ft_check(format[i], ap);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}