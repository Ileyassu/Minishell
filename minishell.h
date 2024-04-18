#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libft/libft.h"

typedef enum s_tokens
{
    PIPE = 1,
    RIGHT,
    LEFT,
    RIGHT_RIGHT,
    LEFT_LEFT,
} t_tokens;

typedef struct s_simple_cmnds 
{
    char **str;
    struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
} t_simple_cmnds;

typedef struct s_lexer
{
    int index;
    char *str;
    t_tokens token;
    struct s_lexer *next;
    struct s_lexer *prev;
}   t_lexer;

typedef struct s_tools 
{
    t_lexer *lexer;
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

int add_tokens(t_tools *tools);
int check_token(char c);
int minishell(t_tools *tools);
void init_tools(t_tools *tools);
