#include "minishell.h"

int skip_spaces(int i, char *str)
{
    while((str[i]) && (str[i] == ' ' || str[i] == '\t' 
        || str[i] == '\n' || str[i] == '\r'))
        i++;
    return (i);
}

int is_space(char c)
{
    if(c == ' ' || c == '\t' 
        || c == '\n' || c == '\r')
            return (1);
    return (0);
}

int quotes_handler(int i, char *str, char c)
{
    if (str[i] == c)
    {
        i++;
        while(str[i] != c && str[i])
            i++;
        i++;
        return (i);
    }
    return 0;
}

int pipe_counter(t_tools *tools)
{
    int counter;

    counter = 0;
    t_lexer *tmp = tools->lexer;
    while(tmp)
    {
        if(tmp->token == PIPE)
            counter++;
        tmp = tmp->next;
    }
    return (counter);
}

int clear_node(t_lexer **lexer)
{
    if((*lexer)->str)
        free((*lexer)->str);
    (*lexer)->str = NULL;
    free((*lexer));
    *lexer = NULL;
    return (1);
}

int delete_first_node(t_lexer **lexer)
{
    t_lexer *node;
    node = (*lexer);
    (*lexer) = (*lexer)->next;
    clear_node(lexer);
    (*lexer)->prev = NULL;
    return (1);
}

int delete_node_by_index(t_lexer **lexer, int index)
{
    t_lexer *node;
    t_lexer *prev;

    prev = NULL;
    if ((*lexer)->index == index)
    {
        delete_first_node(lexer);
        return (1);
    }
    node = (*lexer)->next;
    while (node && node->index != index)
        node = node->next;
    if(node && node->index == index)
    {
        prev = node->prev;
        if (node->next)
        {
            prev->next = node->next;
            node->next->prev = prev;
        }
        clear_node(&node);
    }
    else if (node->index == index && node->next == NULL)
    {
        prev->next = NULL;
        clear_node(&node);
    }
    return (1);
}

int chttaba (t_lexer **lexer)
{
    t_lexer *tmp = (*lexer);
    while(tmp)
    {
       tmp = tmp->next;
       free((*lexer));
       (*lexer)= tmp;
    }
    (*lexer) = NULL;
    return (1);
}