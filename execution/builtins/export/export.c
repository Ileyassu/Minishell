/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:41:53 by zmoussam          #+#    #+#             */
/*   Updated: 2024/07/20 01:15:32 by ibenaiss         ###   ########.fr       */
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
		ft_list_remove_if(&global_var.list, new_node->name);
	return (0);
}

int	check_parsse(t_env_node *new, int _check_parse, int *i)
{
	if (_check_parse)
	{
		if (_check_parse == -1 && *i == 1)
		{
			global_var.exit_status = 512;
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
	int			_check_parse;
	int			check;

	global_var.exit_status = 0;
	while (argv[index])
	{
		if (argv[index][0] == ';' || argv[index][0] == '#')
			break ;
		new = get_new_node(argv[index], 0);
		if (!new)
			return ;
		_check_parse = parss_export_variable(new, index);
		check = check_parsse(new, _check_parse, &index);
		if (check == 2)
			break ;
		else if (check == 1)
			continue ;
		if (env_find(global_var.list, new->name, ft_strlen(new->name)))
			if (remove_old_variable(new, &index))
				continue ;
		add_back(&global_var.list, new);
		index++;
	}
}

void	export(t_parse_node *root)
{
	if (root->ac == 1 || (root->ac == 2 \
		&& (root->av[1][0] == '#' || root->av[1][0] == ';')))
	{
		print_sort_list();
		global_var.exit_status = 0;
	}
	else
		add_export_variable(root->av, 1);
}
