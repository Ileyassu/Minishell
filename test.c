#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "minishell.h"

int main() {
    char str[] = "test | < | sdfskf ";
    int i = 0;
    while(str[i])
    {
        if(check_token(str[i]))
            printf("%d\n", check_token(str[i]));
        i++;
    }

    return 0;
}