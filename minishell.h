#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libft/libft.h"
# include <stdbool.h>

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_parser_tools
{
	t_lexer			*lexer_list;
	t_lexer			*redirections;
	int				num_redirections;
	struct s_tools	*tools;
}	t_parser_tools;

typedef struct s_tools
{
	char					*args;
	char					**paths;
	char					**envp;
	struct s_simple_cmds	*simple_cmds;
	t_lexer					*lexer_list;
	char					*pwd;
	char					*old_pwd;
	int						pipes;
	int						*pid;
	int					heredoc;
	int					reset;
}	t_tools;

typedef struct s_simple_cmds
{
	char					**str;
	int						(*builtin)(t_tools *, struct s_simple_cmds *);
	int						num_redirections;
	char					*hd_file_name;
	t_lexer					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;

int	count_args(t_lexer *lexer_list);
int	find_matching_quote(char *line, int i, int *num_del, int del);
t_lexer	*ft_lexernew(char *str, int token);
int	add_node(char *str, t_tokens token, t_lexer **lexer_list);
void	ft_lexeradd_back(t_lexer **lst, t_lexer *new);
t_tokens	check_token(int c);
int	parser(t_tools *tools);
void old_pwd_extractor(t_tools *tools);
int	find_pwd(t_tools *tools);
char	**ft_arrdup(char **arr);
int	handle_token(char *str, int i, t_lexer **lexer_list);
int	handle_quotes(int i, char *str, char del);
int	read_words(int i, char *str, t_lexer **lexer_list);
int	token_reader(t_tools *tools);
int	count_quotes(char *line);
void	ft_lexerclear(t_lexer **lst);
t_lexer	*ft_lexerclear_one(t_lexer **lst);
int	is_whitespace(char c);
int	skip_spaces(char *str, int i);
int	parse_envp(t_tools *tools);
void	ft_lexerdel_first(t_lexer **lst);
void	ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new);
void	ft_simple_cmdsclear(t_simple_cmds **lst);
t_simple_cmds	*initialize_cmd(t_parser_tools *parser_tools);
int	reset_tools(t_tools *tools);
t_simple_cmds	*ft_simple_cmdsnew(char **str, int num_redirections, t_lexer *redirections);
void	ft_lexerdelone(t_lexer **lst, int key);
t_parser_tools	init_parser_tools(t_lexer *lexer_list, t_tools *tools);
int	add_new_redirection(t_lexer *tmp, t_parser_tools *parser_tools);
void	rm_redirections(t_parser_tools *parser_tools);
void	count_pipes(t_lexer *lexer_list, t_tools *tools);
int	implement_tools(t_tools *tools);
char	*find_path(char **envp);
void	free_arr(char **split_arr);
int	minishell_loop(t_tools *tools);

#endif