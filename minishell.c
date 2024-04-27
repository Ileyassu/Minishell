#include "minishell.h"

int minishell(t_tools *tools)
{
    tools->line = readline("Minihell$ ");
    char *tmp = ft_strtrim(tools->line, " ");
	free(tools->line);
	tools->line = ft_strdup(tmp);
    add_history(tools->line);
    free(tmp);
    create_lexer(tools);
    if (parse(tools))
        return (0);
    reset_tools(tools);
    return (1);
}