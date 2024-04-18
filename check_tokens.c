#include "minishell.h"

int token_char(char c)
{
    if(c == '|' || c == '<' || c == '>')
    {
        return(1);
    }
    return (0);
}

int check_token(char c)
{
    if (token_char(c))
    {
        if(c == '|')
            return (PIPE);//should add node after this
        else if (c == '<')
            return (LEFT); //should add node after this
        else if (c == '>')
            return (RIGHT); //should add node after this
    }
    return 0;
}

t_lexer *add_new_node(t_tokens token, char *str)
{
    t_lexer *node = malloc(sizeof(t_lexer));
    if (!node)
        return (NULL);
    node->next = NULL;
    node->prev = NULL;
    node->index = 0;
    node->token = token;
    node->str = str;
    return (node);
}

void add_back(t_lexer **head, t_lexer *new)
{
    t_lexer *tmp;
    t_lexer *prev;

    tmp = NULL;
    prev = NULL;
    if(*head == NULL)
    {
        new->index = 0;
        *head = new;
        return;
    }
    tmp = *head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
    new->index = tmp->index + 1;
}
int lexer (t_tokens token, char *str, t_lexer **head)
{
    t_lexer *lexer;
    lexer = add_new_node(token, str);
    if (lexer == NULL)
        return (0);
    add_back(head, lexer);
    return (1);
}
int add_tokens(t_tools *tools)
{
    int i = 0;
    t_tokens token;
    while(tools->line[i])
    {
        if(check_token(tools->line[i]) == RIGHT && check_token(tools->line[i + 1]) == RIGHT)
        {
            token = RIGHT_RIGHT;
            lexer (token, ">>", &tools->lexer); //should allocate for lexer->str;
        }
        else if(check_token(tools->line[i]) == LEFT && check_token(tools->line[i + 1]) == LEFT)
        {
            token = LEFT_LEFT;
            lexer (token, "<<", &tools->lexer);
        }
        else if(check_token(tools->line[i]))
        {
            token = check_token(tools->line[i]);
            if (token == PIPE)
                lexer (token, "|", &tools->lexer);
            else if (token == RIGHT)
                lexer (token, ">", &tools->lexer);
            else if (token == LEFT)
                lexer (token, "<", &tools->lexer);
        }
        i++;
    }

    return (1);
}