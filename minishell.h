#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libft/libft.h"

typedef struct s_simple_cmnds 
{
    char **str;
    struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
} t_simple_cmnds;


typedef struct s_tools 
{
    char **envp;
    char *PWD;
    char *OLD_PWD;
    char *PATH;
    char **PATHS;
    char *line;
    struct s_simple_cmnds	*simple_cmds;
    int	pipes;
	int	*pid;
	int	heredoc;
	int	reset;
} t_tools;

int minishell(t_tools *tools);
void init_tools(t_tools *tools);
