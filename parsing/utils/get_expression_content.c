/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expression_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:07:56 by yaithadd          #+#    #+#             */
/*   Updated: 2025/08/05 14:56:50 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_expression_len(char *word)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (word[i] == 34 || word[i] == 39)
		i++;
	while (word[i + 1])
	{
		len++;
		i++;
	}
	return (len);
}

char	*get_expression_content(char *word)
{
	int		len;
	int		i;
	char	*new_word;

	i = 0;
	len = get_expression_len(word);
	new_word = (char *)gc_malloc((len + 1) * sizeof(char));
	if (!new_word)
		return (NULL);
	(1) && (i = 0, len = 0);
	if (word[i] == 34 || word[i] == 39)
		i++;
	while (word[i + 1])
	{
		new_word[len] = word[i];
		len++;
		i++;
	}
	new_word[len] = '\0';
	return (new_word);
}
