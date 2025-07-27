/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expression_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:07:56 by yaithadd          #+#    #+#             */
/*   Updated: 2025/07/24 13:07:01 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*get_expression_content(char *word)
{
	int		len;
	int		i;
	char	*new_word;

	i = 0;
	len = 0;
	while (word[i])
	{
		if (word[i] != 34 && word[i] != 39)
			len++;
		i++;
	}
	new_word = (char *)gc_malloc((len + 1) * sizeof(char));
	if (!new_word)
		return (NULL);
	(1) && (i = 0), (len = 0);
	while (word[i])
	{
		if (word[i] != 34 && word[i] != 39)
			new_word[len++] = word[i];
		i++;
	}
	new_word[len] = '\0';
	return (new_word);
}
