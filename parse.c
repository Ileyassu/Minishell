#include "minishell.h"

void parse(t_tools *tools)
{
    //t_comands *cmnd;
    t_parser parser;

    tools->cmnds = NULL;
    pipe_counter(tools);

    //add the double token here;
    while(tools->lexer)
    {
        if(tools->lexer->token == PIPE && tools->lexer)
            delete_node_by_index(&tools->lexer, tools->lexer->index);
        parser = init_parser(tools->lexer, tools);
        tools->lexer = tools->lexer->next;
    }
}