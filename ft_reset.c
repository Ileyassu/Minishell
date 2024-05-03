#include "minishell.h"

int	reset_tools(t_tools *tools)
{
	clear_simple_cmnd(&tools->simple_cmds);
	free(tools->args);
	if (tools->pid)
		free(tools->pid);
	free_arr(tools->paths);
	init_tools(tools);
	tools->reset = true;
	minishell(tools);
	return (1);
}