#include "../minishell.h"

t_parser_tools	init_parser_tools(t_lexer *lexer, t_tools *tools)
{
	t_parser_tools	parser_tools;

	parser_tools.lexer = lexer;
	parser_tools.redirections = NULL;
	parser_tools.num_redirections = 0;
	parser_tools.tools = tools;
	return (parser_tools);
}