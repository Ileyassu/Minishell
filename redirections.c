#include "minishell.h"

void add_redirection_node(t_lexer *tmp, t_parser *parser)
{
    t_lexer *node;

    node = add_new_node(tmp->token, ft_strdup(tmp->next->str));
    if (!node)
        exit(1); //add error function
    
    add_back(&parser->redirections, node);
    delete_node_by_index(&parser->lexer, node->index);
    delete_node_by_index(&parser->lexer, node->next->index);
    parser->count_redirections++;
}

void remove_redirections (t_parser *parser)
{
    t_lexer *tmp;

    tmp = parser->lexer;
    while(tmp && tmp->token == 0)
        tmp = tmp->next;
    if(tmp == PIPE)
        return;
    if (tmp == RIGHT || tmp == RIGHT_RIGHT || tmp == LEFT || tmp == LEFT_LEFT)
        add_redirection_node(tmp, parser);
    remove_redirections(parser);
}