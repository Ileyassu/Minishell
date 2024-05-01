#include "../minishell.h"

t_simple_cmds	*ft_simple_cmdsnew(char **str,
	int num_redirections, t_lexer *redirections)
{
	t_simple_cmds	*new_element;

	new_element = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->hd_file_name = NULL;
	new_element->num_redirections = num_redirections;
	new_element->redirections = redirections;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}
// t_simple_cmds	*initialize_cmd(t_parser_tools *parser_tools)
// {
// 	char	**str;
// 	int		i;
// 	int		arg_size;
// 	t_lexer	*tmp;

// 	i = 0;
// 	rm_redirections(parser_tools);
// 	arg_size = count_args(parser_tools->lexer_list);
// 	str = ft_calloc(arg_size + 1, sizeof(char *));
// 	tmp = parser_tools->lexer_list;
// 	while (arg_size > 0)
// 	{
// 		if (tmp->str)
// 		{
// 			str[i++] = ft_strdup(tmp->str);
// 			ft_lexerdelone(&parser_tools->lexer_list, tmp->i);
// 			tmp = parser_tools->lexer_list;
// 		}
// 		arg_size--;
// 	}
// 	return (ft_simple_cmdsnew(str,
// 			parser_tools->num_redirections, parser_tools->redirections));
// }
void	ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new)
{
	t_simple_cmds	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}




t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map->prev != NULL)
	{
		map = map->prev;
		i++;
	}
	return (map);
}