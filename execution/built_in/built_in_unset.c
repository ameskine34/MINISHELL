/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameskine <ameskine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:26:29 by ameskine          #+#    #+#             */
/*   Updated: 2025/08/05 16:25:19 by ameskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	unset_only(t_list *lst)
{
	if (ft_lstsize(lst) == 1)
	{
		*exit_status() = 0;
		return ;
	}
}

void	ft_unset(t_list *lst, t_list **lst_env)
{
	t_list *(current_env), *tmp, *prev_env;
	unset_only(lst);
	tmp = lst->next;
	while (tmp)
	{
		prev_env = NULL;
		current_env = *lst_env;
		while (current_env)
		{
			if (((t_env *)current_env->content)->key && !ft_strcmp(
					((t_env *)current_env->content)->key, tmp->content))
			{
				if (prev_env == NULL)
				{
					*lst_env = (*lst_env)->next;
					break ;
				}
				prev_env->next = current_env->next;
			}
			prev_env = current_env;
			current_env = current_env->next;
		}
		tmp = tmp->next;
	}
	*exit_status() = 0;
}
