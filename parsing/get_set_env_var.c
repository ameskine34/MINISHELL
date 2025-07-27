/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:37:13 by yaithadd          #+#    #+#             */
/*   Updated: 2025/06/02 14:37:32 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

// static char	*get_key(char *env_var)
// {
// 	int		i;
// 	char	*key;

// 	i = 0;
// 	key = NULL;
// 	while (env_var[i])
// 	{
// 		if (env_var[i] == '=')
// 		{
// 			key = ft_substr(env_var, 0, i);
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (key);
// }

// static char	*get_value(char *env_var)
// {
// 	int		i;
// 	char	*value;
// 	int		is_equale_signe_skiped;

// 	i = 0;
// 	value = NULL;
// 	is_equale_signe_skiped = 0;
// 	while (env_var[i])
// 	{
// 		if (env_var[i] == '=')
// 		{
// 			value = ft_substr(env_var, i + 1, ft_strlen(env_var) - i);
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (value);
// }

// void	set_env(t_list **env_, char *env)
// {
// 	t_env	*env_var;

// 	env_var = init_env_node(get_key(env), get_value(env));
// 	if (!env_var)
// 		return ;
// 	ft_lstadd_back(env_, ft_lstnew((void *)env_var));
// }

t_env	*get_env(t_list *list, char *key)
{
	t_env *result;

	result = NULL;
	while (list)
	{
		if (ft_strncmp(((t_env *)list->content)->key, key, ft_strlen(key)) == 0)
		{
			result = list->content;
			break ;
		}
		list = list->next;
	}
	return (result);
}