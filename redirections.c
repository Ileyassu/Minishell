#include "minishell.h"

void add_redirection_node(t_lexer *tmp, t_parser *parser)
{

    t_lexer *node;
    node = add_new_node(tmp->token, ft_strdup(tmp->next->str));
    if (!node)
        exit(1);
    add_back(&parser->redirections, node);
    delete_node_by_index(&parser->lexer, node->index);
    printf("adding redirection\n");
    t_parser *x = parser;
    while(x->redirections)
    {
        printf("tmp redirection = %s\n", x->redirections->str);
        x->redirections =  x->redirections->next;
    }
    delete_node_by_index(&parser->lexer, node->next->index);
    parser->count_redirections++;
}

void remove_redirections (t_parser *parser)
{
    t_lexer *tmp;

    tmp = parser->lexer;
    while(tmp && tmp->token == 0)
    {
        tmp = tmp->next;
    }

    if(!tmp || tmp->token == PIPE)
    {
        return;
    }
    if (tmp->token == RIGHT || tmp->token == RIGHT_RIGHT || tmp->token == LEFT || tmp->token == LEFT_LEFT)
        add_redirection_node(tmp, parser);
    remove_redirections(parser);
}