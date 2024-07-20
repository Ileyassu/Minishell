/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:01:56 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/20 18:44:53 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing/parser.h"
#include "./execution/execution.h"
#include "utils/utils.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/errno.h>
#include <signal.h>
#include <sys/signal.h>

t_glb_v	global_var;

void	check_sigquit_(void)
{
	if (WIFSIGNALED(global_var.exit_status))
	{
		if (global_var.check_sigquit == 0)
			global_var.exit_status = 130 * 256;
		else if (global_var.check_sigquit == 1)
			global_var.exit_status = 131 * 256;
	}
}

void	minishell(t_parse_node *list, char *line)
{
	if (ft_strcmp(line, "") != 0)
		add_history(line);
	if (global_var.check_signal == 0)
	{
		list = parse(line);
		if (list)
		{
			if (global_var.check_signal == 0)
				execution(list);
			node_del(&list);
		}
	}
	global_var.check_signal = 0;
	free(line);
}

int	main(int ac, char **argv, char **env)
{
	t_parse_node	*list;
	const char		*prompt;
	char			*line;

	list = NULL;
	intialize_signal();
	if (ac < 2 && !argv[1])
	{
		global_var.list = create_env(env);
		ft_list_remove_if(&global_var.list, "OLDPWD");
		while (1337)
		{
			prompt = wild_card_getter(getcwd(NULL, 0));
			line = readline(prompt);
			free((void *)prompt);
			if (line == NULL)
				break ;
			minishell(list, line);
		}
		printf("exit\n");
		return (free_env_list(), 0);
	}
}