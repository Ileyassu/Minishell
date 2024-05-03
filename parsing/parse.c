#include "../minishell.h"

int	parser(t_tools *tools)
{
	t_simple_cmds	*node;
	t_parser_tools	parser_tools;

	tools->simple_cmds = NULL;
	count_pipes(tools->lexer, tools);
	if(tools->lexer->token == PIPE)
    {
        exit(1);
    }  
	while (tools->lexer)
	{
		if (tools->lexer && tools->lexer->token == PIPE)
			delete_lexer_node(&tools->lexer, tools->lexer->i);
		parser_tools = init_parser_tools(tools->lexer, tools);
		node = initialize_cmd(&parser_tools);
		if (!tools->simple_cmds)
			tools->simple_cmds = node;
		else
			cmnd_add_back(&tools->simple_cmds, node);
		tools->lexer = parser_tools.lexer;
	}
	return (0);
}