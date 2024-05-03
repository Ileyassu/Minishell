#include "../minishell.h"

t_simple_cmds	*new_command(char **str,
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
// 	remove_redirections(parser_tools);
// 	arg_size = count_args(parser_tools->lexer);
// 	str = ft_calloc(arg_size + 1, sizeof(char *));
// 	tmp = parser_tools->lexer;
// 	while (arg_size > 0)
// 	{
// 		if (tmp->str)
// 		{
// 			str[i++] = ft_strdup(tmp->str);
// 			delete_lexer_node(&parser_tools->lexer, tmp->i);
// 			tmp = parser_tools->lexer;
// 		}
// 		arg_size--;
// 	}
// 	return (new_command(str,
// 			parser_tools->num_redirections, parser_tools->redirections));
// }
void	cmnd_add_back(t_simple_cmds **list, t_simple_cmds *new)
{
	t_simple_cmds	*tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = new;
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