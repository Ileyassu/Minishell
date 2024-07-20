/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:41:57 by zmoussam          #+#    #+#             */
/*   Updated: 2024/07/20 01:15:32 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include<stdlib.h>
#include <unistd.h>
#include<stdio.h>

void	pwd(t_parse_node *root)
{
	char	*cwd;
	char	buffer[4096];

	cwd = getcwd(buffer, 4096);
	if (root->ac == 1)
	{
		if (cwd == NULL)
			printf("%s\n", buffer);
		else
			printf("%s\n", cwd);
		global_var.exit_status = 0;
	}
	else
	{
		global_var.exit_status = 256;
		printf("minishel v0.1: pwd: %s: illegal option\n", root->av[1]);
		printf("Usage: pwd []\n");
	}
}
