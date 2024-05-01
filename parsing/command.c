#include "../minishell.h"

int	count_args(t_lexer *lexer_list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	add_new_redirection(t_lexer *tmp, t_parser_tools *parser_tools)
{
	t_lexer	*node;
	int		index_1;
	int		index_2;

	node = ft_lexernew(ft_strdup(tmp->next->str), tmp->token);
	ft_lexeradd_back(&parser_tools->redirections, node);
	index_1 = tmp->i;
	index_2 = tmp->next->i;
	ft_lexerdelone(&parser_tools->lexer_list, index_1);
	ft_lexerdelone(&parser_tools->lexer_list, index_2);
	parser_tools->num_redirections++;
	return (0);
}

void	rm_redirections(t_parser_tools *parser_tools)
{
	t_lexer	*tmp;

	tmp = parser_tools->lexer_list;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if ((tmp->token >= GREAT
			&& tmp->token <= LESS_LESS))
		add_new_redirection(tmp, parser_tools);
	rm_redirections(parser_tools);
}

t_simple_cmds	*initialize_cmd(t_parser_tools *parser_tools)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	rm_redirections(parser_tools);
	arg_size = count_args(parser_tools->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	tmp = parser_tools->lexer_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_lexerdelone(&parser_tools->lexer_list, tmp->i);
			tmp = parser_tools->lexer_list;
		}
		arg_size--;
	}
	return (ft_simple_cmdsnew(str,
			parser_tools->num_redirections, parser_tools->redirections));
}

void	ft_simple_cmdsclear(t_simple_cmds **lst)
{
	t_simple_cmds	*tmp;
	t_lexer			*redirections_tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		redirections_tmp = (*lst)->redirections;
		ft_lexerclear(&redirections_tmp);
		if ((*lst)->str)
			free_arr((*lst)->str);
		if ((*lst)->hd_file_name)
			free((*lst)->hd_file_name);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}