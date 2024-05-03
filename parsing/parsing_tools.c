#include "../minishell.h"

void	count_pipes(t_lexer *lexer, t_tools *tools)
{
	t_lexer	*tmp;

	tmp = lexer;
	tools->pipes = 0;
	while (tmp)
	{
		if (tmp->token == PIPE)
			tools->pipes++;
		tmp = tmp->next;
	}
}