#include "minishell.h"

int quotes_counter(char *line)
{
    int i;
    int single_quote_count;
    int double_quote_count;

	i = 0;
    single_quote_count = 0;
    double_quote_count = 0;

    while (line[i] != '\0')
    {
        if (line[i] == '\"')
            i += find_matching_quote(line, i, &double_quote_count, '\"');
        else if (line[i] == '\'')
            i += find_matching_quote(line, i, &single_quote_count, '\'');
		i++;
    }
    if ((double_quote_count > 0 && double_quote_count % 2 != 0) || 
        (single_quote_count > 0 && single_quote_count % 2 != 0))
        return 0;

    return 1;
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
	return (0);
}


int	init_tools(t_tools *tools)
{
	tools->pid = NULL;
	tools->lexer = NULL;
	tools->simple_cmds = NULL;
	tools->reset = false;
	tools->heredoc = false;
	parse_envp(tools);
	return (1);
}
// void	count_pipes(t_lexer *lexer, t_tools *tools)
// {
// 	t_lexer	*tmp;

// 	tmp = lexer;
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
int	minishell(t_tools *tools)
{
	char	*tmp;

	tools->args = readline("Minishell$ ");
	tmp = ft_strtrim(tools->args, " ");
	free(tools->args);
	tools->args = tmp;
	if (!tools->args)
	{
		ft_putendl_fd("exit", 1);
		exit(0);
	}
	if (tools->args[0] == '\0')
		return (reset_tools(tools));
	add_history(tools->args);
	quotes_counter(tools->args);
	token_reader(tools);
	parser(tools);
	//prepare_executor(tools);
	//t_simple_cmds *tmpp = tools->simple_cmds;
	//int i = 0;
	// while(tmpp->redirections)
	// {
	// 	printf("%s\n", tmpp->redirections->str);
	// 	tmpp->redirections = tmpp->redirections->next;
	// }
	// while(tmpp)
	// {
	// 	i = 0;
	// 	while(tmpp->str[i])
	// 	{
	// 		printf("%s == %s == == %d == num = %d" , tmpp->str[i], tmpp->redirections->str , 
	// 		tmpp->redirections->token,tmpp->num_redirections);
	// 		i++;
	// 	}
	// 	printf("next\n");
	// 	tmpp = tmpp->next;
	// }
	reset_tools(tools);
	return (1);
}

