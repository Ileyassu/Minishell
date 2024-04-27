#include "minishell.h"

int reset_tools(t_tools *tools)
{
    cmnd_clear (&tools->cmnds);
    free(tools->line);
    free(tools->PATHS);
    init_tools(tools);
    tools->reset = 1;
    minishell(tools);
    return 1;
}