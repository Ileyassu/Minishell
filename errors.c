#include "minishell.h"

int double_token_error(t_tokens token, t_tools *tools)
{
    
	ft_putstr_fd("syntax error near unexpected token ",
		2);
	if (token == RIGHT)
		ft_putstr_fd("'>'\n", 2);
	else if (token == RIGHT_RIGHT)
		ft_putstr_fd("'>>'\n", 2);
	else if (token == LEFT)
		ft_putstr_fd("'<'\n", 2);
	else if (token == LEFT_LEFT)
		ft_putstr_fd("'<<'\n", 2);
	else if (token == PIPE)
		ft_putstr_fd("'|'\n", 2);
	else
		ft_putstr_fd("\n", 2);
	clear_node(&tools->lexer);
	return (0);
}