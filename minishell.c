#include "minishell.h"

int	count_quotes(char *line)
{
	int	i;
	int	s;
	int	d;

	s = 0;
	d = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 34)
			i += find_matching_quote(line, i, &d, 34);
		if (line[i] == 39)
			i += find_matching_quote(line, i, &s, 39);
	}
	if ((d > 0 && d % 2 != 0) || (s > 0 && s % 2 != 0))
		return (0);
	return (1);
}
int	parse_envp(t_tools *tools)
{
	char	*path_from_envp;
	int		i;
	char	*tmp;

	path_from_envp = find_path(tools->envp);
	tools->paths = ft_split(path_from_envp, ':');
	free(path_from_envp);
	i = 0;
	while (tools->paths[i])
	{
		if (ft_strncmp(&tools->paths[i][ft_strlen(tools->paths[i]) - 1],
			"/", 1) != 0)
		{
			tmp = ft_strjoin(tools->paths[i], "/");
			free(tools->paths[i]);
			tools->paths[i] = tmp;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}


int	implement_tools(t_tools *tools)
{
	tools->simple_cmds = NULL;
	tools->lexer_list = NULL;
	tools->reset = false;
	tools->pid = NULL;
	tools->heredoc = false;
	parse_envp(tools);
	return (1);
}
// void	count_pipes(t_lexer *lexer_list, t_tools *tools)
// {
// 	t_lexer	*tmp;

// 	tmp = lexer_list;
// 	tools->pipes = 0;
// 	while (tmp)
// 	{
// 		if (tmp->token == PIPE)
// 			tools->pipes++;
// 		tmp = tmp->next;
// 	}
// }


char	*join_heredoc(char *str1, char *str2)
{
	char	*ret;
	char	*tmp;

	if (!str2)
		return (ft_strdup(str1));
	tmp = ft_strjoin(str1, " ");
	ret = ft_strjoin(tmp, str2);
	free(tmp);
	free(str2);
	return (ret);
}
int	minishell_loop(t_tools *tools)
{
	char	*tmp;

	tools->args = readline("Minishell$ ");
	tmp = ft_strtrim(tools->args, " ");
	free(tools->args);
	tools->args = tmp;
	if (!tools->args)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (tools->args[0] == '\0')
		return (reset_tools(tools));
	add_history(tools->args);
	count_quotes(tools->args);
	token_reader(tools);
	parser(tools);
	//prepare_executor(tools);
	t_simple_cmds *tmpp = tools->simple_cmds;
	int i = 0;
	while(tmpp)
	{
		i = 0;
		while(tmpp->str[i])
		{
			printf("%s == %s == \n", tmpp->str[i], tmpp->redirections->str);
			i++;
		}
		printf("next\n");
		tmpp = tmpp->next;
	}
	reset_tools(tools);
	return (1);
}

