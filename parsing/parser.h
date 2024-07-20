/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:23:00 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/20 17:56:22 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../lexer/lexer.h"
# include "../libft/libft.h"
# include <readline/readline.h>
# include "../utils/utils.h"

# define MISSMATCH (void *)-1

typedef struct s_rdr_node
{
	t_token_type			type;
	char					*file;
	struct s_rdr_node		*next;
}			t_rdr_node;
typedef struct s_parser_node
{
	t_token_type			type;
	char					**av;
	int						ac;
	t_rdr_node				*rdrlst;
	struct s_parser_node	*left;
	struct s_parser_node	*right;
}			t_parse_node;

t_parse_node	*check_pipe(t_lexer *lexer);
t_parse_node	*ft_pipe_line(t_lexer *lexer);
t_parse_node	*collect_cmd(t_lexer *lexer);
t_parse_node	*parse(char *input);
t_parse_node	*parse_input(t_lexer *lexer);
t_cmd			*cmd_components(t_lexer *lexer, t_rdr_node	**rdr);
t_parse_node	*node_create(t_cmd **av, t_rdr_node *rdrlist, t_token_type tp);
char			**av_creat(t_cmd **list);
t_rdr_node		*collect_rdr(t_lexer	*lexer, t_rdr_node	*rdr,
					t_token	token);
void			rdr_addback(t_rdr_node **lst, t_rdr_node *_new);
void			node_del(t_parse_node **node);
void			node_ptr(t_parse_node **node, t_parse_node *left,
					t_parse_node *right);
void			rdr_clear(t_rdr_node **lst);
void			print_error(t_token token);
void			handler(int signum);

#endif
