#include "minishell.h"

char **dup_env(char **envp)
{
    int i = 0;
    int len = 0;
    char **dup;
    while(envp[len] != NULL)
        len++;
    dup = malloc(len + 1);
    while(envp[i])
    {
        dup[i] = ft_strdup(envp[i]);
        i++;
    }
    dup[i] = NULL;
    return(envp);
}

void pwd_extractor(t_tools *tools)
{
    int i = 0;
    char pwd[] = "PWD";
    int pwd_len = 3;
    int j = 0;
    while(tools->envp[i])
    {
        pwd_len = 3;
        j = 0;
        while(tools->envp[i][j] == pwd[j] && pwd_len > 0)
        {
            pwd_len--;
            j++;
        }
        if (pwd_len == 0)
            break;
        i++;
    }
    tools->PWD = ft_substr(tools->envp[i], 4, ft_strlen(tools->envp[i]) - 4);
}

void old_pwd_extractor(t_tools *tools)
{
    int i = 0;
    char pwd[] = "OLDPWD";
    int pwd_len = 6;
    int j = 0;
    while(tools->envp[i])
    {
        pwd_len = 6;
        j = 0;
        while(tools->envp[i][j] == pwd[j] && pwd_len > 0)
        {
            pwd_len--;
            j++;
        }
        if (pwd_len == 0)
        {
            tools->OLD_PWD = ft_substr(tools->envp[i], 7, ft_strlen(tools->envp[i]) - 6);
            break;
        }
        i++;
    }
}
int main(int ac, char **av, char **envp) 
{
    (void)ac;
    (void)av;
    t_tools tools;
    tools.envp = dup_env(envp);
    pwd_extractor(&tools);
    old_pwd_extractor(&tools);
    init_tools(&tools);
    minishell(&tools);
    t_lexer *tmp = tools.lexer;
    while(tmp)
    {
        printf("Index: %d Token: %d, Str: %s\n", tmp->index, tmp->token, tmp->str);
        tmp = tmp->next;
    }
}