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

int add_tokens(t_tools *tools)
{
    int i = 0;
    while(tools->line[i])
    {
        if(check_token(tools->line[i]) == RIGHT && check_token(tools->line[i + 1]) == RIGHT)
        {
            printf("add node right\n"); //add node with the RIGHT_RIGHT
        }
        else if(check_token(tools->line[i]) == LEFT && check_token(tools->line[i + 1]) == LEFT)
        {
            printf("add node left\n"); //add node with the LEFT_LEFT
        }
        else if(check_token(tools->line[i]))
            printf("add node\n"); //add node
        i++;
    }
    return (1);
}