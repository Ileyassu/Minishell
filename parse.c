#include "minishell.h"

t_comands *commands(char **str, t_parser *parser)
{
    t_comands *new_cmd;
    new_cmd = malloc(sizeof(t_comands));
    new_cmd->str = str;
    new_cmd->number_of_redirections = parser->count_redirections;
    new_cmd->redirections = parser->redirections;
    new_cmd->next = NULL;
    new_cmd->prev = NULL;
    return (new_cmd);
}

int	count_args(t_lexer *lexer_list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->index >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_comands *init_comands(t_parser *parser)
{
    char **str;
    int i;
    t_lexer *tmp;
    int arg_size;
    t_comands *cmd;

    cmd = NULL;
    arg_size = count_args(parser->lexer);
    str = ft_calloc(arg_size, sizeof(char *));
    remove_redirections(parser);
    tmp = parser->lexer;
    int i = 0;
    while(arg_size > 0)
    {
        if (tmp->str)
        {
        str[i] = ft_strdup(tmp->str);
        delete_node_by_index(&parser->lexer, tmp->index);
        tmp = parser->lexer;
        }
        arg_size--;
    }
    cmd = commands(str, parser);
    return (cmd);
}

void parse(t_tools *tools)
{
    t_comands *cmnd;
    t_parser parser;

    tools->cmnds = NULL;
    pipe_counter(tools);

    //add the double token here;
    while(tools->lexer)
    {
        if(tools->lexer->token == PIPE && tools->lexer)
            delete_node_by_index(&tools->lexer, tools->lexer->index);
        parser = init_parser(tools->lexer, tools);
        printf("%s\n", tools->lexer->str);
        tools->lexer = tools->lexer->next;
        cmnd = init_comands(&parser);
        if (!tools->cmnds)
            tools->cmnds = cmnd;
        else
            //cmnd add back;
    }
}