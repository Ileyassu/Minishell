#include "minishell.h"

int minishell(t_tools *tools)
{
    tools->line = readline("\033[1;50mminihell\033[34m$ \033[1m");
    char *tmp = ft_strtrim(tools->line, " ");
	free(tools->line);
	tools->line = ft_strdup(tmp);
    add_history(tools->line);
    free(tmp);

    return 1;
}