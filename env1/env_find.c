/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:11:35 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 22:01:46 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "env.h"

t_env_node	*env_find(t_env_node *env, char *s, int len)
{
	t_env_node	*node;

	if (len == -1)
		len = ft_strlen(s);
	while (env)
	{
		if (len == env->len && !ft_strncmp(env->name, s, len))
		{
			node = env;
			return (node);
		}
		env = env->next;
	}
	return (NULL);
}

char	*env_find2(t_env_node *env, char *s, int len)
{
	t_env_node	*node;

	if (len == -1)
		len = ft_strlen(s);
	while (env)
	{
		if (len == env->len && !ft_strncmp(env->name, s, len))
		{
			node = env;
			return (node->content);
		}
		env = env->next;
	}
	return (NULL);
}

int	env_find3(t_env_node *env, char *s)
{
	while (env)
	{
		if (!ft_strcmp(env->content, s))
		{
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	print_list(void)
{
	t_env_node	*head;

	head = g_lbv.list;
	while (head)
	{
		if (head->content[0] != '\0')
			printf("%s=%s\n", head->name, head->content);
		head = head->next;
	}
}

void	ft_list_remove_if(t_env_node **begin_list, void *data_ref)
{
	t_env_node	*cur;

	if (*begin_list == NULL || begin_list == NULL)
		return ;
	cur = *begin_list;
	if (ft_strcmp(cur->name, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur->name);
		free(cur->content);
		free(cur);
		ft_list_remove_if(begin_list, data_ref);
	}
	else
		ft_list_remove_if(&cur->next, data_ref);
}
