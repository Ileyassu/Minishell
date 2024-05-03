#include "../minishell.h"

int	count_args(t_lexer *lexer)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer;
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
	delete_lexer_node(&parser_tools->lexer, index_1);
	delete_lexer_node(&parser_tools->lexer, index_2);
	parser_tools->num_redirections++;
	return (0);
}

void	remove_redirections(t_parser_tools *parser_tools)
{
	t_lexer	*tmp;

	tmp = parser_tools->lexer;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if ((tmp->token >= GREAT
			&& tmp->token <= LESS_LESS))
		add_new_redirection(tmp, parser_tools);
	remove_redirections(parser_tools);
}

t_simple_cmds	*initialize_cmd(t_parser_tools *parser_tools)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	remove_redirections(parser_tools);
	arg_size = count_args(parser_tools->lexer);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	tmp = parser_tools->lexer;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			delete_lexer_node(&parser_tools->lexer, tmp->i);
			tmp = parser_tools->lexer;
		}
		arg_size--;
	}
	return (new_command(str,
			parser_tools->num_redirections, parser_tools->redirections));
}

void	clear_simple_cmnd(t_simple_cmds **list)
{
	t_simple_cmds	*tmp;
	t_lexer			*redirections_tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		redirections_tmp = (*list)->redirections;
		ft_lexerclear(&redirections_tmp);
		if ((*list)->str)
			free_arr((*list)->str);
		if ((*list)->hd_file_name)
			free((*list)->hd_file_name);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}