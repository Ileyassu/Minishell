/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:16:21 by zmoussam          #+#    #+#             */
/*   Updated: 2024/07/20 01:15:32 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check__(void)
{
	t_env_node	*head;

	head = global_var.list;
	while (head)
	{
		if (ft_strcmp(head->name, "_") == 0)
			return ;
		head = head->next;
	}
	printf("_=/Users/zmoussam/Desktop/minishell/./minishell\n");
}

void	env_cmd(t_parse_node *root)
{
	if (root->ac != 1)
	{
		if (root->av[1][0] == '-')
		{
			printf("env: illegall option %s\n", root->av[1]);
			printf("usage: env whit no option or argument\n");
			global_var.exit_status = 256;
			return ;
		}
		else
			printf("env: %s: No such file or directory\n", root->av[1]);
		global_var.exit_status = 127 * 256;
	}
	else
	{
		print_list();
		check__();
		global_var.exit_status = 0;
	}
}
