/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:26:47 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 22:26:51 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <stdio.h>

void	print_echo_argv(char **argv, int argc, int i)
{
	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
		if (i != argc)
			printf(" ");
	}
}

void	check_new_line(char **argv, int *i, int *k)
{
	int	j;

	while (argv[*i] && argv[*i][0] == '-' && argv[*i][1] == 'n')
	{
		j = 2;
		while (argv[*i][j] == 'n')
			j++;
		if (argv[*i][j] == '\0')
			*k = 1;
		else
			break ;
		*i += 1;
	}
}

void	echo(t_parser_node *root)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (root->ac > 1)
	{
		check_new_line(root->av, &i, &k);
		print_echo_argv(root->av, root->ac, i);
	}
	if (k == 0)
		printf("\n");
	g_lbv.exit_status = 0;
}
