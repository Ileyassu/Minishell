#include "minishell.h"

void get_path(t_tools *tools)
{
    int i = 0;
    int size_of_envp = 0;
    char path[] = "PATH";
    int PATH_len = 4;
    while(tools->envp[size_of_envp])
        size_of_envp++;
    int j = 0;
    while(tools->envp[i])
    {
        PATH_len = 3;
        j = 0;
        while(tools->envp[i][j] == path[j] && PATH_len > 0)
        {
            PATH_len--;
            j++;
        }
        if (PATH_len == 0)
            break;
        i++;
    }
    tools->PATH = ft_substr(tools->envp[i], 5, ft_strlen(tools->envp[i]) - 5);
}

int	parse_envp(t_tools *tools)
{
    char *tmp;
    int i = 0;
    tools->PATHS = ft_split(tools->PATH, ':');
    while(tools->PATHS[i])
    {
        if(tools->PATHS[i][ft_strlen(tools->PATHS[i]) - 1] != '/')
        {
            tmp = ft_strjoin(tools->PATHS[i], "/");
            free(tools->PATHS[i]);
            tools->PATHS[i] = ft_strdup(tmp);
        }
        i++;
    }
    return (1);
}

void init_tools(t_tools *tools)
{
    tools->lexer = NULL;
    tools->cmnds = NULL;
    tools->pipes = 0;
    tools->pid = NULL;
    tools->heredoc = 0;
    tools->reset = 0;
    get_path(tools);
    parse_envp(tools);
}

t_parser init_parser(t_lexer *lexer, t_tools *tools)
{
    t_parser parser;
    parser.lexer = lexer;
    parser.count_redirections = 0;
    parser.redirections = NULL;
    parser.tools = tools;
    return (parser);
}