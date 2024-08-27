/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:26:36 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 22:38:26 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	remove_old_variable(t_env_node *new_node, int *i)
{
	if (!ft_strcmp(new_node->name, "PATH") && new_node->content[0] == '\0')
	{
		*i += 1;
		delone_env(new_node);
		return (1);
	}
	else
		ft_list_remove_if(&g_lbv.list, new_node->name);
	return (0);
}

int	check_parsse(t_env_node *new, int check_parse, int *i)
{
	if (check_parse)
	{
		if (check_parse == -1 && *i == 1)
		{
			g_lbv.exit_status = 512;
			delone_env(new);
			return (2);
		}
		*i += 1;
		delone_env(new);
		return (1);
	}
	return (0);
}

void	add_export_variable(char **argv, int index)
{
	t_env_node	*new;
	int			check_parse;
	int			check;

	g_lbv.exit_status = 0;
	while (argv[index])
	{
		if (argv[index][0] == ';' || argv[index][0] == '#')
			break ;
		new = get_new_node(argv[index], 0);
		if (!new)
			return ;
		check_parse = parss_export_variable(new, index);
		check = check_parsse(new, check_parse, &index);
		if (check == 2)
			break ;
		else if (check == 1)
			continue ;
		if (env_find(g_lbv.list, new->name, ft_strlen(new->name)))
			if (remove_old_variable(new, &index))
				continue ;
		add_back(&g_lbv.list, new);
		index++;
	}
}

void	export(t_parser_node *root)
{
	if (root->ac == 1 || (root->ac == 2 && (root->av[1][0] == '#'
			|| root->av[1][0] == ';')))
	{
		print_sort_list();
		g_lbv.exit_status = 0;
	}
	else
	{
		add_export_variable(root->av, 1);
	}
}
