#include "../minishell.h"

int	parser(t_tools *tools)
{
	t_simple_cmds	*node;
	t_parser_tools	parser_tools;

	tools->simple_cmds = NULL;
	count_pipes(tools->lexer_list, tools);
	if(tools->lexer_list->token == PIPE)
    {
        exit(1);
    }  
	while (tools->lexer_list)
	{
		if (tools->lexer_list && tools->lexer_list->token == PIPE)
			ft_lexerdelone(&tools->lexer_list, tools->lexer_list->i);
		parser_tools = init_parser_tools(tools->lexer_list, tools);
		node = initialize_cmd(&parser_tools);
		if (!tools->simple_cmds)
			tools->simple_cmds = node;
		else
			ft_simple_cmdsadd_back(&tools->simple_cmds, node);
		tools->lexer_list = parser_tools.lexer_list;
	}
	t_simple_cmds *tmp = node;
	while(tmp)
	{
		printf("str = %s\nredirection = %s\nnum of redirections = %d\n", tmp->str[0], tmp->redirections->str, tmp->num_redirections);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}