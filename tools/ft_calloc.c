/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:06:55 by yaithadd          #+#    #+#             */
/*   Updated: 2024/11/10 13:47:59 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*allocated;

	allocated = gc_malloc(size * nmemb);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, nmemb * size);
	return (allocated);
}
