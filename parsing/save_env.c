/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaithadd <younessaithadou9@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:37:13 by yaithadd          #+#    #+#             */
/*   Updated: 2025/06/01 15:05:01 by yaithadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

// char	*get_key(char *env_var)
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

// char	*get_value(char *env_var)
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
// 			is_equale_signe_skiped = 1;
// 		if (is_equale_signe_skiped == 1)
// 		{
// 			value = ft_substr(env_var, i + 1, ft_strlen(env_var) - i);
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (value);
// }

// void	save_env(t_list **env_, char **env)
// {
// 	int i;
// 	char **key_value;
// 	t_env *env_var;

// 	while (env[i])
// 	{
// 		env_var = init_env_node(get_key(env[i]), get_value(env[i]));
// 		if (!env_var)
// 			return ;
// 		ft_lstadd_back(env_, ft_lstnew((void *)env_var));
// 		i++;
// 	}
// }