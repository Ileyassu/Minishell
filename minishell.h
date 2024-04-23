#ifndef MINISHELL_H
#define MINISHELL_H

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

typedef struct s_comands 
{
    char **str;
    struct s_comands 	*next;
	struct s_comands 	*prev;
} t_comands ;

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
    struct s_comands	*cmnds;
    int	pipes;
	int	*pid;
    t_lexer *redirections;
	int	heredoc;
	int	reset;
} t_tools;

typedef struct s_parser 
{
    t_lexer *lexer;
    t_lexer *redirections;
    int count_redirections;
    t_tools *tools;
}   t_parser;

int add_tokens(t_tools *tools, int i);
int check_token(char c);
int minishell(t_tools *tools);
void init_tools(t_tools *tools);
int skip_spaces(int i, char *str);
int is_space(char c);
int quotes_handler(int i, char *str, char c);
int create_lexer(t_tools *tools);
int pipe_counter(t_tools *tools);
int clear_node(t_lexer **lexer);
int delete_first_node(t_lexer **lexer);
int delete_node_by_index(t_lexer **lexer, int index);
int chttaba (t_lexer **lexer);
t_parser init_parser(t_lexer *lexer, t_tools *tools);
void parse(t_tools *tools);

#endif