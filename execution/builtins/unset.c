/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:41:55 by zmoussam          #+#    #+#             */
/*   Updated: 2024/07/20 01:15:32 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	print_unset_error(char *argv, int *check, int *check_exit_status)
{
	*check = 1;
	*check_exit_status = 256;
	printf("minishell: unset: %s: not a valid identifier\n", argv);
}

void	parse_unset_variable(char *argv, int *check, int *check_exit_status)
{
	int	i;

	i = 0;
	if (ft_isdigit(argv[0]))
	{
		print_unset_error(argv, check, check_exit_status);
		return ;
	}
	while (argv[i] && *check == 0)
	{
		if ((argv[i] <= 64 \
		&& !ft_isdigit(argv[i])) \
		|| (argv[i] >= 91 && argv[i] <= 96 \
		&& argv[i] != '_') || argv[i] >= 123)
			print_unset_error(argv, check, check_exit_status);
		i++;
	}
}

void	unset(t_parse_node *root, int index)
{
	int	k;
	int	check_exit_status;

	check_exit_status = 0;
	if (root->ac > 1)
	{
		if (root->av[1][0] == '-')
		{
			global_var.exit_status = 512;
			printf("minishell: unset: %s: invalid option\n", root->av[1]);
			printf("unset: usage: unset [-f] [name ...]\n");
		}
		else if (root->ac >= 2)
		{
			while (root->av[index])
			{
				k = 0;
				parse_unset_variable(root->av[index], &k, &check_exit_status);
				if (k == 0 && env_find(global_var.list, root->av[index], -1))
					ft_list_remove_if(&global_var.list, root->av[index]);
				index++;
			}
		global_var.exit_status = check_exit_status;
		}
	}
}
