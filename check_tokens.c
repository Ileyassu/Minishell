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
            return (PIPE);
        else if (c == '<')
            return (LEFT);
        else if (c == '>')
            return (RIGHT);
    }
    return 0;
}
//create a new file for these
t_lexer *add_new_node(t_tokens token, char *str)
{
    t_lexer *node = malloc(sizeof(t_lexer));
    if (!node)
        return (NULL);
    node->next = NULL;
    node->prev = NULL;
    node->index = 0;
    node->token = token;
    node->str = ft_strdup(str);
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

int get_word(int i, char *str, t_tools *tools)
{
    int j = 0;
    int tmp = 0;
    char *wrd;

    wrd = NULL;
    while(str[i + j] && !check_token(str[i + j]))
    {
        j = j + quotes_handler(j, str, '"');
        j = j + quotes_handler(j, str, '\'');
        if (is_space(str[i + j]) || check_token(str[i + j]))
        {
            break;
        }
        j++;
    }
    wrd = ft_substr(str, i, j);
    tmp = lexer(0, wrd, &tools->lexer);
    if (tmp == 0)
        return (0);
    free(wrd);
    return (j);
}
int add_tokens(t_tools *tools, int i)
{
    t_tokens token;
    if(check_token(tools->line[i]) == RIGHT && check_token(tools->line[i + 1]) == RIGHT)
    {
        token = RIGHT_RIGHT;
        lexer (token, ">>", &tools->lexer);
        return (2);
    }
    else if(check_token(tools->line[i]) == LEFT && check_token(tools->line[i + 1]) == LEFT)
    {
        token = LEFT_LEFT;
        lexer (token, "<<", &tools->lexer);
        return (2);
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
    return (1);
}

int create_lexer(t_tools *tools)
{
    int i = 0;
    int j = 0;
    char *str = tools->line;
    while(str[i])
    {
        i = skip_spaces(i, str);
        if(check_token(str[i]))
        {
            i += add_tokens(tools, i);
        }
        else
        {
            j = i;
            j += get_word(i, str, tools);
            i = j;
        }
    }
    t_lexer *tmp = tools->lexer;
    while(tmp)
    {
        printf("tmp = %s\n", tmp->str);
        tmp = tmp->next;
    }
    return (0);
}