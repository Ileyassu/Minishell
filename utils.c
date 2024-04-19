#include "minishell.h"

int skip_spaces(int i, char *str)
{
    while((str[i]) && (str[i] == ' ' || str[i] == '\t' 
        || str[i] == '\n' || str[i] == '\r'))
    {
        i++;
    }
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