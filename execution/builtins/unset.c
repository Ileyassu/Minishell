/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:27:08 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 22:36:55 by ibenaiss         ###   ########.fr       */
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
	if (env_find3(g_lbv.list, argv))
	{
		return ;
	}
	if (ft_isdigit(argv[0]))
	{
		print_unset_error(argv, check, check_exit_status);
		return ;
	}
	while (argv[i] && *check == 0)
	{
		if ((argv[i] <= 64 && !ft_isdigit(argv[i])) || (argv[i] >= 91
				&& argv[i] <= 96 && argv[i] != '_') || argv[i] >= 123)
			print_unset_error(argv, check, check_exit_status);
		i++;
	}
}

char	*get_value(char *s, t_env_node *env)
{
	while (env)
	{
		if (!ft_strcmp(s, env->content))
			return (ft_strdup(env->name));
		env = env->next;
	}
	return (NULL);
}

void	unset_condition_helper(t_parser_node *root, int check_exit_status,
		int index, int k)
{
	if (root->av[1][0] == '-')
	{
		g_lbv.exit_status = 512;
		printf("minishell: unset: %s: invalid option\n", root->av[1]);
		printf("unset: usage: unset [-f] [name ...]\n");
	}
	else if (root->ac >= 2)
	{
		while (root->av[index])
		{
			parse_unset_variable(root->av[index], &k, &check_exit_status);
			if (k == 0 && env_find(g_lbv.list, root->av[index], -1))
				ft_list_remove_if(&g_lbv.list, root->av[index]);
			index++;
		}
		g_lbv.exit_status = check_exit_status;
	}
}

void	unset(t_parser_node *root, int index)
{
	int	k;
	int	check_exit_status;

	k = 0;
	check_exit_status = 0;
	if (root->ac > 1)
		unset_condition_helper(root, check_exit_status, index, k);
}
