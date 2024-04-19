#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "minishell.h"

int	search_quotes(int *i, char *str, char c)
{
    while(str[*i] != c && check_token(str[*i]) == 0)
    {
        i++;
    }
}

int main() {
    char str[] = "test "" | < | sdfskf ";
    int i = 0;
    // while(str[i])
    // {
    //     if(check_token(str[i]))
    //         printf("%d\n", check_token(str[i]));
    //     i++;
    // }
    int j = 0;
    handle_quotes(j, str, 34);
    return 0;
}