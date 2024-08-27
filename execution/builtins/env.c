/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:26:52 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 22:26:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check(void)
{
	t_env_node	*head;

	head = g_lbv.list;
	while (head)
	{
		if (ft_strcmp(head->name, "_") == 0)
			return ;
		head = head->next;
	}
}

void	env_cmd(t_parser_node *root)
{
	if (root->ac != 1)
	{
		if (root->av[1][0] == '-')
		{
			printf("env: illegall option %s\n", root->av[1]);
			printf("usage: env whit no option or argument\n");
			g_lbv.exit_status = 256;
			return ;
		}
		else
			printf("env: %s: No such file or directory\n", root->av[1]);
		g_lbv.exit_status = 127 * 256;
	}
	else
	{
		print_list();
		check();
		g_lbv.exit_status = 0;
	}
}
